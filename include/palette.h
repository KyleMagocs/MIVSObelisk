#ifndef Palette_h
#define Palette_h

#include <FastLED.h>

CRGBPalette16 currentPalette = Rainbow_gp;
int paletteIndex = 0;

#pragma region palettes
CRGB purple = CHSV(HUE_PURPLE, 255, 255);
CRGB green = CHSV(HUE_GREEN, 255, 255);
CRGB black = CRGB::Black;
CRGB white = CRGB::White;

// Gradient palette "bhw1_15_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/bhw/bhw1/tn/bhw1_15.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 20 bytes of program space.

DEFINE_GRADIENT_PALETTE( bhw1_15_gp ) {
    0,   1,  8, 87,
   71,  23,195,130,
  122, 186,248,233,
  168,  23,195,130,
  255,   1,  8, 87};

  // Gradient palette "bhw2_23_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/bhw/bhw2/tn/bhw2_23.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 28 bytes of program space.

DEFINE_GRADIENT_PALETTE( bhw2_23_gp ) {
    0,   0,  0,  0,
   66,  57,227,233,
   96, 255,255,  8,
  124, 255,255,255,
  153, 255,255,  8,
  188,  57,227,233,
  255,   0,  0,  0};



// Gradient palette "bhw2_50_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/bhw/bhw2/tn/bhw2_50.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 20 bytes of program space.
DEFINE_GRADIENT_PALETTE( bhw2_50_gp ) {
    0,   8,  2, 23,
   84,  47,  7,102,
  138,  16, 46,147,
  173,   2,127,203,
  255,   1,  7, 11};

// Gradient palette "Dark2_06_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/cb/qual/tn/Dark2_06.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 48 bytes of program space.
DEFINE_GRADIENT_PALETTE( Dark2_06_gp ) {
    0,   1, 88, 37,
   42,   1, 88, 37,
   42, 167, 29,  1,
   84, 167, 29,  1,
   84,  33, 41,105,
  127,  33, 41,105,
  127, 197,  4, 54,
  170, 197,  4, 54,
  170,  23, 99,  1,
  212,  23, 99,  1,
  212, 194,105,  1,
  255, 194,105,  1};

// Gradient palette "German_flag_smooth_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/ggr/tn/German_flag_smooth.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 20 bytes of program space.
DEFINE_GRADIENT_PALETTE( German_flag_smooth_gp ) {
    0,   0,  0,  0,
   63,  42,  0,  0,
  127, 255,  0,  0,
  191, 255, 55,  0,
  255, 255,255,  0};

// Gradient palette "ramp_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/grass/tn/ramp.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 24 bytes of program space.
DEFINE_GRADIENT_PALETTE( ramp_gp ) {
    0,   0,  0,  0,
   84,   0,  0,255,
   84,   0,  0,  0,
  170,   0,255,  0,
  170,   0,  0,  0,
  255, 255,  0,  0};

// Gradient palette "GMT_seis_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/gmt/tn/GMT_seis.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 40 bytes of program space.
DEFINE_GRADIENT_PALETTE( GMT_seis_gp ) {
    0,  88,  0,  0,
   28, 255,  0,  0,
   56, 255, 22,  0,
   85, 255,104,  0,
  113, 255,255,  0,
  141, 255,255,  0,
  169,  17,255,  1,
  198,   0,223, 31,
  226,   0, 19,255,
  255,   0,  0,147};

// Gradient palette "winter_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/h5/tn/winter.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 8 bytes of program space.
DEFINE_GRADIENT_PALETTE( winter_gp ) {
    0,   0,  0,255,
  255,   0,255, 44};

// Gradient palette "cool_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/h5/tn/cool.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 8 bytes of program space.
DEFINE_GRADIENT_PALETTE( cool_gp ) {
    0,   0,255,255,
  255, 255,  0,255};

// Gradient palette "yarg_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/h5/tn/yarg.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 8 bytes of program space.
DEFINE_GRADIENT_PALETTE( yarg_gp ) {
    0,   0,  0,  0,
  255, 255,255,255};


CRGBPalette16 allPalettes[] = {
    Dark2_06_gp,
    bhw2_50_gp,
    GMT_seis_gp,
    ramp_gp,
    cool_gp,
    yarg_gp,
    // WhiteStripes_p // ack it just looks like ass because I'm not injecting better power
    winter_gp
};

int numPalettes = sizeof(allPalettes) / sizeof(CRGBPalette16);
#pragma endregion

CRGBPalette16 getCurrentPalette(){
    return allPalettes[paletteIndex];
}

void randomizePalette(){
  paletteIndex = random(numPalettes);
}

void init_palettes(){
    randomizePalette();
}

#endif