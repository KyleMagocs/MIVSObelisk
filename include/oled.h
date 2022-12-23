#ifndef oled_h
#define oled_h

#include <SPI.h>
#include <SD.h>
#include <elapsedMillis.h>
#include "heltec.h"
#include "constants.h"


void draw_base() {
    Heltec.display -> clear();
    // Heltec.display->
    // Heltec.display->setInverseFont(1);
    Heltec.display->setColor(WHITE);  // DRAW BG
    Heltec.display->fillRect(0,0,128,1);  // cute line
    Heltec.display->fillRect(0,2,128,9);  // version
    Heltec.display->fillRect(0,23,48,9);  // palette
    Heltec.display->fillRect(0,46,48,9);  // pattern
    Heltec.display->fillRect(100,23,48,9);  // next
    Heltec.display->fillRect(88,46,48,9);  // uptime
    Heltec.display->setColor(BLACK);  // DRAW TEXT
    Heltec.display->setTextAlignment(TEXT_ALIGN_LEFT);
    Heltec.display->drawString(0, 21, "PALETTE");
    Heltec.display->drawString(0, 44, "PATTERN");

    // Heltec.display->setInverseFont(0);
    Heltec.display->setTextAlignment(TEXT_ALIGN_RIGHT);
    Heltec.display->drawString(127, 21 , "NEXT");
    Heltec.display->drawString(127, 44 , "UPTIME");
    Heltec.display->drawString(127, 0 , VERSIONSTRING);

    Heltec.display->setColor(WHITE);
    Heltec.display->drawRect(76,11,48,10);
    Heltec.display->drawString(122, 9 , "by socks!");
}

void logPalette(String paletteName) { 
    Heltec.display->setTextAlignment(TEXT_ALIGN_LEFT);
    Heltec.display->drawString(0, 30, paletteName);
}

void updatePattern(String pattern){
    Heltec.display->setTextAlignment(TEXT_ALIGN_LEFT);
    // Heltec.display->setInverseFont(0);
    Heltec.display->drawString(0, 54, pattern);
}

static void drawTimers(int timer, elapsedSeconds uptime)
{
    // Heltec.display->setInverseFont(0);

    Heltec.display->setTextAlignment(TEXT_ALIGN_RIGHT);
    // timer for next pattern
    char timestr[8];
    short min = timer / 60;
    short sec = timer % 60;
    sprintf(timestr, "%2dm %2ds", min, sec);
    sprintf(timestr, "%6d", timer);
    Heltec.display->drawString(127, 30, timestr);


    // uptime
    long tempUptime = uptime;
    char timestr2[11];
    short hr = tempUptime / 60 / 60;
    min = (tempUptime  % 3600) / 60;
    sec = (tempUptime  % 3600) % 60;
    sprintf(timestr2, "%3dh%2dm%2ds", hr, min,sec);
    
    Heltec.display->drawString(127, 54, timestr2);
}

void drawBrightness(float b){
    char bstr[6];
    sprintf(bstr, "%5f", b);
    Heltec.display->drawString(80,32,bstr);
}

void show_oled(){
    Heltec.display -> display();
}

void clear_oled(){
    Heltec.display->clear();
    Heltec.display-> display();
}

void init_oled()
{
    Heltec.begin(true /*DisplayEnable Enable*/, false /*LoRa Enable*/, true /*Serial Enable*/);
    Heltec.display->setFont(ArialMT_Plain_10);
    // draw_base();
    Heltec.display->clear();
    Heltec.display->drawFastImage(0,0,128,64, cubesbmp);
    show_oled();
}



#endif