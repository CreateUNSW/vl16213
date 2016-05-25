/*-- Define Pins --*/
#define LIM 1015  //The point at which the sensor switches between touch and release
#define BOUNCE 30

/*-- Set up Variables --*/
double States[16]; //set states to off
int Pins[16] = {A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15};

void setup() {
  /*-- Set Analog Pins --*/
  for (int i = 0; i < 16; i++){
    pinMode(Pins[i], INPUT);  //set analog pins for input
    digitalWrite(Pins[i], HIGH);  //Pull up analog pins
    states[i] = 0;
  }
  
  /*-- Set up Serial --*/
  Serial.begin(115200);
  
  for(int i = 0; i < 16; i++){      //cycle through pins
    for(int j = 0; j<1000; j++){
      states[i] += analogRead(Pins[i]); //read 100 times
      delay(100);
    }
    Serial.print((states[i]/1000)-5); //print average minus 5 to create a baseline sensitivity
    Serial.print(",");
  }
}

void loop() {
  
}
