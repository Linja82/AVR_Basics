/* Description:
 * 
 * This code will measure the distance of the object in front of the HC-SR04 ultrasonic distance sensor, then
 * print out the distance in cm in the serial monitor. 
 * 
 * Notes: 
 * 
 *    The NewPing library will not work with the following libraries/functions 
 *    (These are just the issues I found, there may be more)
 *        noTone()
 *        tone()
 *        Volume library by Connor Nishijima
 *
 *    This example specifically uses the HC-SR04 Ultrasonic module
 *
 * Wiring:
 *    HC-SR04:            Arduino:
 *    
 *      GND                 GND
 *      TRIG                2
 *      ECHO                3
 *      VCC                 5V
 */ 

#include <NewPing.h>

// Pin definitions
#define TRIGGER_PIN 2     // Pin that the trigger pin on the HC-SR04 is connected to
#define ECHO_PIN 3        // Pin that the echo pin on the HC-SR04 is connected to

#define MAX_DIST  300     // The maximum distance in centimeters that the sensor will try to measure. Anything greater than 300cm will return as 300cm
#define ITERATIONS 5      // The library will take multiple measurements then return the median value to reduce outliers.
                          // The ITERATION variable sets the number of measurements taken before the median is calculated.

// Data variables
int distance;             // The variable that stores the measured distance value

void setup() {
  Serial.begin(9600);     // Initializes the serial port at a speed of 9600 baud. This is done so we can receive information from the Arduino.
}

void loop() {

}
