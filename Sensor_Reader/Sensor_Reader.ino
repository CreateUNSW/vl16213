/*-- Define Pins --*/
#define LIM 1018 //The point at which the sensor switches between touch and release
#define BOUNCE_TIME 100 //Number of Cycles to debounce

/*-- Set up Variables --*/
int Pins[16] = {A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15};
int Bounce;
double LastTime;
int maxIndex;
int lastMax;
int temp;

int Map[16] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
int Sense[16] = {1018,1018,1018,1018,1018,1018,1018,1018,1018,1018,1018,1018,1018,1018,1018};

void setup() {
  /*-- Set Analog Pins --*/
  for (int i = 0; i < 16; i++){
    pinMode(Pins[i], INPUT);  //set analog pins for input
    digitalWrite(Pins[i], HIGH);  //Pull up analog pins
    Bounce = 0;
    LastTime = 0;
    lastMax = LIM;
    maxIndex = -1;
    temp = 0;
  }
  
  /*-- Set up Serial --*/
  Serial.begin(115200);
}

void loop() {
  if(Bounce == 0){ //if 300ms since last touch
    for(int i = 0; i < 16; i++){      //cycle through pins
      temp = analogRead(Pins[i]);
      
      Serial.print("BoxIndex: ");
      Serial.print(Map[i]);        //Send information on pin touched
      Serial.print("          Pressure: ");
      Serial.println(temp);
      
      if(temp < Sense[i]){  //Check if the sensor has detected touch
          if(temp < lastMax){   //if touch greater than the last maximum 
            maxIndex = Map[i]; //save pin index
            lastMax = temp;  //save pressure
          }
      }
    }
    
    Bounce = 1; //set debounce
    LastTime = millis();  //save last time since bounced

    Serial.println("max box = "); //
    Serial.println(maxIndex);
    maxIndex = -1;  //reset maxIndex to something random
    lastMax = LIM;
  } else {
      if((millis() - LastTime)> BOUNCE_TIME){
        Bounce = 0;
      }
  }
}  
