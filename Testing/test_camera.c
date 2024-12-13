/* Davey Getchell
 * 12/5/25
 * CS7680 - Final Project
 * test_camera.c - this file is testing the abilities of the RaspberryPi Camera module using
 *                  the V4L2 API
*/

// Imports
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <linux/videodev2.h>

#define WIDTH 1920
#define HEIGHT 1080

int main(){
    const char *dev_name = "/dev/video0";
    int fd = open(dev_name, O_RDWR);
    if (fd == -1) {
        perror("Opening video device");
        return -1;
    }

    // Query device capabilities
    struct v4l2_capability cap;
    if(ioctl(fd, VIDIOC_QUERYCAP, &cap) == -1){
        perror("Querying capabilities");
        close(fd);
        return -1;
    }

    // Set image format
    struct v4l2_format fmt;
    memset(&fmt, 0, sizeof(fmt));
    fmt.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    fmt.fmt.pix.width = WIDTH;
    fmt.fmt.pix.height = HEIGHT;
    fmt.fmt.pix.pixelformat = V4L2_PIX_FMT_YUYV; 
    fmt.fmt.pix.field = V4L2_FIELD_NONE;

    if(ioctl(fd, VIDIOC_S_FMT, &fmt) == -1) {
        perror("Setting pixel format");
        close(fd);
        return -1;
    }

    // Request buffers
    struct v4l2_requestbuffers req;
    memset(&req, 0, sizeof(req));
    req.count = 1;
    req.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    req.memory = V4L2_MEMORY_MMAP;

    if(ioctl(fd, VIDIOC_REQBUFS, &req) == -1) {
        perror("Requesting buffer");
        close(fd);
        return -1;
    }

    // Map the buffer
    struct v4l2_buffer buf;
    memset(&buf, 0, sizeof(buf));
    buf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    buf.memory = V4L2_MEMORY_MMAP;
    buf.index = 0;

    if(ioctl(fd, VIDIOC_QUERYBUF, &buf) == -1){
        perror("Querying buffer");
        close(fd);
        return -1;
    }

    void *buffer_start = mmap(NULL, buf.length, PROT_READ | PROT_WRITE, MAP_SHARED, fd, buf.m.offset);
    if(buffer_start == MAP_FAILED){
        perror("Mapping buffer");
        close(fd);
        return -1;
    }

    // Queue the buffer
    if(ioctl(fd, VIDIOC_QBUF, &buf) == -1){
        perror("Queueing buffer");
        close(fd);
        return -1;
    }

    // Start streaming
    int type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    if(ioctl(fd, VIDIOC_STREAMON, &type) == -1){
        perror("Start capture");
        close(fd);
        return -1;
    }

    // Capture frame by dequeuing buffer
    if(ioctl(fd, VIDIOC_DQBUF, &buf) == -1){
        perror("Dequeueing buffer");
        close(fd);
        return -1;
    }
    
    // Write the buffer to an file
    FILE *file = fopen("image.jpg", "wb");
    if (file) {
        fwrite(buffer_start, buf.bytesused, 1, file);
        fclose(file);
        printf("Image saved as 'image.jpg'\n");
    } else {
        perror("Saving image");
    }

    // Stop streaming
    if(ioctl(fd, VIDIOC_STREAMOFF, &type) == -1){
        perror("Stop capture");
    }

    // Cleanup
    munmap(buffer_start, buf.length);
    close(fd);

    return 0;
}