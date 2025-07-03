#include <Arduino.h>

#ifndef MOTOR_CONTROL
#define MOTOR_CONTROL

// Right Rear
#define RIGHT1 8
#define RIGHT2 13
#define RIGHT_PWM 9
// Left Rear
#define LEFT1 12
#define LEFT2 11
#define LEFT_PWM 10

// Right front
#define RIGHT3 2
#define RIGHT4 4
#define RIGHT2_PWM 3
// Left front
#define LEFT3 5
#define LEFT4 7
#define LEFT2_PWM 6

void LF(String, int);
void RF(String, int);
void LR(String, int);
void RR(String, int);

void forward(int); //直走
void backward(int); //後退
void turnLeft1(int); //左平移
void turnRight1(int); //右平移
void turnLeft2(int); //左前移動
void turnRight2(int); //右前移動
void turnLeft3(String, int); //左迴旋
void turnRight3(String, int); //右迴旋
void cycleLeft(int); //逆時針迴旋
void cycleRight(int); //順時針迴旋
void stopMotor();

void set();
#endif