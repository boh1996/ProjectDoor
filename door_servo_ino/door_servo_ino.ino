#include <Servo.h>

Servo doorServo;
int doorServoPin = 12;
int redLedPin = 11;
int sensorValue = 0;

void setup () {
   Serial.begin(9600);
   doorServo.attach(doorServoPin);
}

void loop () {
  if ( Serial.availanle > 0 ) {
    sensorValue = Serial.read();
    
    if (
  }
}
