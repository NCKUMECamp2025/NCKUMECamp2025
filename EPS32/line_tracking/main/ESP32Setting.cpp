#include "ESP32Setting.h"

void setPin()
{
    pinMode(TRIG, OUTPUT);
    pinMode(ECHO, INPUT);

    pinMode(LR1, OUTPUT);
    pinMode(LR2, OUTPUT);
    pinMode(LR_PWM, OUTPUT);
    pinMode(RR1, OUTPUT);
    pinMode(RR2, OUTPUT);
    pinMode(RR_PWM, OUTPUT);
    pinMode(LF1, OUTPUT);
    pinMode(LF2, OUTPUT);
    pinMode(LF_PWM, OUTPUT);
    pinMode(RF1, OUTPUT);
    pinMode(RF2, OUTPUT);
    pinMode(RF_PWM, OUTPUT);
}

int ultraDis()
{
    long duration, distance;
    digitalWrite(TRIG, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG, LOW);

    duration = pulseIn(ECHO, HIGH);

    distance = duration * 0.034 / 2;

    delay(50);

    return distance;
}

void LF(String dir, int speed)
{
    if (dir == "+")
    {
        digitalWrite(LF1, HIGH);
        digitalWrite(LF2, LOW);
        analogWrite(LF_PWM, speed);
    }
    else if (dir == "-")
    {
        digitalWrite(LF1, LOW);
        digitalWrite(LF2, HIGH);
        analogWrite(LF_PWM, speed);
    }
    else
    {
        digitalWrite(LF1, LOW);
        digitalWrite(LF2, LOW);
    }
}

void RF(String dir, int speed)
{
    if (dir == "+")
    {
        digitalWrite(RF1, HIGH);
        digitalWrite(RF2, LOW);
        analogWrite(RF_PWM, speed);
        //analogWrite(RF_PWM, motorspeed*0.6);
    }
    else if (dir == "-")
    {
        digitalWrite(RF1, LOW);
        digitalWrite(RF2, HIGH);
        analogWrite(RF_PWM, speed);
        //analogWrite(RF_PWM, motorspeed*0.6);
    }
    else
    {
        digitalWrite(RF1, LOW);
        digitalWrite(RF2, LOW);
    }
}

void LR(String dir, int speed)
{
    if (dir == "+")
    {
        digitalWrite(LR1, HIGH);
        digitalWrite(LR2, LOW);
        analogWrite(LR_PWM, speed);
    }
    else if (dir == "-")
    {
        digitalWrite(LR1, LOW);
        digitalWrite(LR2, HIGH);
        analogWrite(LR_PWM, speed);
    }
    else
    {
        digitalWrite(LR1, LOW);
        digitalWrite(LR2, LOW);
    }
}

void RR(String dir, int speed)
{
    if (dir == "+")
    {
        digitalWrite(RR1, HIGH);
        digitalWrite(RR2, LOW);
        analogWrite(RR_PWM, speed);
    }
    else if (dir == "-")
    {
        digitalWrite(RR1, LOW);
        digitalWrite(RR2, HIGH);
        analogWrite(RR_PWM, speed);
    }
    else
    {
        digitalWrite(RR1, LOW);
        digitalWrite(RR2, LOW);
    }
}

// ǐ
void forward(int speed)
{
  //オ近タ锣
  LR("+", speed);
  //近タ锣
  RR("+", speed);
  //オ玡近タ锣
  LF("+", speed);
  //玡近タ锣
  RF("+", speed);
}

// 癶
void backward(int speed)
{
  //オ近は锣
  LR("-", speed);
  //近は锣
  RR("-", speed);
  //オ玡近は锣
  LF("-", speed);
  //玡近は锣
  RF("-", speed);
}

// オキ簿(オ玡近┕,玡オ近┕玡)
void turnLeft1(int speed)
{
  //オ近タ锣
  LR("+", speed);
  //近は锣
  RR("-", speed);
  //オ玡近は锣
  LF("-", speed);
  //玡近タ锣
  RF("+", speed);
}

// キ簿(オ玡近┕玡,玡オ近┕)
void turnRight1(int speed)
{
  //オ近は锣
  LR("-", speed);
  //近タ锣
  RR("+", speed);
  //オ玡近タ锣
  LF("+", speed);
  //玡近は锣
  RF("-", speed);
}

// オ玡弊簿(オ玡近ぃ笆,玡オ近┕玡)
void turnLeft2(int speed)
{
  //オ近タ锣
  LR("+", speed);
  //近ぃ笆
  RR("", 0);
  //オ玡近ぃ笆
  LF("", 0);
  //玡近タ锣
  RF("+", speed);
}

// 玡弊簿(オ玡近┕玡,玡オ近ぃ笆)
void turnRight2(int speed)
{

  //オ近ぃ笆
  LR("", 0);
  //近タ锣
  RR("+", speed);
  //オ玡近タ锣
  LF("+", speed);
  //玡近ぃ笆
  RF("", 0);
}

// オ癹臂 玡(オ玡オ近ぃ笆,玡近┕玡) (オ玡オ近ぃ笆,玡近┕)
void turnLeft3(String dir, int speed)
{
  //オ近ぃ笆
  LR("", 0);
  //近锣
  RR(dir, speed);
  //オ玡近ぃ笆
  LF("", 0);
  //玡近锣
  RF(dir, speed);
}

// 癹臂 玡(オ玡オ近┕玡,玡近ぃ笆) (オ玡オ近┕,玡近ぃ笆) 
void turnRight3(String dir, int speed)
{
  //オ近锣
  LR(dir, speed);
  //近ぃ笆
  RR("", 0);
  //オ玡近锣
  LF(dir, speed);
  //玡近ぃ笆
  RF("", 0);
}

// 癴皐癹臂(オ玡オ近┕,玡近┕玡)
void cycleLeft(int speed)
{
  //オ近は锣
  LR("-", speed);
  //近タ锣
  RR("+", speed);
  //オ玡近は锣
  LF("-", speed);
  //玡近タ锣
  RF("+", speed);
}

// 抖皐癹臂(オ玡オ近┕玡,玡近┕)
void cycleRight(int speed)
{
  //オ近タ锣
  LR("+", speed);
  //近は锣
  RR("-", speed);
  //オ玡近タ锣
  LF("+", speed);
  //玡近は锣
  RF("-", speed);
}

// 氨ó
void stopMotor() 
{
  analogWrite(LR_PWM, 0);
  analogWrite(RR_PWM, 0);
  analogWrite(LF_PWM, 0);
  analogWrite(RF_PWM, 0);
}