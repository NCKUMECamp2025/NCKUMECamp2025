#include "motorControl.h"
#include <Arduino.h>

void LF(String dir, int speed)
{
  if (dir == "+")
  {
    digitalWrite(LEFT3, HIGH);
    digitalWrite(LEFT4, LOW);
    analogWrite(LEFT2_PWM, speed);
  }
  else if (dir == "-")
  {
    digitalWrite(LEFT3, LOW);
    digitalWrite(LEFT4, HIGH);
    analogWrite(LEFT2_PWM, speed);
  }
  else
  {
    digitalWrite(LEFT3, LOW);
    digitalWrite(LEFT4, LOW);
  }
}

void RF(String dir, int speed)
{
  if (dir == "+")
  {
    digitalWrite(RIGHT3, HIGH);
    digitalWrite(RIGHT4, LOW);
    analogWrite(RIGHT2_PWM, speed);
    //analogWrite(RIGHT2_PWM, motorspeed*0.6);
  }
  else if (dir == "-")
  {
    digitalWrite(RIGHT3, LOW);
    digitalWrite(RIGHT4, HIGH);
    analogWrite(RIGHT2_PWM, speed);
    //analogWrite(RIGHT2_PWM, motorspeed*0.6);
  }
  else
  {
    digitalWrite(RIGHT3, LOW);
    digitalWrite(RIGHT4, LOW);
  }
}

void LR(String dir, int speed)
{
  if (dir == "+")
  {
    digitalWrite(LEFT1, HIGH);
    digitalWrite(LEFT2, LOW);
    analogWrite(LEFT_PWM, speed);
  }
  else if (dir == "-")
  {
    digitalWrite(LEFT1, LOW);
    digitalWrite(LEFT2, HIGH);
    analogWrite(LEFT_PWM, speed);
  }
  else
  {
    digitalWrite(LEFT1, LOW);
    digitalWrite(LEFT2, LOW);
  }
}

void RR(String dir, int speed)
{
  if (dir == "+")
  {
    digitalWrite(RIGHT1, HIGH);
    digitalWrite(RIGHT2, LOW);
    analogWrite(RIGHT_PWM, speed);
  }
  else if (dir == "-")
  {
    digitalWrite(RIGHT1, LOW);
    digitalWrite(RIGHT2, HIGH);
    analogWrite(RIGHT_PWM, speed);
  }
  else
  {
    digitalWrite(RIGHT1, LOW);
    digitalWrite(RIGHT2, LOW);
  }
}

// 直走
void forward(int speed)
{
  //左後輪正轉
  LR("+", speed);
  //右後輪正轉
  RR("+", speed);
  //左前輪正轉
  LF("+", speed);
  //右前輪正轉
  RF("+", speed);
}

// 後退
void backward(int speed)
{
  //左後輪反轉
  LR("-", speed);
  //右後輪反轉
  RR("-", speed);
  //左前輪反轉
  LF("-", speed);
  //右前輪反轉
  RF("-", speed);
}

// 左平移(左前、右後輪往後,右前、左後輪往前)
void turnLeft1(int speed)
{
  //左後輪正轉
  LR("+", speed);
  //右後輪反轉
  RR("-", speed);
  //左前輪反轉
  LF("-", speed);
  //右前輪正轉
  RF("+", speed);
}

// 右平移(左前、右後輪往前,右前、左後輪往後)
void turnRight1(int speed)
{
  //左後輪反轉
  LR("-", speed);
  //右後輪正轉
  RR("+", speed);
  //左前輪正轉
  LF("+", speed);
  //右前輪反轉
  RF("-", speed);
}

// 左前斜移(左前、右後輪不動,右前、左後輪往前)
void turnLeft2(int speed)
{
  //左後輪正轉
  LR("+", speed);
  //右後輪不動
  RR("", 0);
  //左前輪不動
  LF("", 0);
  //右前輪正轉
  RF("+", speed);
}

// 右前斜移(左前、右後輪往前,右前、左後輪不動)
void turnRight2(int speed)
{

  //左後輪不動
  LR("", 0);
  //右後輪正轉
  RR("+", speed);
  //左前輪正轉
  LF("+", speed);
  //右前輪不動
  RF("", 0);
}

// 左迴旋 前(左前、左後輪不動,右前、右後輪往前) 後(左前、左後輪不動,右前、右後輪往後)
void turnLeft3(String dir, int speed)
{
  //左後輪不動
  LR("", 0);
  //右後輪轉
  RR(dir, speed);
  //左前輪不動
  LF("", 0);
  //右前輪轉
  RF(dir, speed);
}

// 右迴旋 前(左前、左後輪往前,右前、右後輪不動) 後(左前、左後輪往後,右前、右後輪不動) 
void turnRight3(String dir, int speed)
{
  //左後輪轉
  LR(dir, speed);
  //右後輪不動
  RR("", 0);
  //左前輪轉
  LF(dir, speed);
  //右前輪不動
  RF("", 0);
}

// 逆時針迴旋(左前、左後輪往後,右前、右後輪往前)
void cycleLeft(int speed)
{
  //左後輪反轉
  LR("-", speed);
  //右後輪正轉
  RR("+", speed);
  //左前輪反轉
  LF("-", speed);
  //右前輪正轉
  RF("+", speed);
}

// 順時針迴旋(左前、左後輪往前,右前、右後輪往後)
void cycleRight(int speed)
{
  //左後輪正轉
  LR("+", speed);
  //右後輪反轉
  RR("-", speed);
  //左前輪正轉
  LF("+", speed);
  //右前輪反轉
  RF("-", speed);
}

// 停車
void stopMotor() 
{
  analogWrite(LEFT_PWM, 0);
  analogWrite(RIGHT_PWM, 0);
  analogWrite(LEFT2_PWM, 0);
  analogWrite(RIGHT2_PWM, 0);
}

void set()
{
  pinMode(LEFT1, OUTPUT);
  pinMode(LEFT2, OUTPUT);
  pinMode(LEFT_PWM, OUTPUT);
  pinMode(RIGHT1, OUTPUT);
  pinMode(RIGHT2, OUTPUT);
  pinMode(RIGHT_PWM, OUTPUT);
  
  pinMode(LEFT3, OUTPUT);
  pinMode(LEFT4, OUTPUT);
  pinMode(LEFT2_PWM, OUTPUT);
  pinMode(RIGHT3, OUTPUT);
  pinMode(RIGHT4, OUTPUT);
  pinMode(RIGHT2_PWM, OUTPUT);
}