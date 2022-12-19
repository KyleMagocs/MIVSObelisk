#ifndef oled_h
#define oled_h

#include <SPI.h>
#include <SD.h>
#include <elapsedMillis.h>
#include "heltec.h"
#include "constants.h"



bool writePattern = true;

void init_oled()
{
    Heltec.begin(true /*DisplayEnable Enable*/, false /*LoRa Enable*/, true /*Serial Enable*/);
    Heltec.display->setFont(ArialMT_Plain_10);
}

void draw_base() {
    char header2[] = "PATTERN";
    char header3[] = "NEXT";
    char header5[] = "UPTIME";
    char header6[] = "PALETTE";

    Heltec.display -> clear();
    // Heltec.display->
    // Heltec.display->setInverseFont(1);
    Heltec.display->drawString(128-(sizeof(VERSIONSTRING)/sizeof(char))*6, 0 , VERSIONSTRING);
    Heltec.display->drawString(0, 16, header2);
    Heltec.display->drawString(128-(sizeof(header3)/sizeof(char))*6, 16 , header3);
    Heltec.display->drawString(128-(sizeof(header5)/sizeof(char))*6, 40 , header5);
    Heltec.display->drawString(0, 40, header6);

    // Heltec.display->setInverseFont(0);
    char header4[] = "by socks!";
    Heltec.display->drawString(128-(sizeof(header4)/sizeof(char))*8, 8 , header4);
}

void logPalette(String paletteName) { 
    Heltec.display->drawString(0, 48, paletteName);
}

static void updatePattern(char pattern[]){
    // Heltec.display->setInverseFont(0);
    Heltec.display->drawString(0, 24, pattern);
}

static void drawTimers(int timer, elapsedSeconds uptime)
{
    // Heltec.display->setInverseFont(0);

    // timer for next pattern
    char timestr[8];
    short min = timer / 60;
    short sec = timer % 60;
    sprintf(timestr, "%2dm %2ds", min, sec);
    Heltec.display->drawString(128-5*8, 24, timestr);


    // uptime
    long tempUptime = uptime;

    char timestr2[11];
    short hr = tempUptime / 60 / 60;
    min = (tempUptime  % 3600) / 60;
    sec = (tempUptime  % 3600) % 60;
    sprintf(timestr2, "%3dh%2dm", hr, min);
    Heltec.display->drawString(128-5*8, 48, timestr2);
}

void show_oled(){
    Heltec.display -> display();
}

#endif