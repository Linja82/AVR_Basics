#include <Servo.h>

Servo servo1;

int servo1_pin = 9;           // The PWM pin that the signal pin of the servo is connected to
int incoming_position = 0;  
bool return_to_zero = true;

void setup() {
  Serial.begin(9600);
  servo1.attach(servo1_pin);
}

void loop() {
  while (Serial.available() == 0){}
    incoming_position = Serial.parseInt();
    if (incoming_position == -1)
    {
      if (return_to_zero)
      {
        Serial.println("Return to zero is OFF");
        return_to_zero = false;
      }
      else
      {
        Serial.println("Return to zero is ON");
        return_to_zero = true;
      }
    }
    else
    {
      // Move servo to desired position
      Serial.println(incoming_position);
      servo1.write(incoming_position);
  
      // Return to zero
      if (return_to_zero)
      {
        delay(1000);
        incoming_position = 0;
        servo1.write(incoming_position);
      }
    }
}
