#include <Adafruit_NeoPixel.h>
#include <avr/power.h>

#define NUMPIXELS 45 

#define RED 0
#define BLUE 1
#define YELLOW 2
#define WHITE 3

byte pixelMatrix[22][NUMPIXELS][3];


void setup() {
    randomSeed(analogRead(A0));
    delay(1000);
    setupStrips();
    /*
    block(0, 1, 7, 15, 125, 0, 0);
    block(8, 1, 19, 15, 125, 125, 0);
    block(0, 17, 3, 26, 125, 125, 125);
    block(8, 10, 13, 21, 0, 0, 125);     
    block(0, 27, 3, 44, 125, 125, 125);
    block(8, 23, 13, 36, 125, 125, 125);
    block(4, 17, 7, 21, 125, 0, 0);
    block(8, 38, 12, 44, 0, 0, 125);
    block(4, 22, 7, 26, 125, 0, 0);
    block(14, 10, 17, 15, 125, 125, 0);
    block(4, 28, 7, 36, 0, 0, 125);
    block(14, 17, 17, 36, 125, 125, 125);
    block(4, 38, 7, 44, 125, 0, 0);
    block(13, 38, 17, 44, 0, 0, 125);
    block(18, 1, 21, 15, 125, 125, 125);
    block(18, 17, 21, 31, 125, 0, 0);
    block(18, 33, 21, 44, 125, 125, 0);
    */
}

void loop() {
    /*
     block(0,1,4,11,random(4));
     block(0,12,4,23,random(4));
     block(0,24,4,34,random(4));
     block(0,36,4,45,random(4));
     
     block(5,1,9,11,random(4));
     block(5,12,9,23,random(4));
     block(5,24,9,34,random(4));
     block(5,36,9,45,random(4));
    
     block(10,1,14,11,random(4));
     block(10,12,14,23,random(4));
     block(10,24,14,34,random(4));
     block(10,36,14,45,random(4));
    
     block(15,1,19,11,random(4));
     block(15,12,19,23,random(4));
     block(15,24,19,34,random(4));
     block(15,36,19,45,random(4));
     *//*
     block(0, 1, 7, 15, random(4));
    block(8, 1, 19, 15, random(4));
    block(0, 17, 3, 26, random(4));
    block(8, 10, 13, 21, random(4));     
    block(0, 27, 3, 44, random(4));
    block(8, 23, 13, 36, random(4));
    block(4, 17, 7, 21, random(4));
    block(8, 38, 12, 44, random(4));
    block(4, 22, 7, 26, random(4));
    block(14, 10, 17, 15, random(4));
    block(4, 28, 7, 36, random(4));
    block(14, 17, 17, 36, random(4));
    block(4, 38, 7, 44, random(4));
    block(13, 38, 17, 44, random(4));
    block(18, 1, 21, 15, random(4));
    block(18, 17, 21, 31, random(4));
    block(18, 33, 21, 44, random(4));
     */

     /*block(0,0,9,4,random(4));
 block(0,6,9,14,random(4));
 block(0,15,4,26,random(4));
 block(5,15,9,22,random(4));
 
 block(5,23,9,26,random(4));
 block(0,28,9,31,random(4));
 block(0,32,9,35,random(4));
 block(0,37,3,44,random(4));

 block(4,37,12,44,random(4));
 block(10,0,14,4,random(4));
 block(10,6,15,26,random(4));
 block(10,28,12,35,random(4));

 block(13,28,15,38,random(4));
 block(13,40,19,44,random(4));
 block(15,0,19,4,random(4));
 block(16,6,19,19,random(4));

 block(16,21,19,33,random(4));
 block(16,36,19,38,random(4));*/
 block(0, 0, 6, 13, random(4));
    block(0, 14, 6, 20, random(4));
    block(0, 22, 3, 29, random(4));
    block(4, 22, 10, 25, random(4));     
    block(4, 26, 10, 29, random(4));
    block(0, 30, 5, 36, random(4));
    block(0, 38, 9, 44, random(4));
    block(7, 0, 10, 8, random(4));
    block(7, 10, 10, 21, random(4));
    block(6, 30, 14, 37, random(4));
    block(11, 0, 21, 6, random(4));
    block(10, 38, 14, 44, random(4));
    block(11, 7, 14, 21, random(4));
    block(11, 22, 16, 29, random(4));
    block(15, 7, 19, 14, random(4));
    block(20, 7, 21, 16, random(4));
    block(15, 15, 21, 21, random(4));  
    block(17, 22, 21, 29, random(4));  
    block(15, 30, 21, 44, random(4)); 
     writeStrips(pixelMatrix);
     delay(20000);
}
/*
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
*/
void block(int X, int Y, int Length, int Height, byte colour){
  uint16_t x, y;
  byte R, G, B;
  switch (colour) {
    case RED:
        R = 90;
        G = 0;
        B = 0;
        break;
    case BLUE:
        R = 0;
        G = 0;
        B = 90;
        break;
    case YELLOW:
        R = 90;
        G = 90;
        B = 0;    
        break;
    case WHITE:
        R = 90;
        G = 90;
        B = 90;    
        break;
    default:
        R = 0;
        G = 0;
        B = 0;
  }
  for(x = X;  x<=Length; x++){
    for(y = Y; y<=Height; y++){
      pixelMatrix[x][y][0] = R;
      pixelMatrix[x][y][1] = G;
      pixelMatrix[x][y][2] = B;
    }
  } 
}

