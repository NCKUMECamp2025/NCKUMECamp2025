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

// ����
void forward(int speed)
{
  //���������
  LR("+", speed);
  //�k�������
  RR("+", speed);
  //���e������
  LF("+", speed);
  //�k�e������
  RF("+", speed);
}

// ��h
void backward(int speed)
{
  //���������
  LR("-", speed);
  //�k�������
  RR("-", speed);
  //���e������
  LF("-", speed);
  //�k�e������
  RF("-", speed);
}

// ������(���e�B�k�������,�k�e�B��������e)
void turnLeft1(int speed)
{
  //���������
  LR("+", speed);
  //�k�������
  RR("-", speed);
  //���e������
  LF("-", speed);
  //�k�e������
  RF("+", speed);
}

// �k����(���e�B�k������e,�k�e�B���������)
void turnRight1(int speed)
{
  //���������
  LR("-", speed);
  //�k�������
  RR("+", speed);
  //���e������
  LF("+", speed);
  //�k�e������
  RF("-", speed);
}

// ���e�ײ�(���e�B�k�������,�k�e�B��������e)
void turnLeft2(int speed)
{
  //���������
  LR("+", speed);
  //�k�������
  RR("", 0);
  //���e������
  LF("", 0);
  //�k�e������
  RF("+", speed);
}

// �k�e�ײ�(���e�B�k������e,�k�e�B���������)
void turnRight2(int speed)
{

  //���������
  LR("", 0);
  //�k�������
  RR("+", speed);
  //���e������
  LF("+", speed);
  //�k�e������
  RF("", 0);
}

// ���j�� �e(���e�B���������,�k�e�B�k������e) ��(���e�B���������,�k�e�B�k�������)
void turnLeft3(String dir, int speed)
{
  //���������
  LR("", 0);
  //�k�����
  RR(dir, speed);
  //���e������
  LF("", 0);
  //�k�e����
  RF(dir, speed);
}

// �k�j�� �e(���e�B��������e,�k�e�B�k�������) ��(���e�B���������,�k�e�B�k�������) 
void turnRight3(String dir, int speed)
{
  //�������
  LR(dir, speed);
  //�k�������
  RR("", 0);
  //���e����
  LF(dir, speed);
  //�k�e������
  RF("", 0);
}

// ��a�f�ɰw�j��(���e�B���������,�k�e�B�k������e)
void cycleLeft(int speed)
{
  //���������
  LR("-", speed);
  //�k�������
  RR("+", speed);
  //���e������
  LF("-", speed);
  //�k�e������
  RF("+", speed);
}

// ��a���ɰw�j��(���e�B��������e,�k�e�B�k�������)
void cycleRight(int speed)
{
  //���������
  LR("+", speed);
  //�k�������
  RR("-", speed);
  //���e������
  LF("+", speed);
  //�k�e������
  RF("-", speed);
}

// ����
void stopMotor() 
{
  analogWrite(LR_PWM, 0);
  analogWrite(RR_PWM, 0);
  analogWrite(LF_PWM, 0);
  analogWrite(RF_PWM, 0);
}