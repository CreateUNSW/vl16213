#include "Arduino.h"
#include <Adafruit_NeoPixel.h>

#define NUMPIXELS 45    

#define STRIP1 2
#define STRIP2 3
#define STRIP3 4
#define STRIP4 5
#define STRIP5 6
#define STRIP6 7
#define STRIP7 8
#define STRIP8 9
#define STRIP9 10

#define STRIP10 11
#define STRIP11 12
#define STRIP12 13
#define STRIP13 14
#define STRIP14 15
#define STRIP15 16
#define STRIP16 17

#define STRIP17 18
#define STRIP18 19
#define STRIP19 20
#define STRIP20 21
#define STRIP21 22
#define STRIP22 23



Adafruit_NeoPixel strip_1 = Adafruit_NeoPixel(NUMPIXELS, STRIP1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip_2 = Adafruit_NeoPixel(NUMPIXELS, STRIP2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip_3 = Adafruit_NeoPixel(NUMPIXELS, STRIP3, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip_4 = Adafruit_NeoPixel(NUMPIXELS, STRIP4, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip_5 = Adafruit_NeoPixel(NUMPIXELS, STRIP5, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip_6 = Adafruit_NeoPixel(NUMPIXELS, STRIP6, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip_7 = Adafruit_NeoPixel(NUMPIXELS, STRIP7, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip_8 = Adafruit_NeoPixel(NUMPIXELS, STRIP8, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip_9 = Adafruit_NeoPixel(NUMPIXELS, STRIP9, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip_10 = Adafruit_NeoPixel(NUMPIXELS, STRIP10, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip_11 = Adafruit_NeoPixel(NUMPIXELS, STRIP11, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip_12 = Adafruit_NeoPixel(NUMPIXELS, STRIP12, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip_13 = Adafruit_NeoPixel(NUMPIXELS, STRIP13, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip_14 = Adafruit_NeoPixel(NUMPIXELS, STRIP14, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip_15 = Adafruit_NeoPixel(NUMPIXELS, STRIP15, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip_16 = Adafruit_NeoPixel(NUMPIXELS, STRIP16, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip_17 = Adafruit_NeoPixel(NUMPIXELS, STRIP17, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip_18 = Adafruit_NeoPixel(NUMPIXELS, STRIP18, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip_19 = Adafruit_NeoPixel(NUMPIXELS, STRIP19, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip_20 = Adafruit_NeoPixel(NUMPIXELS, STRIP20, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip_21 = Adafruit_NeoPixel(NUMPIXELS, STRIP21, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip_22 = Adafruit_NeoPixel(NUMPIXELS, STRIP22, NEO_GRB + NEO_KHZ800);


void setupStrips(){
  strip_1.begin();
  strip_2.begin();
  strip_3.begin();
  strip_4.begin();
  strip_5.begin();
  strip_6.begin();
  strip_7.begin();
  strip_8.begin();
  strip_9.begin();
  strip_10.begin();
  strip_11.begin();
  strip_12.begin();
  strip_13.begin();
  strip_14.begin();
  strip_15.begin();
  strip_16.begin();
  strip_17.begin();
  strip_18.begin();
  strip_19.begin();
  strip_20.begin();
  strip_21.begin();
  strip_22.begin();  
}

void writeStrips(byte pixelMatrix[22][NUMPIXELS][3]){
  
  for(int i=0;i<NUMPIXELS;i++){strip_1.setPixelColor(i, strip_1.Color(pixelMatrix[0][i][0],pixelMatrix[0][i][1],pixelMatrix[0][i][2]));}
  strip_1.show();
  
  for(int i=0;i<NUMPIXELS;i++){strip_2.setPixelColor(i, strip_2.Color(pixelMatrix[1][i][0],pixelMatrix[1][i][1],pixelMatrix[1][i][2]));}
  strip_2.show();
  
  for(int i=0;i<NUMPIXELS;i++){strip_3.setPixelColor(i, strip_3.Color(pixelMatrix[2][i][0],pixelMatrix[2][i][1],pixelMatrix[2][i][2]));}
  strip_3.show();
  
  for(int i=0;i<NUMPIXELS;i++){strip_4.setPixelColor(i, strip_4.Color(pixelMatrix[3][i][0],pixelMatrix[3][i][1],pixelMatrix[3][i][2]));}
  strip_4.show();
  
  for(int i=0;i<NUMPIXELS;i++){strip_5.setPixelColor(i, strip_5.Color(pixelMatrix[4][i][0],pixelMatrix[4][i][1],pixelMatrix[4][i][2]));}
  strip_5.show();
  
  for(int i=0;i<NUMPIXELS;i++){strip_6.setPixelColor(i, strip_6.Color(pixelMatrix[5][i][0],pixelMatrix[5][i][1],pixelMatrix[5][i][2]));}
  strip_6.show();
  
  for(int i=0;i<NUMPIXELS;i++){strip_7.setPixelColor(i, strip_7.Color(pixelMatrix[6][i][0],pixelMatrix[6][i][1],pixelMatrix[6][i][2]));}
  strip_7.show();
  
  for(int i=0;i<NUMPIXELS;i++){strip_8.setPixelColor(i, strip_8.Color(pixelMatrix[7][i][0],pixelMatrix[7][i][1],pixelMatrix[7][i][2]));}
  strip_8.show();
  
  for(int i=0;i<NUMPIXELS;i++){strip_9.setPixelColor(i, strip_9.Color(pixelMatrix[8][i][0],pixelMatrix[8][i][1],pixelMatrix[8][i][2]));}
  strip_9.show();
  
  for(int i=0;i<NUMPIXELS;i++){strip_10.setPixelColor(i, strip_10.Color(pixelMatrix[9][i][0],pixelMatrix[9][i][1],pixelMatrix[9][i][2]));}
  strip_10.show();
  
  for(int i=0;i<NUMPIXELS;i++){strip_11.setPixelColor(i, strip_11.Color(pixelMatrix[10][i][0],pixelMatrix[10][i][1],pixelMatrix[10][i][2]));}
  strip_11.show();
  
  for(int i=0;i<NUMPIXELS;i++){strip_12.setPixelColor(i, strip_12.Color(pixelMatrix[11][i][0],pixelMatrix[11][i][1],pixelMatrix[11][i][2]));}
  strip_12.show();
  
  for(int i=0;i<NUMPIXELS;i++){strip_13.setPixelColor(i, strip_13.Color(pixelMatrix[12][i][0],pixelMatrix[12][i][1],pixelMatrix[12][i][2]));}
  strip_13.show();
  
  for(int i=0;i<NUMPIXELS;i++){strip_14.setPixelColor(i, strip_14.Color(pixelMatrix[13][i][0],pixelMatrix[13][i][1],pixelMatrix[13][i][2]));}
  strip_14.show();
  
  for(int i=0;i<NUMPIXELS;i++){strip_15.setPixelColor(i, strip_15.Color(pixelMatrix[14][i][0],pixelMatrix[14][i][1],pixelMatrix[14][i][2]));}
  strip_15.show();
  
  for(int i=0;i<NUMPIXELS;i++){strip_16.setPixelColor(i, strip_16.Color(pixelMatrix[15][i][0],pixelMatrix[15][i][1],pixelMatrix[15][i][2]));}
  strip_16.show();

  for(int i=0;i<NUMPIXELS;i++){strip_17.setPixelColor(i, strip_17.Color(pixelMatrix[16][i][0],pixelMatrix[16][i][1],pixelMatrix[16][i][2]));}
  strip_17.show();

  for(int i=0;i<NUMPIXELS;i++){strip_18.setPixelColor(i, strip_18.Color(pixelMatrix[17][i][0],pixelMatrix[17][i][1],pixelMatrix[17][i][2]));}
  strip_18.show();
  
  for(int i=0;i<NUMPIXELS;i++){strip_19.setPixelColor(i, strip_19.Color(pixelMatrix[18][i][0],pixelMatrix[18][i][1],pixelMatrix[18][i][2]));}
  strip_19.show();

  for(int i=0;i<NUMPIXELS;i++){strip_20.setPixelColor(i, strip_20.Color(pixelMatrix[19][i][0],pixelMatrix[19][i][1],pixelMatrix[19][i][2]));}
  strip_20.show();
  
  for(int i=0;i<NUMPIXELS;i++){strip_21.setPixelColor(i, strip_21.Color(pixelMatrix[20][i][0],pixelMatrix[20][i][1],pixelMatrix[20][i][2]));}
  strip_21.show();
  
  for(int i=0;i<NUMPIXELS;i++){strip_22.setPixelColor(i, strip_22.Color(pixelMatrix[21][i][0],pixelMatrix[21][i][1],pixelMatrix[21][i][2]));}
  strip_22.show();
}

