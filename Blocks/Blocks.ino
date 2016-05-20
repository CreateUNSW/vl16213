#include <Adafruit_NeoPixel.h>
#include <avr/power.h>

#define NUMPIXELS 45 

byte pixelMatrix[22][NUMPIXELS][3];
//byte *pointer = &pixelMatrix;
//*(pointer+3) = 4;

int a[10];

void setup() {
 delay(1000);
 setupStrips();
 //Serial.begin(115200);
}

void loop() {
    writeStrips(pixelMatrix);
}

void block(int X, int Y, int Length, int Height, byte R, byte G, byte B){
  uint16_t x, y;
  for(x = X;  x<=Length; x++){
    for(y = Y; y<=Height; y++){
      pixelMatrix[x][y][0] = R;
      pixelMatrix[x][y][1] = G;
      pixelMatrix[x][y][2] = B;
    }
  } 
}

