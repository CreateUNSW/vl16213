/*-- Define Variables --*/
#define BOUNCE_TIME 1500 //Number of milliseconds to debounce

/*-- Set up Variables --*/
int bounce = 0;
double nextTime = 0;
int maxIndex = -1;
int lastMax = 0;
int temp = 0;
int value = 0;

/*-- Sey up Arrays --*/
int pins[16] = {A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15};
int box[16] =   {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
int sense[16] = {1010,1010,1010,1010,1010,1010,1010,1010,1010,1010,1010,1020,1010,1010,1010};

void setup() {
  /*-- Set Analog Pins --*/
  for (int i = 0; i < 16; i++){
    pinMode(pins[i], INPUT);  //set analog pins for input
    digitalWrite(pins[i], HIGH);  //Pull up analog pins
  }
  
  /*-- Set up Serial --*/
  Serial.begin(9600);
}

void loop() {
  if(bounce == 0){ //if 300ms since last touch
    for(int i = 0; i < 16; i++){      //cycle through pins
      temp = analogRead(pins[i]);

      /*
      Serial.print("BoxIndex: ");
      Serial.print(box[i]);        //Send information on pin touched
      Serial.print("          Pressure: ");
      Serial.println(temp);
      */
      
      if(temp < sense[i]) {  //Check if the sensor has detected touch
        value = sense[i] - temp;
        if(value > lastMax){   //if touch greater than the last maximum 
          maxIndex = box[i]; //save pin index
          lastMax = value;  //save pressure
        }
        bounce = 1; //set debounce
        nextTime = millis() + BOUNCE_TIME;  //save time at which checking restarts
      }
    }
    

    //Serial.println("max box = "); //
    if(maxIndex!=-1 ){
      Serial.println(maxIndex);
    }
    maxIndex = -1;  //reset maxIndex to something random
    lastMax = 0;
  } else {
    if(millis() > nextTime){
      bounce = 0;
    }
  }
}  
