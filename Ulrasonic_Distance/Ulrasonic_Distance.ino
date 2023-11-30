/* Description:
 * 
 *    This code will measure the distance of the object in front of the HC-SR04 ultrasonic distance sensor, then
 *    print out the distance in cm in the serial monitor. 
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

////////////////////////////////////////////// Libraries ////////////////////////////////////////////
#include <NewPing.h>  // Library to use the distance sensor. Documentation: https://bitbucket.org/teckel12/arduino-new-ping/wiki/Home

////////////////////////////////////////// Pin Definitions //////////////////////////////////////////
#define TRIGGER_PIN 2     // Pin that the trigger pin on the HC-SR04 is connected to
#define ECHO_PIN 3        // Pin that the echo pin on the HC-SR04 is connected to

/////////////////////////////////// Sonar Configuration Variables ///////////////////////////////////
#define MAX_DIST  300     // The maximum distance in centimeters that the sensor will try to measure. Anything greater than 300cm will return as 300cm
#define ITERATIONS 5      // The library will take multiple measurements then return the median value to reduce outliers.
                          // The ITERATION variable sets the number of measurements taken before the median is calculated.

/////////////////////////////////////////// Data Variables //////////////////////////////////////////
int distance;             // The variable that stores the measured distance value

///////////////////////////////////////////// Sonar Stuff////////////////////////////////////////////
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DIST);   // Initializes the sensor at the pins specified earlier. Also specifies the maximum distance the sensor will try to measure.

/////////////////////////////////////////// Initialization //////////////////////////////////////////
void setup() {
  Serial.begin(9600);     // Initializes the serial port at a speed of 9600 baud. This is done so we can receive information from the Arduino.
}

////////////////////////////////////////////// Main Loop ////////////////////////////////////////////
void loop() {
  distance = sonar.ping_median(ITERATIONS);   // Sends out multiple pings (Number of pings equals the ITERATIONS variable), then calculates the median value.
                                              // This will give the measured time for the ping to return in microseconds. This does not give a reading in a length unit.

  distance = sonar.convert_cm(distance);      // This converts the distance from time to a length unit, more specifically centimeters in this case.

  Serial.println(distance);     // Prints the measured distance to the serial monitor
}
