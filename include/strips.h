#ifndef strips_h
#define strips_h


#include <FastLED.h>
#include "constants.h"

#define COLOR_ORDER GRB
#define LED_TYPE    WS2812
TBlendType    currentBlending = LINEARBLEND;

CRGB leds1[NUM_LEDS];
CRGB leds2[NUM_LEDS];
CRGB leds3[NUM_LEDS];
CRGB leds4[NUM_LEDS];

void init_leds(){
    FastLED.addLeds<LED_TYPE, LED_PIN_1, COLOR_ORDER>(leds1, NUM_LEDS).setCorrection( TypicalLEDStrip );
    FastLED.addLeds<LED_TYPE, LED_PIN_2, COLOR_ORDER>(leds2, NUM_LEDS).setCorrection( TypicalLEDStrip );
    FastLED.addLeds<LED_TYPE, LED_PIN_3, COLOR_ORDER>(leds4, NUM_LEDS).setCorrection( TypicalLEDStrip );
    FastLED.addLeds<LED_TYPE, LED_PIN_4, COLOR_ORDER>(leds3, NUM_LEDS).setCorrection( TypicalLEDStrip );

    FastLED.setBrightness(BRIGHTNESS);  

    FastLED.clear();
    FastLED.show();
}

#endif