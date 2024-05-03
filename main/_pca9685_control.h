#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include "config.h"
int servoTflag = 0;
int servoBflag = 0;
Adafruit_PWMServoDriver PCA9685=Adafruit_PWMServoDriver(PCA9685_ADRRESS);

void initializeServo(){
    PCA9685.begin();
    PCA9685.setPWMFreq(SERVO_FREQUENCY);
    PCA9685.setPWM(0,0,angleToPulse(0));
    PCA9685.setPWM(1,0,angleToPulse(0));
}

int angleToPulse(int ang){  
    int pulse = map(ang,0, 180, SERVOMIN,SERVOMAX);  // map angle of 0 to 180 to Servo min and Servo max 
    Serial.print("Angle: ");Serial.print(ang);
    Serial.print(" pulse: ");Serial.println(pulse);
    return pulse;
}

void rotateTopServo(){
    if(servoTflag == 0){
        PCA9685.setPWM(0,0,angleToPulse(180));
        int servoTflag = 1;
    }
    else if(servoTflag == 1){
        PCA9685.setPWM(0,0,angleToPulse(0));
        int servoTflag = 0;
    }
}

void rotateBotServo(){
    if(servoBflag == 0){
        PCA9685.setPWM(1,0,angleToPulse(180));
        int servoBflag = 1;
    }
    else if(servoBflag == 1){
        PCA9685.setPWM(1,0,angleToPulse(0));
        int servoBflag = 0;
    }    
}