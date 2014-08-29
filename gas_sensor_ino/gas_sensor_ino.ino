int gasPin = 5;
int redLedPin = 11;
int yellowLedPin = 9;
int buzzerPin = 10;

void setup () {
  Serial.begin(9600);
  pinMode(yellowLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
  
  pinMode(buzzerPin, OUTPUT);
}

void loop () {
  int sensorValue = analogRead(gasPin);
  
  Serial.println(sensorValue);
  
  if ( sensorValue > 850  ) {

    analogWrite(redLedPin, 0);
    analogWrite(yellowLedPin, map(sensorValue, 0, 1000, 0, 255));
  } else {
    analogWrite(redLedPin, 0);
    analogWrite(yellowLedPin, 0); 
  }
  
  if ( sensorValue > 920 ) {
     digitalWrite(buzzerPin, HIGH);
     analogWrite(yellowLedPin, map(sensorValue, 0, 1000, 0, 255));
     analogWrite(redLedPin, map(sensorValue, 0, 1000, 0, 255));
  } else {
     digitalWrite(buzzerPin, LOW); 
  }
  delay(50);
}

