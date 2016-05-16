/*-- Define Pins --*/
#define LIM 1015  //The point at which the sensor switches between touch and release
#define BOUNCE 20 //Number of Cycles to debounce

/*-- Set up Variables --*/
boolean States[16]; //set states to off
int Pins[16] = {A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15};
int Bounce[16];

void setup() {
  /*-- Set Analog Pins --*/
  for (int i = 0; i < 16; i++){
    pinMode(Pins[i], INPUT);  //set analog pins for input
    digitalWrite(Pins[i], HIGH);  //Pull up analog pins
    States[i] = false;
    Bounce[i] = 0;
  }
  
  /*-- Set up Serial --*/
  Serial.begin(115200);
}

void loop() {
  for(int i = 0; i < 16; i++){      //cycle through pins
    if(Bounce[i]<1){
      if(analogRead(Pins[i]) < LIM){  //Check if the sensor has detected touch
        if(States[i] != true){        //If sensor has detected touch, was it previously being touched, if not:
          States[i] = true;           //Set up so that it's state is being touched
          Serial.println(i+1);        //Send information on pin touched
          Bounce[i] = BOUNCE;
        }
      } else {                        //If there is no pressure
        States[i] = false;            //Change state to untouched
      }
    }else if(Bounce[i]>1){
      Bounce[i] = Bounce[i] - 1;
    }
  }
}
