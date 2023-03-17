float count = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  count = analogRead(A0);
  Serial.println("Sensor 1: " + String(count));
  delay(1000);
}
