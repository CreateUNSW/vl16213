#include <Adafruit_NeoPixel.h>
#include <avr/power.h>
#include "Blocks.h"

#define NUMPIXELS 45 
#define NUMBLOCKS 19
int numBlocks = 16;

typedef enum {FRONT, LEFT, RIGHT, BACK} side_t;
side_t side = RIGHT;

#define RED 0
#define BLUE 1
#define YELLOW 2
#define WHITE 3

byte pixelMatrix[22][NUMPIXELS][3];

byte redArray[4] =    {125, 125,  125,  0};
byte greenArray[4] =  {125, 125,  0,    0};
byte blueArray[4] =   {125,   0,  0,  255};

blockVar blocks[NUMBLOCKS];

void setup() {
  randomSeed(analogRead(A0));
  
 //Front
 if(side == FRONT){
   blocks[0] = {0,1,4,11,0};
   blocks[1] = {0,12,4,23,1};
   blocks[2] = {0,24,4,34,2};
   blocks[3] = {0,36,4,45,3};
   
   blocks[4] = {5,1,9,11,0};
   blocks[5] = {5,12,9,23,1};
   blocks[6] = {5,24,9,34,3};
   blocks[7] = {5,36,9,45,4};
  
   blocks[8] = {10,1,14,11,0};
   blocks[9] = {10,12,14,23,1};
   blocks[10] = {10,24,14,34,2};
   blocks[11] = {10,36,14,45,3};
  
   blocks[12] = {15,1,19,11,0};
   blocks[13] = {15,12,19,23,1};
   blocks[14] = {15,24,19,34,3};
   blocks[15] = {15,36,19,45,4};
 }
 
  //right
  else if(side == RIGHT){
    blocks[0] = {0, 0, 6, 13, 0};
    blocks[1] = {0, 14, 6, 20, 1};
    blocks[2] = {0, 22, 3, 29, 2};
    blocks[3] = {4, 22, 10, 25, 3};     
    blocks[4] = {4, 26, 10, 29, 1};
    blocks[5] = {0, 30, 5, 36, 2};
    blocks[6] = {0, 38, 9, 44, 3};
    blocks[7] = {7, 0, 10, 8, 1};
    blocks[8] = {7, 10, 10, 21, 2};
    blocks[9] = {6, 30, 14, 37, 3};
    blocks[10] = {11, 0, 21, 6, 1};
    blocks[11] = {10, 38, 14, 44, 0};
    blocks[12] = {11, 7, 14, 21, 2};
    blocks[13] = {11, 22, 16, 29, 3};
    blocks[14] = {15, 7, 19, 14, 0};
    blocks[15] = {20, 7, 21, 16, 1};
    blocks[16] = {15, 15, 21, 21, 2};  
    blocks[17] = {17, 22, 21, 29, 3};  
    blocks[18] = {15, 30, 21, 44, 1};
    numBlocks = 19;
  }
  
  // Left
  else if(side == LEFT){
    blocks[0] = {0, 1, 7, 15, 1};
    blocks[1] = {8, 1, 19, 15, 2};
    blocks[2] = {0, 17, 3, 26, 3};
    blocks[3] = {8, 10, 13, 21, 1};     
    blocks[4] = {0, 27, 3, 44, 0};
    blocks[5] = {8, 23, 13, 36, 1};
    blocks[6] = {4, 17, 7, 21, 2};
    blocks[7] = {8, 38, 12, 44, 3};
    blocks[8] = {4, 22, 7, 26, 1};
    blocks[9] = {14, 10, 17, 15, 0};
    blocks[10] = {4, 28, 7, 36, 1};
    blocks[11] = {14, 17, 17, 36, 2};
    blocks[12] = {4, 38, 7, 44, 3};
    blocks[13] = {13, 38, 17, 44, 3};
    blocks[14] = {18, 1, 21, 15, 0};
    blocks[15] = {18, 17, 21, 31, 1};
    blocks[16] = {18, 33, 21, 44, 2};
    numBlocks = 17;
  }

  //back
  else {
    blocks[0] = {0,0,9,4,0};
    blocks[1]={0,6,9,14,1};
    blocks[2]={0,15,4,26,2};
    blocks[3]={5,15,9,22,3};
    
    blocks[4]={5,23,9,26,1};
    blocks[5]={0,28,9,31,0};
    blocks[6]={0,32,9,35,3};
    blocks[7]={0,37,3,44,4};
    
    blocks[8]={4,37,12,44,0};
    blocks[9]={10,0,14,4,2};
    blocks[10]={10,6,15,26,1};
    blocks[11]={10,28,12,35,3};
    
    blocks[12]={13,28,15,38,1};
    blocks[13]={13,40,19,44,0};
    blocks[14]={15,0,19,4,3};
    blocks[15]={16,6,19,19,2};
    
    blocks[16]={16,21,19,33,2};
    blocks[17]={16,36,19,38,1};
    numBlocks = 18;
  }
 
  delay(1500);
  setupStrips();
  Serial.begin(9600);
  Serial1.begin(9600);
}

void loop() {
  //writeStrips(pixelMatrix);
  Serial.println("waiting");    
  while(!Serial1.available()){}
  Serial.println("received");
  byte i = Serial1.read();
  Serial.println((int)i);
  if( i < numBlocks ){
    blocks[i].curColour = (blocks[i].curColour+1)%4;
    block(blocks[i].x,blocks[i].y,blocks[i].xEnd,blocks[i].yEnd,blocks[i].curColour);
  }
}

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

