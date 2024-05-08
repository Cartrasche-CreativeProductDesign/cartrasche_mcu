# Cartrasche

- 연세대학교 기계공학과 창의제품설계 프로젝트
- Yonsei University M.E Creative Design Project

![cartrasche_logo](https://github.com/Cartrasche-CreativeProductDesign/cartrasche_dev/assets/68832065/74af2a03-79aa-4e0f-a699-e39b201d271c)

> Participants
> * 연세대학교 기계공학과 18학번 **[김원준](https://github.com/wkdalswns0427/)**
> * 연세대학교 기계공학과 18학번 **[박현진](https://github.com/wkdalswns0427/)**
> * 연세대학교 기계공학과 19학번 **[장민준](https://github.com/wkdalswns0427/)**
> * 연세대학교 기계공학과 19.5학번 **[조믿음](https://github.com/wkdalswns0427/)**
> * 연세대학교 기계공학과 21학번 **[김현준](https://github.com/wkdalswns0427/)**

## Specification

### Computing Environment
**Jetson Nano 4Gb**
- Ubuntu 20.04
- ROS1 --version Noetic
- Python --version 3.10.4

**Arduino MEGA(ATmega2560)**
- Arduino 1.8.13

### Platform Robot
- 24V 3000rpm BLDC Motor
- MD200T BLDC Motor Driver
- BNO-055 IMU Sensor
- YDLiDAR G4
- Logitech Webcam

### Rotating Tray System
- 12V NEMA17 Stepper Motor
- 12V Stepper driven Linear Ball Screw
- TB6560 Stepper Driver
- PCA9685 12-channel PWM Driver
- NEOPIXEL 12 LED_RING

## ROSSERIAL-ATMEGA
**JETSON -> ARDUINO MEGA**
- Subscribe : /cmd_vel  [geometry_msgs::Twist] -> linear.x, angular.z
- Subscribe : /switch_tray [std_msgs::Int32] -> 1 or 2
- Publish   : /rosduino [std_msgs::String] -> callback msg for received topic
- Publish   : /heartbeat [std_msgs::String] -> heartbeat

## Circuit Diagram