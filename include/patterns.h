#ifndef patterns_h
#define patterns_h

#include "palette_objects.h"
#include "constants.h"
#include "fire.h"
#include "ocean.h"
#include "oled.h"
#include "strips.h"
#include "matrix.h"

short patternIndex;


void playStartupPattern(){
    for(int i = LEDS_PER_STRIP-1; i >= 0; i--){
    
        leds1[i] = CHSV(192+i*2, 255, BRIGHTNESS);
        leds2[i] = CHSV(192+i*2, 255, BRIGHTNESS);
        leds3[i] = CHSV(192+i*2, 255, BRIGHTNESS);
        leds4[i] = CHSV(192+i*2, 255, BRIGHTNESS);

        leds2[LEDS_PER_STRIP+i] =  CHSV(128+i*2, 255, BRIGHTNESS);
        leds1[LEDS_PER_STRIP+i] =  CHSV(128+i*2, 255, BRIGHTNESS);
        leds3[LEDS_PER_STRIP+i] =  CHSV(128+i*2, 255, BRIGHTNESS);
        leds4[LEDS_PER_STRIP+i] =  CHSV(128+i*2, 255, BRIGHTNESS);

        leds2[LEDS_PER_STRIP*2+i] =  CHSV(64+i*2, 255, BRIGHTNESS);
        leds1[LEDS_PER_STRIP*2+i] =  CHSV(64+i*2, 255, BRIGHTNESS);
        leds3[LEDS_PER_STRIP*2+i] =  CHSV(64+i*2, 255, BRIGHTNESS);
        leds4[LEDS_PER_STRIP*2+i] =  CHSV(64+i*2, 255, BRIGHTNESS);

        leds2[LEDS_PER_STRIP*3+i] =  CHSV(0+i*2, 255, BRIGHTNESS);
        leds1[LEDS_PER_STRIP*3+i] =  CHSV(0+i*2, 255, BRIGHTNESS);
        leds3[LEDS_PER_STRIP*3+i] =  CHSV(0+i*2, 255, BRIGHTNESS);
        leds4[LEDS_PER_STRIP*3+i] =  CHSV(0+i*2, 255, BRIGHTNESS);
        FastLED.show();
        delay(50);
    }
    delay(5000);
    for(int i = 0; i < NUM_LEDS; i++){
        leds1[i] = CHSV(0, 0, BRIGHTNESS);
        leds2[i] = CHSV(0, 0, BRIGHTNESS);
        leds3[i] = CHSV(0, 0, BRIGHTNESS);
        leds4[i] = CHSV(0, 0, BRIGHTNESS);
        fadeToBlackBy(leds1, i, 40);
        fadeToBlackBy(leds2, i, 40);
        fadeToBlackBy(leds3, i, 40);
        fadeToBlackBy(leds4, i, 40);
        FastLED.show();
        delay(20);
    }
    for(int i = 0; i < 12; i++){  // get the rest of them to fade out
        fadeToBlackBy(leds1, NUM_LEDS, 40);
        fadeToBlackBy(leds2, NUM_LEDS, 40);
        fadeToBlackBy(leds3, NUM_LEDS, 40);
        fadeToBlackBy(leds4, NUM_LEDS, 40);
        FastLED.show();
        delay(20);
    }
    FastLED.show();
}

void FillAllStripsUniform( uint8_t colorIndex)
{
    updatePattern("uniform");

    for( int i = 0; i < NUM_LEDS; i++) {
        leds1[i] = ColorFromPalette( getCurrentPalette(), colorIndex, BRIGHTNESS, currentBlending);
        leds2[i] = ColorFromPalette( getCurrentPalette(), colorIndex, BRIGHTNESS, currentBlending);
        leds3[i] = ColorFromPalette( getCurrentPalette(), colorIndex, BRIGHTNESS, currentBlending);
        leds4[i] = ColorFromPalette( getCurrentPalette(), colorIndex, BRIGHTNESS, currentBlending);
    }
}

void FillAllStripsCycle( uint8_t colorIndex)
{
    updatePattern("cycle");
    for( int i = 0; i < NUM_LEDS; i++) {
        leds1[i] = ColorFromPalette( getCurrentPalette(), colorIndex, BRIGHTNESS, currentBlending);
        leds2[i] = ColorFromPalette( getCurrentPalette(), colorIndex, BRIGHTNESS, currentBlending);
        leds3[i] = ColorFromPalette( getCurrentPalette(), colorIndex, BRIGHTNESS, currentBlending);
        leds4[i] = ColorFromPalette( getCurrentPalette(), colorIndex, BRIGHTNESS, currentBlending);
        colorIndex++;
    }
}

void FillEachCube( uint8_t colorIndex)
{
    updatePattern("cubes");
  for(int i = 0; i < 4; i++){  // each box
    for(int j = 0; j < LEDS_PER_STRIP; j++)  // each LED in the box
    {
      leds1[i*LEDS_PER_STRIP + j] = ColorFromPalette( getCurrentPalette(), colorIndex+i*64, BRIGHTNESS, currentBlending);
      leds2[i*LEDS_PER_STRIP + j] = ColorFromPalette( getCurrentPalette(), colorIndex+i*64, BRIGHTNESS, currentBlending);
      leds3[i*LEDS_PER_STRIP + j] = ColorFromPalette( getCurrentPalette(), colorIndex+i*64, BRIGHTNESS, currentBlending);
      leds4[i*LEDS_PER_STRIP + j] = ColorFromPalette( getCurrentPalette(), colorIndex+i*64, BRIGHTNESS, currentBlending);
    }
  }
}

void CycleCubes( uint8_t colorIndex)
{
  updatePattern("cubecycle");
  for(int i = 0; i < 4; i++){  // each box
    for(int j = 0; j < LEDS_PER_STRIP; j++)  // each LED in the box
    {
      leds1[i*LEDS_PER_STRIP + j] = ColorFromPalette( getCurrentPalette(), colorIndex+i*64, BRIGHTNESS, currentBlending);
      leds2[i*LEDS_PER_STRIP + j] = ColorFromPalette( getCurrentPalette(), colorIndex+i*64, BRIGHTNESS, currentBlending);
      leds3[i*LEDS_PER_STRIP + j] = ColorFromPalette( getCurrentPalette(), colorIndex+i*64, BRIGHTNESS, currentBlending);
      leds4[i*LEDS_PER_STRIP + j] = ColorFromPalette( getCurrentPalette(), colorIndex+i*64, BRIGHTNESS, currentBlending);
      colorIndex+= 3;
    }
  }
}

void FillEachPillar( uint8_t colorIndex)
{
    updatePattern("pillars");
    for( int i = 0; i < NUM_LEDS; i++) {
        leds1[i] = ColorFromPalette( getCurrentPalette(), colorIndex, BRIGHTNESS, currentBlending);
    }
    for( int i = 0; i < NUM_LEDS; i++) {
        leds2[i] = ColorFromPalette( getCurrentPalette(), colorIndex+32, BRIGHTNESS, currentBlending);
    }
    for( int i = 0; i < NUM_LEDS; i++) {
        leds3[i] = ColorFromPalette( getCurrentPalette(), colorIndex+64, BRIGHTNESS, currentBlending);
    }
    for( int i = 0; i < NUM_LEDS; i++) {
        leds4[i] = ColorFromPalette( getCurrentPalette(), colorIndex+96, BRIGHTNESS, currentBlending);
    }
}

// there are several patterns that are seeded before they play, and it's kinda ugly if they start mid-stream
void reseedTheSeeded(){
    init_matrix();
    init_fire();
}

typedef void (*PatternFunction)(uint8_t index);
PatternFunction allPatterns[] = {
    FillAllStripsCycle,
    FillAllStripsUniform,
    FillEachCube,
    CycleCubes,
    FillEachPillar,
    pacifica_loop,
    FireNormal,
    FireCool,
    Matrix
    };
int NUMPATTERNS = sizeof(allPatterns) / sizeof(PatternFunction);

void randomizePattern()
{
    patternIndex = random(NUMPATTERNS);
    
}



#endif