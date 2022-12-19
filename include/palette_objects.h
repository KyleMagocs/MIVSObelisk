#ifndef palette_objects_h
#define palette_objects_h

#include "palette.h"

int paletteIndex = 0;

struct obeliskPalette {
    String name;
    CRGBPalette16 palette;
};


obeliskPalette blues = {"blues", bhw1_15_gp};
obeliskPalette blueyellow = {"blueyellow", bhw1_15_gp};
obeliskPalette dark = {"dark", Dark2_06_gp};
obeliskPalette seismic = {"Seismic", GMT_seis_gp};
obeliskPalette ramp = {"rgb ramp", ramp_gp};
obeliskPalette cool = {"bluepink", cool_gp};
obeliskPalette hangonfatboy = {"fatboy", hangonfatboy_gp};
obeliskPalette winter = {"winter", winter_gp};
obeliskPalette ryb = {"ryb", ryb_gp};
obeliskPalette aspect = {"aspect", aspectcolr_gp};

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