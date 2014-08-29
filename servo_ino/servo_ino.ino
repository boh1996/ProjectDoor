#include <Servo.h>

Servo servo;

int pin = 12;
int value;
int amount = 1;

void setup () {
  Serial.begin(9600);
  servo.attach(pin);
}

void loop () {
  value = value + amount;
   
  if ( value == 180 || value == 0 ) {
    amount = -amount;
  }
  
  if ( value == 90 || value == 0 ) {
     digitalWrite(11, 255);
     delay(50);
     digitalWrite(11, 0);
  }
  
  Serial.println(value);
   
  servo.write(value);
  delay(25); 
}
