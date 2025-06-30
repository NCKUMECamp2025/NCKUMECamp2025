// #include <SoftwareSerial.h>
#include <Ultrasonic.h>

Ultrasonic ultrasonic(12, 13);

const int LeftSensorPin = A0;
const int RightSensorPin = A1;

// SoftwareSerial softSerial(2, 3); // RX, TX

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  // softSerial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int Left = analogRead(LeftSensorPin);
  int Right = analogRead(RightSensorPin);
  int Distance = ultrasonic.read();
  String color = "White";

  Serial.print("L:"); Serial.print(Left); Serial.print(";");
  Serial.print("R:"); Serial.print(Right); Serial.print(";");
  Serial.print("D:"); Serial.print(Distance); Serial.print(";");
  Serial.print("C:"); Serial.print(color); Serial.print(";");
  Serial.println();
  
  /*
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
  */

  // delay(1000);
}
