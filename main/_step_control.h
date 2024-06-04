#ifndef _STEP_CONTROL_H
#define _STEP_CONTROL_H

#include "config.h"
#include "_led_control.h"

int step = 0;
int stepDelayShort = 350;
int stepDelay = 50;
int a = 0;

void initialize_steppers(){
  pinMode(STEP_DIR, OUTPUT);
  pinMode(STEP_STEP, OUTPUT);
  pinMode(STEP_EN, OUTPUT);
  digitalWrite(STEP_EN, LOW);
  pinMode(STEP_DIR_TOP, OUTPUT);
  pinMode(STEP_STEP_TOP, OUTPUT);
  pinMode(STEP_EN_TOP, OUTPUT);
  digitalWrite(STEP_EN_TOP, LOW);
  pinMode(STEP_DIR_BOT, OUTPUT);
  pinMode(STEP_STEP_BOT, OUTPUT);
  pinMode(STEP_EN_BOT, OUTPUT);
  digitalWrite(STEP_EN_BOT, LOW);
}

// push up the link
void spinUp(){
    digitalWrite(STEP_DIR, LOW);
    for(int i  = 0; i < upcount*STEPS_PER_REV; i++){
      digitalWrite(STEP_STEP, HIGH);
      delayMicroseconds(stepDelayShort);
      digitalWrite(STEP_STEP, LOW);
      delayMicroseconds(stepDelayShort);
    }
}

// let down the link
void spinDown(){
  digitalWrite(STEP_DIR, HIGH);
  for(int i  = 0; i < 5*STEPS_PER_REV; i++){
    digitalWrite(STEP_STEP, HIGH);
    delayMicroseconds(stepDelayShort);
    digitalWrite(STEP_STEP, LOW);
    delayMicroseconds(stepDelayShort);
  }
}

//half step
void spinDownLit(){
  digitalWrite(STEP_DIR, HIGH);
  for(int i  = 0; i < 3*STEPS_PER_REV; i++){
    digitalWrite(STEP_STEP, HIGH);
    delayMicroseconds(stepDelayShort);
    digitalWrite(STEP_STEP, LOW);
    delayMicroseconds(stepDelayShort);
  }
}

// rotate top stepper once
void rotateTop(){
  digitalWrite(STEP_DIR_TOP, HIGH);
  for(long int i  = 0; i < rotatecount; i++){ //rotatecount*STEPS_PER_REV2
    digitalWrite(STEP_STEP_TOP, HIGH);
    delayMicroseconds(stepDelay);
    digitalWrite(STEP_STEP_TOP, LOW);
    delayMicroseconds(stepDelay);
  }
}

void rotateTopManual(){
  digitalWrite(STEP_DIR_TOP, LOW);
  for(long int i  = 0; i < 500; i++){ //rotatecount*STEPS_PER_REV2
    digitalWrite(STEP_STEP_TOP, HIGH);
    delayMicroseconds(stepDelay);
    digitalWrite(STEP_STEP_TOP, LOW);
    delayMicroseconds(stepDelay);
  }
}

// rotate bottom stepper once
void rotateBotManual(){
  digitalWrite(STEP_DIR_BOT, LOW);
  for(long int i  = 0; i < 500; i++){
    digitalWrite(STEP_STEP_BOT, HIGH);
    delayMicroseconds(stepDelay);
    digitalWrite(STEP_STEP_BOT, LOW);
    delayMicroseconds(stepDelay);
  }
}

// rotate bottom stepper once
void rotateBot(){
  digitalWrite(STEP_DIR_BOT, HIGH);
  for(long int i  = 0; i < rotatecount*2; i++){
    digitalWrite(STEP_STEP_BOT, HIGH);
    delayMicroseconds(stepDelay);
    digitalWrite(STEP_STEP_BOT, LOW);
    delayMicroseconds(stepDelay);
  }
}

void mid2top(){
  spinUp();
  delay(100);
  rotateTop();
  delay(100);
  spinDownLit();
  delay(100);
  rotateTop();
  spinDown();
  show_white(100);
}

void bot2top(){
  rotateBot();
  delay(200);
  mid2top();
  show_white(100);
}

#endif
