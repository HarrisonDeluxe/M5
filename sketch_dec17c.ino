// https://okasho-engineer.com/to-processing-from-arduino/

#include <M5StickC.h>
int sendData[5] = {100, 150, 200, 250, 300};
int count = 0;

void setup() {
  M5.begin();
  Serial.begin(9600);
  
}

void loop() {
  for(int i=0; i<5; i++) {
    count = sendData[i];
    Serial.write((byte)(1));          // Dummy data 1
    Serial.write((byte)(200));        // Dummy data 2
    Serial.write((byte)(count>>24));  // [24:31] bit
    Serial.write((byte)(count>>16));  // [16:23] bit
    Serial.write((byte)(count>>8));   // [8:15] bit
    Serial.write((byte)(count));      // [0:7] bit
    delay(500);
  }
 }
