
#include <elapsedMillis.h>
#include "constants.h"
#include "patterns.h"
#include "oled.h"
#include "palette_objects.h"

elapsedSeconds oledTimer;
elapsedMillis patternTimer = PATTERN_SWAP *  2; // start it high so we start with a refresh
elapsedSeconds uptime = 0;

static uint8_t startIndex = 0;

void setup(){
    delay(1000);  // safety first!
    
    randomSeed(analogRead(0));

    init_oled();
    init_palettes();
    init_leds();
    
    playStartupPattern();
    clear_oled();
}

void tryPatternSwap(){
    float timer = patternTimer/(float)1000;
    if (timer > PATTERN_SWAP)  // SHUFFLE TIME
    {
        randomizePalette();
        randomizePattern();
        reseedTheSeeded();

        patternTimer = 0;
    }
}

float brightness = 0.0;
void tryCrossFade(){
    float timer = patternTimer/(float)1000;
    if(PATTERN_SWAP-timer < PATTERN_COOLDOWN || timer < PATTERN_COOLDOWN)  // fade out for the last ten seconds, fade in for the first 10 seconds
    {
        float time_delta = min((float)timer, (float)(PATTERN_SWAP-timer));
        float factor = abs(time_delta*(1.0/PATTERN_COOLDOWN));  //this should give you a range of 0-PATTERN_COOLDOWN
        brightness=BRIGHTNESS*factor;
        FastLED.setBrightness(brightness);
    }
}

void drawOled(){
    draw_base();
    logPalette(getCurrentPaletteName());
    drawTimers(PATTERN_SWAP-patternTimer/1000, uptime);  // and update the oled  
}

void tryShowOled(){
    if (oledTimer > OLED_DRAW)
    {
        oledTimer = 0;
        show_oled();  
    }
}

void loop()
{
    tryPatternSwap();
    tryCrossFade();
    drawOled();

    allPatterns[patternIndex](startIndex);
    
    FastLED.show();
    FastLED.delay(1000 / UPDATES_PER_SECOND);
    
    startIndex++; /* motion speed */ 

    tryShowOled();

}