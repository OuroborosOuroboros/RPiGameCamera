# RPi Game Camera  
**Author:** Davey Getchell  
**Course:** CS7680 – Programming Embedded Systems  
**Assignment:** Final Project  
**Due Date:** 12/13/2024  

## Overview  
This project is a proof-of-concept for a motion-activated, solar-powered game camera built using a Raspberry Pi 4, PIR motion sensor, and infrared LEDs. The system is designed to capture images/videos in remote locations, with a focus on sustainable energy use and low-power operation.  

The prototype demonstrates the feasibility of building a custom wildlife camera using cost-effective, off-the-shelf components, providing a foundation for hobbyists and researchers interested in DIY motion-based camera systems.  

**Full Technical Report** available in [`Raspberry_Pi_Game_Camera_Report.pdf`](docs/reports/Raspberry_Pi_Game_Camera_Report.pdf)  

---

## Features  
- Motion-triggered image & video capture using a PIR sensor  
- Solar-powered operation for extended outdoor use  
- Lightweight software design in C, following the Model-View-Controller (MVC) pattern  
- Local storage of images/videos  

---

## Project Limitations & Future Work  
While the prototype met its primary objectives, several areas for improvement were identified:  

- **Enhanced IR LED array** to improve nighttime visibility  
- **Light level measurements** for optimized brightness control  
- **Power consumption testing** to evaluate battery and solar efficiency  
- **Wireless media transfer** using Bluetooth or Wi-Fi for easier file retrieval  
- **Weatherproof casing** to protect against outdoor conditions  

**See full discussion of limitations and future work** in [`Raspberry_Pi_Game_Camera_Report.pdf`](docs/reports/Raspberry_Pi_Game_Camera_Report.pdf)

---

## Hardware Requirements  
- **Raspberry Pi 4** (or similar device)  
- **Raspberry Pi NoIR Camera Module** (or similar camera module)  
- **PIR Motion Sensor**  
- **Infrared LEDs** (for night vision)  
- **Solar-compatible battery**  
- **10W 12V Solar Panel**  
- **Voltage regulator**  
- **Supporting components:** Resistors, transistors, jumper wires, breadboard  

**Diagrams** available in [`/diagrams`](docs/diagrams/)  
**Component Datasheets** available in [`/datasheets`](docs/references/component_datasheets/)  

---

## Software & Dependencies  
- **C Programming Language** (compiled with `gcc`)  
- **pigpio** (for GPIO control)  
- **libcamera** (for camera interaction)  
- **Raspberry Pi OS Lite** (for lightweight operation)  
- **Makefile** (for compiling and managing builds)  

---

## Usage  
1. **Compile**: Use `make` to compile the project.  
2. **Run**: Execute `./game_camera` to start the program.  
3. **Clean up**: Use `make clean` to remove compiled files.  

---

## Contact  
For questions or feedback, please contact me at **[dgetch48@gmail.com](mailto:dgetch48@gmail.com)**.  

---

## License  
This project is open-source and available under the **MIT License**. See the [LICENSE](LICENSE) file for details.  
