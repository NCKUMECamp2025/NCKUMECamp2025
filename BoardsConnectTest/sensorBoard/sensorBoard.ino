#include <SoftwareSerial.h>

const int LeftSensorPin = A0;
const int RightSensorPin = A1;

SoftwareSerial softSerial(2, 3); // RX, TX

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  softSerial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int LeftSensorValue = analogRead(LeftSensorPin);
  int RightSensorValue = analogRead(RightSensorPin);
  softSerial.println(LeftSensorValue);
  
  Serial.print("Left: ");
  // Serial.println(LeftSensorValue);
  if (LeftSensorValue > 600)
    Serial.println("Black");
  else
    Serial.println("White");
  Serial.print("Right: ");
  if (RightSensorValue > 600)
    Serial.println("Black");
  else
    Serial.println("White");
  
  delay(1000);
}
