#ifndef fire_h
#define fire_h

#include "strips.h"
#include "constants.h"
#include "oled.h"


#pragma region FIRE_EXAMPLE
#define COOLING 55

// SPARKING: What chance (out of 255) is there that a new spark will be lit?
// Higher chance = more roaring fire.  Lower chance = more flickery fire.
// Default 120, suggested range 50-200.
#define SPARKING 75
CRGBPalette16 gPal = HeatColors_p;
bool gReverseDirection = false;

void Fire2012WithPalette_1()
{
  // Array of temperature readings at each simulation cell
  random16_add_entropy(random());
  static byte heat1[LEDS_PER_STRIP];

  // Step 1.  Cool down every cell a little
  for (int i = 0; i < LEDS_PER_STRIP; i++)
  {
    heat1[i] = qsub8(heat1[i], random8(0, ((COOLING * 10) / LEDS_PER_STRIP) + 2));
  }

  // Step 2.  Heat1 from each cell drifts 'up' and diffuses a little
  for (int k = LEDS_PER_STRIP - 1; k >= 2; k--)
  {
    heat1[k] = (heat1[k - 1] + heat1[k - 2] + heat1[k - 2]) / 3;
  }

  // Step 3.  Randomly ignite new 'sparks' of heat1 near the bottom
  if (random8() < SPARKING)
  {
    int y = random8(7);
    heat1[y] = qadd8(heat1[y], random8(160, 255));
  }

  // Step 4.  Map from heat1 cells to LED colors
  for (int j = 0; j < LEDS_PER_STRIP; j++)
  {
    // Scale the heat1 value from 0-255 down to 0-240
    // for best results with color palettes.
    byte colorindex = scale8(heat1[j], 240);
    CRGB color = ColorFromPalette(gPal, colorindex);
    int pixelnumber;
    if (gReverseDirection)
    {
      pixelnumber = (LEDS_PER_STRIP - 1) - j;
    }
    else
    {
      pixelnumber = j;
    }
    leds1[pixelnumber] = color;
  }
}

void Fire2012WithPalette_2()
{
  
  // Array of temperature readings at each simulation cell
  random16_add_entropy(random());
  static byte heat2[LEDS_PER_STRIP];

  // Step 1.  Cool down every cell a little
  for (int i = 0; i < LEDS_PER_STRIP; i++)
  {
    heat2[i] = qsub8(heat2[i], random8(0, ((COOLING * 10) / LEDS_PER_STRIP) + 2));
  }

  // Step 2.  Heat2 from each cell drifts 'up' and diffuses a little
  for (int k = LEDS_PER_STRIP - 1; k >= 2; k--)
  {
    heat2[k] = (heat2[k - 1] + heat2[k - 2] + heat2[k - 2]) / 3;
  }

  // Step 3.  Randomly ignite new 'sparks' of heat2 near the bottom
  if (random8() < SPARKING)
  {
    int y = random8(7);
    heat2[y] = qadd8(heat2[y], random8(160, 255));
  }

  // Step 4.  Map from heat2 cells to LED colors
  for (int j = 0; j < LEDS_PER_STRIP; j++)
  {
    // Scale the heat2 value from 0-255 down to 0-240
    // for best results with color palettes.
    byte colorindex = scale8(heat2[j], 240);
    CRGB color = ColorFromPalette(gPal, colorindex);
    int pixelnumber;
    if (gReverseDirection)
    {
      pixelnumber = (LEDS_PER_STRIP - 1) - j;
    }
    else
    {
      pixelnumber = j;
    }
    leds2[pixelnumber] = color;
  }
}

void Fire2012WithPalette_3()
{
  
  // Array of temperature readings at each simulation cell
  random16_add_entropy(random());
  static byte heat3[LEDS_PER_STRIP];

  // Step 1.  Cool down every cell a little
  for (int i = 0; i < LEDS_PER_STRIP; i++)
  {
    heat3[i] = qsub8(heat3[i], random8(0, ((COOLING * 10) / LEDS_PER_STRIP) + 2));
  }

  // Step 2.  Heat3 from each cell drifts 'up' and diffuses a little
  for (int k = LEDS_PER_STRIP - 1; k >= 2; k--)
  {
    heat3[k] = (heat3[k - 1] + heat3[k - 2] + heat3[k - 2]) / 3;
  }

  // Step 3.  Randomly ignite new 'sparks' of heat3 near the bottom
  if (random8() < SPARKING)
  {
    int y = random8(7);
    heat3[y] = qadd8(heat3[y], random8(160, 255));
  }

  // Step 4.  Map from heat3 cells to LED colors
  for (int j = 0; j < LEDS_PER_STRIP; j++)
  {
    // Scale the heat3 value from 0-255 down to 0-240
    // for best results with color palettes.
    byte colorindex = scale8(heat3[j], 240);
    CRGB color = ColorFromPalette(gPal, colorindex);
    int pixelnumber;
    if (gReverseDirection)
    {
      pixelnumber = (LEDS_PER_STRIP - 1) - j;
    }
    else
    {
      pixelnumber = j;
    }
    leds3[pixelnumber] = color;
  }
}

void Fire2012WithPalette_4()
{
  
  // Array of temperature readings at each simulation cell
  random16_add_entropy(random());
  static byte heat4[LEDS_PER_STRIP];

  // Step 1.  Cool down every cell a little
  for (int i = 0; i < LEDS_PER_STRIP; i++)
  {
    heat4[i] = qsub8(heat4[i], random8(0, ((COOLING * 10) / LEDS_PER_STRIP) + 2));
  }

  // Step 2.  Heat4 from each cell drifts 'up' and diffuses a little
  for (int k = LEDS_PER_STRIP - 1; k >= 2; k--)
  {
    heat4[k] = (heat4[k - 1] + heat4[k - 2] + heat4[k - 2]) / 3;
  }

  // Step 3.  Randomly ignite new 'sparks' of heat4 near the bottom
  if (random8() < SPARKING)
  {
    int y = random8(7);
    heat4[y] = qadd8(heat4[y], random8(160, 255));
  }

  // Step 4.  Map from heat4 cells to LED colors
  for (int j = 0; j < LEDS_PER_STRIP; j++)
  {
    // Scale the heat4 value from 0-255 down to 0-240
    // for best results with color palettes.
    byte colorindex = scale8(heat4[j], 240);
    CRGB color = ColorFromPalette(gPal, colorindex);
    int pixelnumber;
    if (gReverseDirection)
    {
      pixelnumber = (LEDS_PER_STRIP - 1) - j;
    }
    else
    {
      pixelnumber = j;
    }
    leds4[pixelnumber] = color;
  }
}

void FireNormal(uint8_t colorIndex){
    updatePattern("fire");

    gPal = HeatColors_p;
    Fire2012WithPalette_1();
    Fire2012WithPalette_2();
    Fire2012WithPalette_3();
    Fire2012WithPalette_4();
}
void FireCool(uint8_t colorIndex)
{
    updatePattern("bluecandle");

    // Second, this palette is like the heat colors, but blue/aqua instead of red/yellow
    gPal = CRGBPalette16(CRGB::Black, CRGB::Blue, CRGB::Aqua, CRGB::White);
    Fire2012WithPalette_1();
    Fire2012WithPalette_2();
    Fire2012WithPalette_3();
    Fire2012WithPalette_4();
}

#pragma endregion


#endif