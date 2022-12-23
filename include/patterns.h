#ifndef patterns_h
#define patterns_h

#include "palette_objects.h"
#include "constants.h"
#include "fire.h"
#include "ocean.h"
#include "matrix.h"
#include "oled.h"
#include "strips.h"

short patternIndex;

void FillAllStripsUniform( uint8_t colorIndex)
{
    updatePattern("UNIFORM");

    for( int i = 0; i < NUM_LEDS; i++) {
        leds1[i] = ColorFromPalette( getCurrentPalette(), colorIndex, BRIGHTNESS, currentBlending);
        leds2[i] = ColorFromPalette( getCurrentPalette(), colorIndex, BRIGHTNESS, currentBlending);
        leds3[i] = ColorFromPalette( getCurrentPalette(), colorIndex, BRIGHTNESS, currentBlending);
        leds4[i] = ColorFromPalette( getCurrentPalette(), colorIndex, BRIGHTNESS, currentBlending);
    }
}

void FillAllStripsCycle( uint8_t colorIndex)
{
    updatePattern("CYCLE");
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
    updatePattern("CUBES");
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
  updatePattern("CUBECYCLE");
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
    updatePattern("PILLARS");
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

void playStartupPattern(){
    // delay(3000);  // TODO:  THIS
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
    FireCool
    };
int NUMPATTERNS = sizeof(allPatterns) / sizeof(PatternFunction);

void randomizePattern()
{
    patternIndex = random(NUMPATTERNS);
}



#endif