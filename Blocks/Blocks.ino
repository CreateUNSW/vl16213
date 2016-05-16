#include <Adafruit_NeoPixel.h>
#include <avr/power.h>

#define BLOC
#define NUMPIXELS 45 

byte pixelMatrix[20][NUMPIXELS][3];
//byte *pointer = &pixelMatrix;
//*(pointer+3) = 4;

int a[10];

void setup() {
 setupStrips();
 //Serial.begin(115200);

 //pinMode(13,OUTPUT);
 //digitalWrite(13,HIGH);
}

void loop() {

 block(0,0,9,4,125,0,0);
 block(0,6,9,14,125,125,125);
 block(0,15,4,26,0,0,125);
 block(5,15,9,22,125,125,0);
 
 block(5,23,9,26,125,125,125);
 block(0,28,9,31,0,0,125);
 block(0,32,9,35,125,0,0);
 block(0,37,3,44,125,125,0);

 block(4,37,12,44,125,0,0);
 block(10,0,14,4,125,125,0);
 block(10,6,15,26,0,0,125);
 block(10,28,12,35,125,125,125);

 block(13,28,15,38,0,0,150);
 block(13,40,19,44,0,0,150);
 block(15,0,19,4,150,150,150);
 block(16,6,19,19,150,0,0);

 block(16,21,19,33,150,150,150);
 block(16,36,19,38,150,0,0);
/*    
 block(0,2,4,11,125,0,0);
 block(0,13,4,23,125,125,125);
 block(0,24,4,34,0,0,125);
 block(0,36,4,45,125,125,0);
 
 block(5,2,9,11,125,125,125);
 block(5,13,9,23,0,0,125);
 block(5,24,9,34,125,0,0);
 block(5,36,9,45,125,125,0);

 block(10,2,14,11,125,0,0);
 block(10,13,14,23,125,125,0);
 block(10,24,14,34,0,0,125);
 block(10,36,14,45,125,125,125);

 block(15,2,19,11,0,0,150);
 block(15,13,19,23,0,0,150);
 block(15,24,19,34,150,150,150);
 block(15,36,19,45,150,0,0);
*/
 writeStrips(pixelMatrix);
 //delay(20);
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

