#ifndef oled_h
#define oled_h

#include <U8x8lib.h>
#include <SPI.h>
#include <SD.h>
#include <elapsedMillis.h>

#include "constants.h"



// the OLED used
U8X8_SSD1306_128X64_NONAME_SW_I2C u8x8(/* clock=*/ 15, /* data=*/ 4, /* reset=*/ 16);

bool writePattern = true;

void init_oled()
{
    char header2[] = "PATTERN";
    char header3[] = "NEXT";
    char header5[] = "UPTIME";
    char header6[] = "PALETTE";


    u8x8.begin();
    u8x8.setFont(u8x8_font_chroma48medium8_r);
    u8x8.setInverseFont(1);
    u8x8.drawString(17-(sizeof(VERSIONSTRING)/sizeof(char)), 0 , VERSIONSTRING);
    u8x8.drawString(0, 3, header2);
    u8x8.drawString(17-(sizeof(header3)/sizeof(char)), 3 , header3);
    u8x8.drawString(17-(sizeof(header5)/sizeof(char)), 6 , header5);
    u8x8.drawString(0, 6, header6);

    u8x8.setInverseFont(0);
    char header4[] = "by socks!";
    u8x8.drawString(17-(sizeof(header4)/sizeof(char)), 1 , header4);
}

void logPalette(int paletteIndex) { 
    char tmp[5];
    sprintf(tmp, "%d", paletteIndex);
    u8x8.drawString(0, 7, tmp);
}



static void updatePattern(char pattern[]){
    u8x8.setInverseFont(0);
    u8x8.drawString(0, 4, pattern);
}

static void drawTimers(int timer, elapsedSeconds uptime)
{
    u8x8.setInverseFont(0);

    // timer for next pattern
    char timestr[8];
    short min = timer / 60;
    short sec = timer % 60;
    sprintf(timestr, "%2dm %2ds", min, sec);
    u8x8.drawString(17-(sizeof(timestr)/sizeof(char)), 4, timestr);


    // uptime
    long tempUptime = uptime;

    char timestr2[11];
    short hr = tempUptime / 60 / 60;
    min = (tempUptime  % 3600) / 60;
    sec = (tempUptime  % 3600) % 60;
    sprintf(timestr2, "%3dh%2dm", hr, min);
    u8x8.drawString(17-(sizeof(timestr2)/sizeof(char)), 7, timestr2);
}

void tryWritePattern(char patternName[]){
    if ( writePattern){
        updatePattern("         ");
        updatePattern(patternName);
        writePattern = false;
    }
}



#endif