#ifndef CONFIG_H
#define CONFIG_H

///////////////// INCLUDE CONFIG /////////////////
#include <Arduino.h>
#include <ros.h>
#include <std_msgs/Int32.h>
#include <std_msgs/Int16.h>
#include <std_msgs/String.h>
#include <std_msgs/Empty.h>
#include <geometry_msgs/Twist.h>

#include <SoftwareSerial.h>
#include <Adafruit_NeoPixel.h>
#include <Wire.h>
// #include <Adafruit_PWMServoDriver.h>
////////////////////////////////////////////////

///////////////// ROBOT CONFIG /////////////////
#define WHEEL_RAD     0.056 // m
#define PI            3.1415926535897932384626433832795
#define TWOPIRAD      0.351858377
#define WHEELBASE     0.3228
#define VEL_MAX       30 // m/s
#define ANG_MAX       30 // deg
#define EPSILON       0.000001
#define LIN_VEL_BASE  140
#define ANG_POS_BASE  149
#define ANG_NEG_BASE  112
#define GRATIO_PARAM  1200
////////////////////////////////////////////////

////////////////// BLDC MOTOR //////////////////
// 50 ~ 3000 RPM 
// 0.03V per 1 analogOut 
// 29RPM per 1 analog Output
// Vol  : analog  RPM
// 3.0V : 153 -> 50 RPM  
// 4.9V : 250 -> 2855 RPM
// 5.0V : 255 -> 3000 RPM 
// linvel || Analog = (((linVel*300)/(TWOPIRAD)-50)/29)+153
#define    SPEED_IN1   5    // ORANGE  6
#define    SPEED_IN2   6    // ORANGE  8
#define         DIR1  10    //  BROWN  2
#define  START_STOP1  11    //   PINK  4
#define         DIR2  12    //  BROWN 16
#define  START_STOP2  13    //   PINK 17
////////////////////////////////////////////////

////////////////// SCREW STEP //////////////////
#define STEP_DIR   22  // CW+  2
#define STEP_STEP  24 // CLK+ 5
#define STEP_EN    26   // EN+  8
///////////////////////////////////////////////

//////////////// ROTATION STEP ////////////////
#define STEP_DIR_TOP     28  // CW+  2
#define STEP_STEP_TOP    30 // CLK+ 5
#define STEP_EN_TOP      32   // EN+  8

#define STEP_DIR_BOT     34  // CW+  2
#define STEP_STEP_BOT    36 // CLK+ 5
#define STEP_EN_BOT      38   // EN+  8

#define MID2TOP          A0
#define BOT2TOP          A1
#define upcount           8
const long int rotatecount=45600;//92000
#define STEPS_PER_REV  1000 // 1/8 step mode shall be  // 1000 , 1 uc -> 5mm
#define STEPS_PER_REV2 1000

// button state
int M2T_bs = 0;
int B2T_bs = 0;
/////////////////////////////////////////////

////////////// ARDUINO CONFIG ///////////////
#define RELAY        23
#define LED_BUILTIN  13

#define LED_PIN      53
#define NUMPIXELS    12 
#define PIXEL_DELAY  100

#define STRIP_PIN1   49 // LEFT
#define STRIP_PIN2   51 // RIGHT
#define NUM_STRIP    18
/////////////////////////////////////////////

/////////////// SERVO CONFIG /////////////////
#define PCA9685_ADRRESS 0x40
#define SERVO_FREQUENCY 60
#define SERVOMIN  125
#define SERVOMAX  625 
// SDA to A4, SCL to A5
/////////////////////////////////////////////

#endif
