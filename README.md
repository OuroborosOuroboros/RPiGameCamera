# RPi Game Camera<br>
**Author:** Davey Getchell<br>
**Course:** CS7680 Programming Embedded Systems<br>
**Assignment:** Final Project<br>
**Due Date:** 12/13/2024

## Overview
This project is a proof-of-concept for a a motion-activated, solar-powered game camera, built using a Raspberry Pi 4, PIR motion sensor and infrared LEDs. The system is designed to to capture images/videos in remote locations, with a focus on sustainable energy use and low-power operation. 

The prototype demonstrates the feasiblity of building a custom wildlife camear using cost-effective, off-the-shelf components, providing a foundation for hobbyists and researchers interested in DIY motion-based camera systems. 

Full Technical Report available in [`/reports`](reports/) 

# Features
- Motion-triggered image & video capture using a PIR sensor
- Solar Powered operation for extended outdoor use
- Lightweight software design in C following the Model-View-Controller (MVC) pattern
- Local storage of images/videos

## **Project Limitations & Future Work**
- See full discussion of limitations and future work in [`/reports`](reports/)

## Hardware Requirements
- **Rasperry Pi 4** (or similar device)
- **Raspbery Pi NoIR Camera Module** (or similar camera module)
- **PIR Motion Sensor**
- **Infrared LEDs** (for night vision)
- **Solar compatible battery**
- **10W 12V Solar Panel**
- **Voltage regulator**
- **Supporting components**: Resistors, transistors, jumper wires, breadboard

## **Software & Dependencies**
- **C Programming Language** (compiled with gcc)
- **pigpio** (for GPIO control)
- **libcamera** (for camera interaction)
- **Raspberry Pi OS Lite** (for lightweight operation)
- **Makefile** (for compiling and managing builds)

**Diagrams** available in [`/diagrams`](diagrams/) <br>
**Component Datasheets** available in [`/datasheets`](datasheets/)

--- 

## Usage
1. **Compile**: Use `make` to compile the assignments.
2. **Clean up**: Use `make clean` to remove compiled files.

## Contact 
For questions or feedback, please contact me at [dgetch48@gmail.com](mailto:dgetch48@gmail.com).

## Future Improvements
- Enhanced IR LED array
- Light level measurements
- Power consumption testing
- Wireless media transfer
- Weatherproof casing

## License
This project is open-source and available under the **MIT License** see the [LICENSE](LICSENSE) file for details. 

