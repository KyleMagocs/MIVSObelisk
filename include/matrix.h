#ifndef matrix_h
#define matrix_h

#include "strips.h"
#include "constants.h"
#include "oled.h"
#include "FastLED.h"

const int TOTALLEDS = NUM_LEDS*NUM_STRIPS;
static byte rain[TOTALLEDS];
int speed = 1;
bool matrixInitialized = false;

void changepattern () {
  int rand1 = random16 (TOTALLEDS);
  int rand2 = random16 (TOTALLEDS);
  if ((rain[rand1] == 1) && (rain[rand2] == 0) )   //take a dot that's on, flip it off; take a dot that's off, flip it on
  {
    rain[rand1] = 0;  
    rain[rand2] = 1;
  }
} 

void raininit() { 
  FastLED.setBrightness(255);   
  FastLED.clear();                           //init array of dots. run once
  for (int i = 0; i < TOTALLEDS; i++) {
    
    if (random8(20) == 0) {
      rain[i] = 1;  //random8(20) number of dots. decrease for more dots
    }
    else {
      // Serial.println(i);
      rain[i] = 0;
    }
  }
  matrixInitialized=true;
} //raininit

void drawIt(int index) {
  int localIndex = index % NUM_LEDS;
  if(index < NUM_LEDS){
      // Serial.print("   1  "); Serial.println(localIndex);
      leds1[localIndex] = CHSV(110, 255, BRIGHTNESS); 
  }
  else if(index >= NUM_LEDS && index < NUM_LEDS * 2){
    // Serial.print("   2  "); Serial.println(localIndex);
    leds2[localIndex] = CHSV(110, 255, BRIGHTNESS);
  }
  else if(index >= NUM_LEDS*2 && index < NUM_LEDS * 3){
    // Serial.print("   3  "); Serial.println(localIndex);
    leds3[localIndex] = CHSV(110, 255, BRIGHTNESS);
  }
  else if(index >= NUM_LEDS*3){
    // Serial.print("   4  "); Serial.println(localIndex);
    leds4[localIndex] = CHSV(110, 255, BRIGHTNESS);
  }
}

void DoMatrix() {
    for (int j = 0; j < TOTALLEDS; j++) {
      // random8(2) add glitchy look
      // grab a random LED
      byte activepx = rain[((j + speed + random8(2) + TOTALLEDS) % TOTALLEDS)];   //fake scroll based on shift coordinate
      if (activepx) {  // if that LED is not off
       int index = (TOTALLEDS - 1) - j; 
        drawIt(index);
      }
      
  }
  speed ++;
  fadeToBlackBy(leds1, NUM_LEDS, 40);
  fadeToBlackBy(leds2, NUM_LEDS, 40);
  fadeToBlackBy(leds3, NUM_LEDS, 40);
  fadeToBlackBy(leds4, NUM_LEDS, 40);
} //updaterain


void Matrix(int _nothing) {
  if (!matrixInitialized){
    raininit();
  }

  DoMatrix();

  EVERY_N_MILLISECONDS(30) {
      changepattern();
  }
  delay(100); // slow the pattern down

}



#endif