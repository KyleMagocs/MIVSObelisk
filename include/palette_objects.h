#ifndef palette_objects_h
#define palette_objects_h

#include "palette.h"

int paletteIndex = 0;

struct obeliskPalette {
    String name;
    CRGBPalette16 palette;
};


obeliskPalette blues = {"BLUES", bhw1_15_gp};
obeliskPalette blueyellow = {"BLUEYELLOW", bhw1_15_gp};
obeliskPalette dark = {"DARK", Dark2_06_gp};
obeliskPalette seismic = {"SEISMIC", GMT_seis_gp};
obeliskPalette ramp = {"RGB RAMP", ramp_gp};
obeliskPalette cool = {"BLUEPINK", cool_gp};
obeliskPalette hangonfatboy = {"FATBOY", hangonfatboy_gp};
obeliskPalette winter = {"WINTER", winter_gp};
obeliskPalette ryb = {"RYB", ryb_gp};
obeliskPalette aspect = {"ASPECT", aspectcolr_gp};

obeliskPalette allPalettes[] = {
    blues,
    blueyellow,
    dark,
    seismic,
    ramp,
    cool,
    hangonfatboy,
    winter,
    ryb,
    aspect
};

int numPalettes = sizeof(allPalettes) / sizeof(obeliskPalette);
#pragma endregion

CRGBPalette16 getCurrentPalette(){
    return allPalettes[paletteIndex].palette;
}

String getCurrentPaletteName(){
    return allPalettes[paletteIndex].name;
}

void randomizePalette(){
  paletteIndex = random(numPalettes);
}

void init_palettes(){
    randomizePalette();
}


#endif