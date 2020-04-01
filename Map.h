uint8_t pps = 3;  // number of Pixels Per Segment
CHSV segBlack(0,0,0); //black

// Name segments and define pixel ranges.
//     1....2....3....4
//    AAA
//   F   B
//    GGG   
//   E   C  
//    DDD

CRGBSet seg1A(  leds(pps*0,  pps-1+(pps*0)  ));
CRGBSet seg1B(  leds(pps*1,  pps-1+(pps*1)  ));
CRGBSet seg1C(  leds(pps*2,  pps-1+(pps*2)  ));
CRGBSet seg1D(  leds(pps*3,  pps-1+(pps*3)  ));
CRGBSet seg1E(  leds(pps*4,  pps-1+(pps*4)  ));
CRGBSet seg1F(  leds(pps*5,  pps-1+(pps*5)  ));
CRGBSet seg1G(  leds(pps*6,  pps-1+(pps*6)  ));

CRGBSet seg2A(  leds(pps*0+(1*7*pps),  pps-1+(pps*0)+(1*7*pps)  ));
CRGBSet seg2B(  leds(pps*1+(1*7*pps),  pps-1+(pps*1)+(1*7*pps)  ));
CRGBSet seg2C(  leds(pps*2+(1*7*pps),  pps-1+(pps*2)+(1*7*pps)  ));
CRGBSet seg2D(  leds(pps*3+(1*7*pps),  pps-1+(pps*3)+(1*7*pps)  ));
CRGBSet seg2E(  leds(pps*4+(1*7*pps),  pps-1+(pps*4)+(1*7*pps)  ));
CRGBSet seg2F(  leds(pps*5+(1*7*pps),  pps-1+(pps*5)+(1*7*pps)  ));
CRGBSet seg2G(  leds(pps*6+(1*7*pps),  pps-1+(pps*6)+(1*7*pps)  ));

CRGBSet seg3A(  leds(pps*0+(2*7*pps),  pps-1+(pps*0)+(2*7*pps)  ));
CRGBSet seg3B(  leds(pps*1+(2*7*pps),  pps-1+(pps*1)+(2*7*pps)  ));
CRGBSet seg3C(  leds(pps*2+(2*7*pps),  pps-1+(pps*2)+(2*7*pps)  ));
CRGBSet seg3D(  leds(pps*3+(2*7*pps),  pps-1+(pps*3)+(2*7*pps)  ));
CRGBSet seg3E(  leds(pps*4+(2*7*pps),  pps-1+(pps*4)+(2*7*pps)  ));
CRGBSet seg3F(  leds(pps*5+(2*7*pps),  pps-1+(pps*5)+(2*7*pps)  ));
CRGBSet seg3G(  leds(pps*6+(2*7*pps),  pps-1+(pps*6)+(2*7*pps)  ));

CRGBSet seg4A(  leds(pps*0+(3*7*pps),  pps-1+(pps*0)+(3*7*pps)  ));
CRGBSet seg4B(  leds(pps*1+(3*7*pps),  pps-1+(pps*1)+(3*7*pps)  ));
CRGBSet seg4C(  leds(pps*2+(3*7*pps),  pps-1+(pps*2)+(3*7*pps)  ));
CRGBSet seg4D(  leds(pps*3+(3*7*pps),  pps-1+(pps*3)+(3*7*pps)  ));
CRGBSet seg4E(  leds(pps*4+(3*7*pps),  pps-1+(pps*4)+(3*7*pps)  ));
CRGBSet seg4F(  leds(pps*5+(3*7*pps),  pps-1+(pps*5)+(3*7*pps)  ));
CRGBSet seg4G(  leds(pps*6+(3*7*pps),  pps-1+(pps*6)+(3*7*pps)  ));

CRGBSet col(leds(84,85)); //colon

uint8_t coordsX[NUM_LEDS] = { 1, 2, 3, 4, 4, 4, 4, 4, 4, 3, 2, 1, 0, 0, 0, 0, 0, 0, 1, 2, 3, 7, 8, 9, 10, 10, 10, 10, 10, 10, 9, 8, 7, 6, 6, 6, 6, 6, 6, 7, 8, 9, 15, 16, 17, 18, 18, 18, 18, 18, 18, 17, 16, 15, 14, 14, 14, 14, 14, 14, 15, 16, 17, 21, 22, 23, 24, 24, 24, 24, 24, 24, 23, 22, 21, 20, 20, 20, 20, 20, 20, 21, 22, 23, 12, 12 };
uint8_t coordsY[NUM_LEDS] = { 0, 0, 0, 1, 2, 3, 5, 6, 7, 8, 8, 8, 7, 6, 5, 3, 2, 1, 4, 4, 4, 0, 0, 0, 1, 2, 3, 5, 6, 7, 8, 8, 8, 7, 6, 5, 3, 2, 1, 4, 4, 4, 0, 0, 0, 1, 2, 3, 5, 6, 7, 8, 8, 8, 7, 6, 5, 3, 2, 1, 4, 4, 4, 0, 0, 0, 1, 2, 3, 5, 6, 7, 8, 8, 8, 7, 6, 5, 3, 2, 1, 4, 4, 4, 3, 5 };

const uint8_t maxX = 24;
const uint8_t maxY = 8;

const uint8_t matrixWidth = maxX + 1;
const uint8_t matrixHeight = maxY + 1;

void xyTest() {
  static uint8_t x = 0;
  static uint8_t y = 0;

  EVERY_N_MILLIS(255 - speed) {
    x++;
    if(x > maxX) {
      x = 0;
      y++;
      if(y > maxY) {
        y = 0;
      }
    }
    
    FastLED.clear();

    CHSV color = CHSV(gHue, 255, 255);
    
    for(uint8_t i = 0; i < NUM_LEDS; i++) {
      uint8_t cx = coordsX[i];
      uint8_t cy = coordsY[i];
      
      if(cx == x && cy == y) {
        leds[i] = color;
      }
    }
  }
}

void xPalette() {
  uint8_t hues = 8;

  for (uint8_t i = 0; i < NUM_LEDS; i++) {
    uint8_t x = coordsX[i];

    leds[i] = ColorFromPalette(palettes[currentPaletteIndex], beat8(speed) - (x * hues));
  }
}

void yPalette() {
  uint8_t hues = 8;

  for (uint8_t i = 0; i < NUM_LEDS; i++) {
    uint8_t y = coordsY[i];

    leds[i] = ColorFromPalette(palettes[currentPaletteIndex], beat8(speed) - (y * hues));
  }
}

void xyPalette() {
  uint8_t hues = 8;

  for (uint8_t i = 0; i < NUM_LEDS; i++) {
    uint8_t x = coordsX[i];
    uint8_t y = coordsY[i];

    leds[i] = ColorFromPalette(palettes[currentPaletteIndex], beat8(speed) - ((x + y) * hues));
  }
}

void xGradientPalette() {
  uint8_t hues = 8;
  
  for (uint8_t i = 0; i < NUM_LEDS; i++) {
    uint8_t x = coordsX[i];

    leds[i] = ColorFromPalette(currentPalette, beat8(speed) - (x * hues));
  }
}

void yGradientPalette() {
  uint8_t hues = 8;
  
  for (uint8_t i = 0; i < NUM_LEDS; i++) {
    uint8_t y = coordsY[i];

    leds[i] = ColorFromPalette(currentPalette, beat8(speed) - (y * hues));
  }
}

void xyGradientPalette() {
  uint8_t hues = 8;
  
  for (uint8_t i = 0; i < NUM_LEDS; i++) {
    uint8_t x = coordsX[i];
    uint8_t y = coordsY[i];

    leds[i] = ColorFromPalette(currentPalette, beat8(speed) - ((x + y) * hues));
  }
}
