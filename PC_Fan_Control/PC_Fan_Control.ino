/* This code is meant to control 4-pin PWM enables PC Fans
 * 
 * This should work for 5V and 12V fans
 * 
 * This will only work on SAMD21 µControllers. Will not work on an Arduino
 */

#define FANPIN 3         // Pin on the Seeeduino that the fan PWM pin is connected to
#define FREQUENCY 25000  // PWM frequency that the fan needs. Most PC fans use a PWM frequency of 25KHz

int dutyCycle = 500;  // The output duty cycle, sets the speed of the fan. Ranges from 0 - 1024 with 0 being the lowest speed and 1024 being the highest speed

void setup() {
  pwm(FANPIN, FREQUENCY, DUTYCYCLE);
}

void loop() {
  
}