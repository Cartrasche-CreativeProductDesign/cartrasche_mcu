#ifndef _LED_CONTROL_H
#define _LED_CONTROL_H

#include "config.h"
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, LED_PIN, NEO_GRBW + NEO_KHZ800);
//Adafruit_NeoPixel strip1 = Adafruit_NeoPixel(NUM_STRIP, STRIP_PIN1, NEO_GRB + NEO_KHZ800);
//Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(NUM_STRIP, STRIP_PIN2, NEO_GRB + NEO_KHZ800);


void initializeLED(){
  pixels.begin();

  for(int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i,pixels.Color(80,80,80));
    pixels.show();
    delay(200);
  }
}

///////////////////// MAIN CENTER LED RING //////////////////////////
void show_red(int brightness){
  for(int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i,pixels.Color(brightness,20, 40)); 
  }
  pixels.show(); //update hardware with RGB color set
  delay(PIXEL_DELAY);
  return;
}

void show_yellow(int brightness){
  for(int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i,pixels.Color(brightness,brightness,0)); 
  }
  pixels.show(); //update hardware with RGB color set
  delay(PIXEL_DELAY);
  return;
}

void show_green(int brightness){
  for(int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i,pixels.Color(0,brightness,0)); 
  }
  pixels.show(); //update hardware with RGB color set
  delay(PIXEL_DELAY);
  return;
}

void show_blue(int brightness){
  for(int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i,pixels.Color(0,0,brightness)); 
  }
  pixels.show(); //update hardware with RGB color set
  delay(PIXEL_DELAY);
  return;
}

void show_violet(int brightness){
  for(int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i,pixels.Color(brightness,0,brightness)); 
  }
  pixels.show(); //update hardware with RGB color set
  delay(PIXEL_DELAY);
  return;
}

void show_white(int brightness){
  for(int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i,pixels.Color(brightness,brightness,brightness)); 
  }
  pixels.show(); //update hardware with RGB color set
  delay(PIXEL_DELAY);
  return;
}

void show_pink(){
  for(int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i,pixels.Color(255,178,245)); 
  }
  pixels.show(); //update hardware with RGB color set
  delay(PIXEL_DELAY);
  return;
}

void turn_off_led(){
  pixels.clear();
  pixels.show();
  delay(PIXEL_DELAY);
  return;
}
/////////////////////////////////////////////////////////////////////////

/*
//////////////////////////// FRONT KKAMBBAKGI ///////////////////////////
void strip1_control(int r, int g, int b, int rangeI, int rangeF){
  for(int i=rangeI;i<rangeF;i++){
    strip1.setPixelColor(i,strip1.Color(r,g,b)); 
  }
  strip1.show();
  delay(PIXEL_DELAY);
  return;
}

void strip2_control(int r, int g, int b, int rangeI, int rangeF){
  for(int i=rangeI;i<rangeF;i++){
    strip2.setPixelColor(i,strip2.Color(r,g,b)); 
  }
  strip2.show();
  delay(PIXEL_DELAY);
  return;
}

void turn_off_strip1(){
  strip1.clear();
  strip1.show();
  delay(50);
  return;
}

void turn_off_strip2(){
  strip2.clear();
  strip2.show();
  delay(50);
  return;
}

void initializeSTRIPS(){
  strip1.begin();
  strip2.begin();
  for(int i=0;i<NUM_STRIP;i++){
    strip1.setPixelColor(i,strip1.Color(100,100,100));
    strip2.setPixelColor(i,strip2.Color(100,100,100));
    strip1.show();
    strip2.show();
  }
  delay(1000);
}
/////////////////////////////////////////////////////////////////////////

void indicFWD(){
  strip1.clear();
  strip2.clear();
  strip1_control(100,100,100,0,9);
  strip2_control(100,100,100,0,9);
}

void indicBWD(){
  strip1.clear();
  strip2.clear();
  strip1_control(100,100,100,9,NUM_STRIP);
  strip2_control(100,100,100,9,NUM_STRIP);

}

void indicLEFT(){
  strip1.clear();
  strip2.clear();
  strip1_control(100,100,100,0,NUM_STRIP);
  strip2.show();
}

void indicRIGHT(){
  strip1.clear();
  strip2.clear();
  strip1.show();
  strip2_control(100,100,100,0,NUM_STRIP);
}

*/
#endif
