#include <SoftwareSerial.h>

int LeftValue;

SoftwareSerial softSerial(2, 3); // RX, TX

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  softSerial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (softSerial.available())
  {
    String str = softSerial.readStringUntil('\n'); // 讀到換行結束
    LeftValue = str.toInt();
    Serial.println(LeftValue);
  }
  if (LeftValue > 600)
  {
    digitalWrite(13, HIGH);
    Serial.println("HIGH");
  }
  else
  {
    digitalWrite(13, LOW);
    Serial.println("LOW");
  }
  delay(1000);
}
