#define THRESH 100
#define THRESH_TIME 1500

int readings[16];
long times[16];
int currReading;
boolean detect[16];

// 5 not sensitive enough

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(1000);
  for(int i = 0; i < 16; ++i){
    readings[i] = analogRead(i);
    detect[i] = false;
    times[i] = millis();
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for(byte i  = 0; i < 16; ++i){
    currReading = analogRead(i);
    if(abs(currReading-readings[i]) > THRESH){
      //if(millis() - times[i] > THRESH_TIME){
        detect[i] = true;
        //Serial.println((int)i+1);
        Serial.write(i+1);
        delay(500);
        for(int j = 0; j < 16; ++j){
          readings[j] = analogRead(j);
        }
      //}
    } else {
      detect[i] = false;
      readings[i] = currReading;
    }
  }
}
