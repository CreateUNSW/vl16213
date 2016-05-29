// minimum amount of movement between readings to be counted as a "hit"
#define THRESH 100

// array for storing the previous reading history
int readings[16];

int currReading;

void setup() {
  // start serial communication from arduino to teensy
  Serial.begin(9600);
  delay(1000);
  // initialise state of all readings
  for(int i = 0; i < 16; ++i){
    readings[i] = analogRead(i);
  }
}

void loop() {
  // read through all 16 sensors
  for(byte i  = 0; i < 16; ++i){
    // get a sensor reading
    currReading = analogRead(i);

    /**SPECIAL CASES FOR CERTAIN SIDES, FAULTY SENSORS**/
    // bad sensor on back side
    /*if(i == 5){
      continue;
    }*/
    // bad sensor on the front side
    /*if (i == 10){
      continue;
    }*/

    // if the sensor movement is above the threshold
    if(abs(currReading-readings[i]) > THRESH){
      // send the sensor number to the Teensy
      Serial.write(i);
      // wait for vibration to subside
      delay(500);
      // reinitialise readings in all sensors
      for(int j = 0; j < 16; ++j){
        readings[j] = analogRead(j);
      }
    } else {
      // otherwise, update history
      readings[i] = currReading;
    }
  }
}
