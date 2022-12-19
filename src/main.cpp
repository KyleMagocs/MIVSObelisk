
#include <elapsedMillis.h>
#include "constants.h"
#include "patterns.h"
#include "oled.h"
#include "palette_objects.h"

elapsedSeconds oledTimer;
elapsedSeconds patternTimer = PATTERN_SWAP *  2; // start it high so we start with a refresh
elapsedSeconds uptime = 0;


// #define LOGPALETTE(name) logPalette(#name)

// void logPalette(char *name) {   // what holy hell is this
//     u8x8.drawString(0, 7, name);
// }


void setup(){
    delay(1000);  // safety first!
    
    randomSeed(analogRead(0));

    init_oled();
    init_palettes();
    init_leds();
    
    // playStartupPattern();
}

static uint8_t startIndex = 0;

void loop()
{
    if (patternTimer > PATTERN_SWAP)  // SHUFFLE TIME
    {
        randomizePalette();
        randomizePattern();
        patternTimer = 0;
        writePattern = true;
    }

    draw_base();
    logPalette(getCurrentPaletteName());
    drawTimers(PATTERN_SWAP - patternTimer, uptime);  // and update the oled  

    allPatterns[patternIndex](startIndex);

    FastLED.show();
    
    if (oledTimer > OLED_DRAW)
    {
        show_oled();  
        oledTimer = 0;
    }

    FastLED.delay(1000 / UPDATES_PER_SECOND);
   


    startIndex++; /* motion speed */ 
}