#include <Servo.h>

Servo doorServo;
int doorServoPin = 12;
int redLedPin = 11;
int sensorValue = 0;

void setup () {
   Serial.begin(9600);
   doorServo.attach(doorServoPin);
   pinMode(redLedPin, OUTPUT);
}

void loop () {
  if ( mySwitch.available() ) {
    Serial.println("Recived");
    sensorValue = 0;
    
    doorServo.write(90);
    
    if ( sensorValue == 2 || sensorValue == 50 ) {
      doorServo.write(180);
      digitalWrite(redLedPin, HIGH);
      delay(3000);
      digitalWrite(redLedPin, LOW);
      delay(100);
      digitalWrite(redLedPin, HIGH);
      delay(100);
      digitalWrite(redLedPin, LOW);
    } else {
       doorServo.write(90);
       digitalWrite(redLedPin, LOW);
    }
  } else {
     doorServo.write(90);
     digitalWrite(redLedPin, LOW);
  }
}
