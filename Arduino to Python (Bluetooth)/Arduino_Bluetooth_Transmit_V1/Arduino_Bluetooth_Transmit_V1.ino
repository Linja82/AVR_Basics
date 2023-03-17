#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11);

float count = 0;

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
}

void loop() {
  Serial.println("Sensor 1: " + String(count));
  mySerial.println("Sensor 1: " + String(count));
  count++;
  delay(1000);
}
