#include "motorControl.h"

String rawData;
int L, R, D;
String C;

// 設定值
int speed = 150;
int black = 500;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  //設定每一個PIN的模式
  set();
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available())
  {
    rawData = Serial.readStringUntil('\n'); // 讀到換行結束
    L = getValue(rawData, "L:").toInt();
    R = getValue(rawData, "R:").toInt();
    D = getValue(rawData, "D:").toInt();
    C = getValue(rawData, "C:");

    /*
    Serial.print("L:"); Serial.print(L); Serial.print(";");
    Serial.print("R:"); Serial.print(R); Serial.print(";");
    Serial.print("D:"); Serial.print(D); Serial.print(";");
    Serial.print("C:"); Serial.print(C); Serial.print(";");
    Serial.println();
    */
  }

  
  if (L > black) 
  {
    turnRight3("+", speed);
    delay(100);
  }
  else if (R > black) 
  {
    turnLeft3("+", speed);
    delay(100);
  }
  else 
  {
    forward(speed);
    delay(100);
  }
  
 // forward(speed);
  // delay(1000);
}

String getValue(String data, String key) {
  int start = data.indexOf(key);
  if (start == -1) return "";
  start += key.length();
  int end = data.indexOf(";", start);
  if (end == -1) end = data.length();
  return data.substring(start, end);
}
