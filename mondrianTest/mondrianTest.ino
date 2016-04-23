#include <Adafruit_NeoPixel.h>
#include <avr/power.h>
#include "map.h"

side panels[FRONT];
byte panelnum = FRONT;

byte mapxy[45][20] = {0};

Adafruit_NeoPixel dots[20] =
{
  Adafruit_NeoPixel(TOTALLEDS,  2, NEO_GRB + NEO_KHZ800),
  Adafruit_NeoPixel(TOTALLEDS,  3, NEO_GRB + NEO_KHZ800),
  Adafruit_NeoPixel(TOTALLEDS,  4, NEO_GRB + NEO_KHZ800),
  Adafruit_NeoPixel(TOTALLEDS,  5, NEO_GRB + NEO_KHZ800),
  Adafruit_NeoPixel(TOTALLEDS,  6, NEO_GRB + NEO_KHZ800),
  Adafruit_NeoPixel(TOTALLEDS,  7, NEO_GRB + NEO_KHZ800),
  Adafruit_NeoPixel(TOTALLEDS,  8, NEO_GRB + NEO_KHZ800),
  Adafruit_NeoPixel(TOTALLEDS,  9, NEO_GRB + NEO_KHZ800),
  Adafruit_NeoPixel(TOTALLEDS, 10, NEO_GRB + NEO_KHZ800),
  Adafruit_NeoPixel(TOTALLEDS, 11, NEO_GRB + NEO_KHZ800),
  Adafruit_NeoPixel(TOTALLEDS, 12, NEO_GRB + NEO_KHZ800),
  Adafruit_NeoPixel(TOTALLEDS, 13, NEO_GRB + NEO_KHZ800),
  Adafruit_NeoPixel(TOTALLEDS, 14, NEO_GRB + NEO_KHZ800),
  Adafruit_NeoPixel(TOTALLEDS, 15, NEO_GRB + NEO_KHZ800),
  Adafruit_NeoPixel(TOTALLEDS, 16, NEO_GRB + NEO_KHZ800),
  Adafruit_NeoPixel(TOTALLEDS, 17, NEO_GRB + NEO_KHZ800),
  Adafruit_NeoPixel(TOTALLEDS, 18, NEO_GRB + NEO_KHZ800),
  Adafruit_NeoPixel(TOTALLEDS, 19, NEO_GRB + NEO_KHZ800),
  Adafruit_NeoPixel(TOTALLEDS, 20, NEO_GRB + NEO_KHZ800),
  Adafruit_NeoPixel(TOTALLEDS, 21, NEO_GRB + NEO_KHZ800)
};

void setup() {
  randomSeed(analogRead(A0));
  for (int i = 0; i < TOTALSTRIPS; i++) {
     dots[i].begin();
     //clears all leds
     dots[i].show(); 
  }
  showMap();
  for (int i = 0; i < panelnum; i++) {
    panels[i].colour = random(0,5);
    switch (panelnum) {
        case FRONT:
            panels[i].sx = front[i].sx;
            panels[i].sy = front[i].sy;
            panels[i].ex = front[i].ex;
            panels[i].ey = front[i].ey;        
        break;
        case LEFT:
            panels[i].sx = front[i].sx;
            panels[i].sy = front[i].sy;
            panels[i].ex = front[i].ex;
            panels[i].ey = front[i].ey;      
        break;
            panels[i].sx = left[i].sx;
            panels[i].sy = left[i].sy;
            panels[i].ex = left[i].ex;
            panels[i].ey = left[i].ey;      
        case RIGHT:
            panels[i].sx = right[i].sx;
            panels[i].sy = right[i].sy;
            panels[i].ex = right[i].ex;
            panels[i].ey = right[i].ey;      
        break;
        case BACK:
            panels[i].sx = back[i].sx;
            panels[i].sy = back[i].sy;
            panels[i].ex = back[i].ex;
            panels[i].ey = back[i].ey;              
        break;
        default:
        ;//do nothing    
    }
  }
  setcol();
  showMap();
}

void loop() {
  // put your main code here, to run repeatedly:

}

void setcol() {
  for (int i = 0; i < panelnum; i++) {
    for (int j = panels[i].sx; j <=panels[i].ex; j++) {
        for (int k = panels[i].sy; k <=panels[i].ey;k++) {
            mapxy[k][j] = panels[i].colour;
        }
    }
  }
}

void showMap() {
  for (int i = 0; i < TOTALSTRIPS; i++) {
    for (int j = 0; j < TOTALLEDS; j++) {
      switch (mapxy[j][i]) {
        case RED: 
            dots[i].setPixelColor(j, dots[i].Color(150,0,0));
            break;
        case BLUE:
            dots[i].setPixelColor(j, dots[i].Color(0,0,150));
            break;
        case YELLOW:
            dots[i].setPixelColor(j, dots[i].Color(150,150,0));
            break;
        case WHITE:
            dots[i].setPixelColor(j, dots[i].Color(125,150,150));
            break;        
        default:
            dots[i].setPixelColor(j, dots[i].Color(0,0,0));
            break;
        }
    }
    dots[i].show();  
  }
}
