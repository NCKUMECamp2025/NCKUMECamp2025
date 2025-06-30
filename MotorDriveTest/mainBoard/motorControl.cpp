#include "motorControl.h"
#include <Arduino.h>

// 直走
void forward(int motorspeed)
{
    //左後輪正轉
    digitalWrite(LEFT1, HIGH);
    digitalWrite(LEFT2, LOW);
    analogWrite(LEFT_PWM, motorspeed);
    //右後輪正轉
    digitalWrite(RIGHT1, HIGH);
    digitalWrite (RIGHT2, LOW);
    analogWrite(RIGHT_PWM, motorspeed);

    //左前輪正轉
    digitalWrite(LEFT3, HIGH);
    digitalWrite(LEFT4, LOW);
    analogWrite(LEFT2_PWM, motorspeed);
    //右前輪正轉
    digitalWrite(RIGHT3, HIGH);
    digitalWrite (RIGHT4, LOW);
    analogWrite(RIGHT2_PWM, motorspeed);
}

// 後退
void backward(int motorspeed)
{
  //左後輪
  digitalWrite(LEFT1, LOW);
  digitalWrite(LEFT2, HIGH);
  analogWrite(LEFT_PWM, motorspeed);
  //右後輪
  digitalWrite(RIGHT1, LOW);
  digitalWrite (RIGHT2, HIGH);
  analogWrite(RIGHT_PWM, motorspeed);

  //左前輪
  digitalWrite(LEFT3, LOW);
  digitalWrite(LEFT4, HIGH);
  analogWrite(LEFT2_PWM, motorspeed);
  //右前輪
  digitalWrite(RIGHT3, LOW);
  digitalWrite (RIGHT4, HIGH);
  analogWrite(RIGHT2_PWM, motorspeed);
}

// 左平移(左前、右後輪往後,右前、左後輪往前)
void turnLeft1(int motorspeed)
{
  //左後輪
  digitalWrite(LEFT1, HIGH);
  digitalWrite(LEFT2, LOW);
  analogWrite(LEFT_PWM, motorspeed);
  //右後輪
  digitalWrite(RIGHT1, LOW);
  digitalWrite (RIGHT2, HIGH);
  analogWrite(RIGHT_PWM, motorspeed);

  //左前輪
  digitalWrite(LEFT3, LOW);
  digitalWrite(LEFT4, HIGH);
  analogWrite(LEFT2_PWM, motorspeed);
  //右前輪
  digitalWrite(RIGHT3, HIGH);
  digitalWrite (RIGHT4, LOW);
  analogWrite(RIGHT2_PWM, motorspeed);
}

// 右平移(左前、右後輪往前,右前、左後輪往後)
void turnRight1(int motorspeed)
{
  //左後輪
  digitalWrite(LEFT1, LOW);
  digitalWrite(LEFT2, HIGH);
  analogWrite(LEFT_PWM, motorspeed);
  //右後輪
  digitalWrite(RIGHT1, HIGH);
  digitalWrite (RIGHT2, LOW);
  analogWrite(RIGHT_PWM, motorspeed);

  //左前輪
  digitalWrite(LEFT3, HIGH);
  digitalWrite(LEFT4, LOW);
  analogWrite(LEFT2_PWM, motorspeed);
  //右前輪
  digitalWrite(RIGHT3, LOW);
  digitalWrite (RIGHT4, HIGH);
  analogWrite(RIGHT2_PWM, motorspeed);
}

// 左前斜移(左前、右後輪不動,右前、左後輪往前)
void turnLeft2(int motorspeed)
{
  //左後輪
  digitalWrite(LEFT1, HIGH);
  digitalWrite(LEFT2, LOW);
  analogWrite(LEFT_PWM, motorspeed);
  //右後輪
  analogWrite(RIGHT_PWM, 0);

  //左前輪
  analogWrite(LEFT2_PWM, 0);
  //右前輪
  digitalWrite(RIGHT3, HIGH);
  digitalWrite (RIGHT4, LOW);
  analogWrite(RIGHT2_PWM, motorspeed);
}

// 右前斜移(左前、右後輪往前,右前、左後輪不動)
void turnRight2(int motorspeed)
{

  //左後輪
  analogWrite(LEFT_PWM, 0);
  //右後輪
  digitalWrite(RIGHT1, HIGH);
  digitalWrite (RIGHT2, LOW);
  analogWrite(RIGHT_PWM, motorspeed);

  //左前輪
  digitalWrite(LEFT3, HIGH);
  digitalWrite(LEFT4, LOW);
  analogWrite(LEFT2_PWM, motorspeed);
  //右前輪
  analogWrite(RIGHT2_PWM, 0);
}

// 左前迴旋(左前、左後輪往後,右前、右後輪不動)
void turnLeft3(int motorspeed)
{
  //左後輪
  digitalWrite(LEFT1, LOW);
  digitalWrite(LEFT2, HIGH);
  analogWrite(LEFT_PWM, motorspeed);
  //右後輪
  analogWrite(RIGHT_PWM, 0);

  //左前輪
  digitalWrite(LEFT3, LOW);
  digitalWrite(LEFT4, HIGH);
  analogWrite(LEFT2_PWM, motorspeed);
  //右前輪
  analogWrite(RIGHT2_PWM, 0);
}

// 右前迴旋(左前、左後輪往前,右前、右後輪不動)
void turnRight3(int motorspeed)
{
  //左後輪
  digitalWrite(LEFT1, HIGH);
  digitalWrite(LEFT2, LOW);
  analogWrite(LEFT_PWM, motorspeed);
  //右後輪
  analogWrite(RIGHT_PWM, 0);

  //左前輪
  digitalWrite(LEFT3, HIGH);
  digitalWrite(LEFT4, LOW);
  analogWrite(LEFT2_PWM, motorspeed);
  //右前輪
  analogWrite(RIGHT2_PWM, 0);
}

// 左後迴旋(左前輪往後,右前輪往前,左後、右後輪不動)
void turnLeft4(int motorspeed)
{
  //左後輪
  analogWrite(LEFT_PWM, 0);
  //右後輪
  analogWrite(RIGHT_PWM, 0);

  //左前輪
  digitalWrite(LEFT3, LOW);
  digitalWrite(LEFT4, HIGH);
  analogWrite(LEFT2_PWM, motorspeed);
  //右前輪
  digitalWrite(RIGHT3, HIGH);
  digitalWrite (RIGHT4, LOW);
  analogWrite(RIGHT2_PWM, motorspeed);
}

// 右後迴旋(左前輪往前,右前輪往後,左後、右後輪不動)
void turnRight4(int motorspeed)
{
  //左後輪
  analogWrite(LEFT_PWM, 0);
  //右後輪
  analogWrite(RIGHT_PWM, 0);

  //左前輪
  digitalWrite(LEFT3, HIGH);
  digitalWrite(LEFT4, LOW);
  analogWrite(LEFT2_PWM, motorspeed);
  //右前輪
  digitalWrite(RIGHT3, LOW);
  digitalWrite (RIGHT4, HIGH);
  analogWrite(RIGHT2_PWM, motorspeed);
}

// 逆時針迴旋(左前、左後輪往後,右前、右後輪往前)
void cycleLeft(int motorspeed)
{
  //左後輪
  digitalWrite(LEFT1, LOW);
  digitalWrite(LEFT2, HIGH);
  analogWrite(LEFT_PWM, motorspeed);
  //右後輪
  digitalWrite(RIGHT1, HIGH);
  digitalWrite (RIGHT2, LOW);
  analogWrite(RIGHT_PWM, motorspeed);

  //左前輪
  digitalWrite(LEFT3, LOW);
  digitalWrite(LEFT4, HIGH);
  analogWrite(LEFT2_PWM, motorspeed);
  //右前輪
  digitalWrite(RIGHT3, HIGH);
  digitalWrite (RIGHT4, LOW);
  analogWrite(RIGHT2_PWM, motorspeed);
}

// 順時針迴旋(左前、左後輪往前,右前、右後輪往後)
void cycleRight(int motorspeed)
{
  //左後輪
  digitalWrite(LEFT1, HIGH);
  digitalWrite(LEFT2, LOW);
  analogWrite(LEFT_PWM, motorspeed);
  //右後輪
  digitalWrite(RIGHT1, LOW);
  digitalWrite (RIGHT2, HIGH);
  analogWrite(RIGHT_PWM, motorspeed);

  //左前輪
  digitalWrite(LEFT3, HIGH);
  digitalWrite(LEFT4, LOW);
  analogWrite(LEFT2_PWM, motorspeed);
  //右前輪
  digitalWrite(RIGHT3, LOW);
  digitalWrite (RIGHT4, HIGH);
  analogWrite(RIGHT2_PWM, motorspeed);
}

// 停車
void stopMotor() 
{
  analogWrite(LEFT_PWM, 0);
  analogWrite(RIGHT_PWM, 0);
}