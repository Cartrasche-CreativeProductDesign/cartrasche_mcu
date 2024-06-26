#ifndef _MOTOR_CONTROL_H
#define _MOTOR_CONTROL_H

#include "config.h"
#include "_led_control.h"

int current_fb_speed = 125;
int current_lr_speed = 125;

void initialize_bldc()
{
  pinMode(DIR1, OUTPUT);
  pinMode(START_STOP1, OUTPUT);
  pinMode(DIR2, OUTPUT);
  pinMode(START_STOP2, OUTPUT);
    
  pinMode(SPEED_IN1, OUTPUT);
  pinMode(SPEED_IN2, OUTPUT);

  analogWrite(SPEED_IN1, 125); //stop
  analogWrite(SPEED_IN2, 125); //stop
  digitalWrite(DIR1, LOW);
  digitalWrite(DIR2, HIGH);
  digitalWrite(START_STOP1, HIGH); //stop
  digitalWrite(START_STOP2, HIGH); //stop
}

// 0 ~ 102 : fwd => BACKWARD
// 100 ~ 152 : stop 
// 153 ~250 : bwd => FORWARD
void fb_control(int dir, int speed)
{
  if(speed>250){
    speed = 155;
  }
  current_fb_speed = speed;

  // 0 : fwd, 1 : bwd
  if(dir == 1){
    digitalWrite(DIR1, LOW);
    digitalWrite(DIR2, HIGH);
    show_red(100);
    
  }
  else if(dir == 0){
    digitalWrite(DIR1, HIGH);
    digitalWrite(DIR2, LOW);
    show_green(80);
  }
  digitalWrite(START_STOP1, LOW);
  digitalWrite(START_STOP2, LOW);
  
  // Slowly increase motor speed
  analogWrite(SPEED_IN1, speed);
}

// 0 ~ 102 : left
// 103 ~ 152 : stop
// 153 ~ 250 : right 
void lr_control(int speed)
{
  // Turn motor on
  if(speed>250){
    speed = 155;
  }
  current_lr_speed = speed;

  digitalWrite(START_STOP1, LOW);
  digitalWrite(START_STOP2, LOW);
  show_green(70);
  if(speed>140){ //////////////////////////////////////////
    //indicLEFT(); //////////////////////////////////////////
  } //////////////////////////////////////////
  else if(speed<120){ //////////////////////////////////////////
    //indicRIGHT(); //////////////////////////////////////////
  } //////////////////////////////////////////
  analogWrite(SPEED_IN2, speed);
}


void turn_off_motor()
{ 
  show_pink();
  //turn_off_strip1();
  //turn_off_strip2();
  while(((current_fb_speed < 100) || (current_fb_speed > 150)) || ((current_lr_speed < 103) || (current_lr_speed > 152))){ // if the motor is moving in any way,
    if(current_fb_speed < 100){ // if moving forward 
      current_fb_speed += 5;
      analogWrite(SPEED_IN1, current_fb_speed);
      }
    else if(current_fb_speed > 150){ // if moving backward 
      current_fb_speed -= 5;
      analogWrite(SPEED_IN1, current_fb_speed);
      }
      
    if(current_lr_speed < 103){ // if moving left
      current_lr_speed += 5;
      analogWrite(SPEED_IN2, current_lr_speed);
      }
    else if(current_lr_speed > 152){ // if moving right
      current_lr_speed -= 5;
      analogWrite(SPEED_IN2, current_lr_speed);
      }
    delay(100);
  }
  current_fb_speed = 125;
  current_lr_speed = 125;
  analogWrite(SPEED_IN1, current_fb_speed);
  analogWrite(SPEED_IN2, current_lr_speed);
  
  digitalWrite(START_STOP1, HIGH);
  digitalWrite(START_STOP2, HIGH);
}

int calculateSpeed(float linVel){
  float calc = (((linVel*GRATIO_PARAM)/TWOPIRAD)-50)/60+LIN_VEL_BASE; // 29
  int AnalogOut = int(trunc(calc));
  return AnalogOut;
}

int calculateAngle(float angVel){
  if(angVel<0){
    float calc = ANG_NEG_BASE - (((GRATIO_PARAM*abs(angVel)*WHEELBASE)/(2*TWOPIRAD)) - 50)/15;
    int AnalogOut = int(trunc(calc));
    return AnalogOut;
  }
  else{
    float calc = (((GRATIO_PARAM*angVel*WHEELBASE)/(2*TWOPIRAD)) - 50)/15 + ANG_POS_BASE;
    int AnalogOut = int(trunc(calc));
    return AnalogOut;
  }
}

#endif
