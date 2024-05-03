# cartrasche_atmega2560
Cartrasche motors and peripherals driver with rosserial enabled

![cartrasche_logo](https://github.com/Cartrasche-CreativeProductDesign/cartrasche_dev/assets/68832065/74af2a03-79aa-4e0f-a699-e39b201d271c)

## Hardware Controller Components
- ARDUINO  | Arduino MEGA(ATmega2560)
- MDROBOT  | MD200T BLDC Driver
- TOSHIBA  | TB6560 Stepper Driver
- ADAFRUIT | PCA9685 12-channel PWM Driver
- ADAFRUIT | NEOPIXEL 12 LED_RING

## ROSSERIAL-ATMEGA
**ARDUINO MEGA**
- Subscribe : /cmd_vel  [geometry_msgs::Twist] -> linear.x, angular.z
- Subscribe : /switch_tray [std_msgs::Int32] -> 1 or 2
- Publish   : /rosduino [std_msgs::String] -> callback msg for received topic
- Publish   : /heartbeat [std_msgs::String] -> heartbeat
