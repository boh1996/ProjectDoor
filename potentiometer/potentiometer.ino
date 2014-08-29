#include <Servo.h>

// The servo - duh?
Servo servo;

// The pin at which the servo is located (digital)
int servoPin = 12;

// The pin at which the potentiometer is located (analogIn)
int potentiometerPin = 0;

// The pin at which the LED is located (digital, PWM)
int ledPin = 11;

int buzzerPin = 10;

void setup () {
  // Initialize serial
  Serial.begin(9600);
  // Initialize the servo
  servo.attach(servoPin);
  // Initialize the LED
  pinMode(ledPin, OUTPUT);
  // Initialize the buzzer
  pinMode(buzzerPin, OUTPUT);
}

void loop () {
  // Read the potentiometer
  int potentiometerValue = analogRead(0);
  // Potentiometer ranges from 0 to 1023, and the servo from 0 to 179
  // In order to allow more fine grained control over the servo,
  // We limit it from 50 to 130
  int servoValue = map(potentiometerValue, 0, 1023,50, 130);
  // Likewise, the LED ranges from 0 to 250
  // We'll have to half the value and then make it always positive
  // As the servo is stopped halfways, so should our LED be - not lit
  int ledValue = abs(map(potentiometerValue, 0, 1023,0, 255) - 135);
  if (ledValue > 110) {
    digitalWrite(buzzerPin, HIGH);
  } else {
    digitalWrite(buzzerPin, LOW);
  }
 
  Serial.println(temp);
  // Write to the servo
  servo.write(servoValue);
  // Weite to the LED
  analogWrite(ledPin, ledValue);
  // Delay to prevent spam
  delay(1000); 
}
