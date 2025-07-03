#include "sensorSetting.h"

String color;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  set();
}

void loop() {
  // put your main code here, to run repeatedly:
  int Left = analogRead(LPin);
  int Right = analogRead(RPin);
  // int Distance = ultrasonic.read();
  int Distance = ultraDis();

  int red = getColor(LOW, LOW);     // 紅色：S2=LOW, S3=LOW
  int green = getColor(HIGH, HIGH); // 綠色：S2=HIGH, S3=HIGH
  int blue = getColor(LOW, HIGH);   // 藍色：S2=LOW, S3=HIGH

  if (red < 90 && green < 90 && blue < 90)
    color = "White";
  else if (red > 250 && green > 300 && blue > 200)
    color = "Black";
  else if (red < 70 && green < 110 && blue < 150)
    color = "Yellow";
  else if (red < 100 && green > 100 && blue > 100)
    color = "Red";
  else
    color = "Other";

  Serial.print("L:"); Serial.print(Left); Serial.print(";");
  Serial.print("R:"); Serial.print(Right); Serial.print(";");
  Serial.print("D:"); Serial.print(Distance); Serial.print(";");
  Serial.print("C:"); Serial.print(color); 
  // Serial.print(red); Serial.print(green); Serial.print(blue); Serial.print(";");
  Serial.println();
}
