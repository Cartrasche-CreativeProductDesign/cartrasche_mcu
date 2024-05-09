#ifndef _LED_CONTROL_H
#define _LED_CONTROL_H

#include "config.h"
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, LED_PIN, NEO_GRBW + NEO_KHZ800);
Adafruit_NeoPixel strip1 = Adafruit_NeoPixel(NUM_STRIP, STRIP_PIN1, NEO_GRBW + NEO_KHZ800);
Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(NUM_STRIP, STRIP_PIN2, NEO_GRBW + NEO_KHZ800);


void initializeLED(){
  pixels.begin();
  // strip1.begin();
  // strip2.begin();

  for(int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i,pixels.Color(100,100,100)); 
  }
  // for(int i=0;i<NUM_STRIP;i++){
  //   // strip1.setPixelColor(i,pixels.Color(100,100,100)); 
  //   // strip2.setPixelColor(i,pixels.Color(100,100,100)); 
  // }     
  pixels.show();
  // strip1.show();
  // strip2.show();
  delay(PIXEL_DELAY);
}
////////////////////////// MAIN CENTER LED RING //////////////////////////
void show_red(int brightness){
  for(int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i,pixels.Color(brightness,0,0)); 
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

void turn_off_led(){
  pixels.clear();
  pixels.show();
  delay(PIXEL_DELAY);
  return;
}
/////////////////////////////////////////////////////////////////////////

//////////////////////////// FRONT KKAMBBAKGI ///////////////////////////
// void strip1_control(int r, int g, int b){
//   for(int i=0;i<NUMPIXELS;i++){
//     strip1.setPixelColor(i,strip1.Color(r,g,b)); 
//   }
//   strip1.show(); //update hardware with RGB color set
//   delay(1000);
//   return;
// }

// void strip2_control(int r, int g, int b){
//   for(int i=0;i<NUMPIXELS;i++){
//     strip2.setPixelColor(i,strip2.Color(r,g,b)); 
//   }
//   strip2.show(); //update hardware with RGB color set
//   delay(1000);
//   return;
// }
/////////////////////////////////////////////////////////////////////////
#endif
