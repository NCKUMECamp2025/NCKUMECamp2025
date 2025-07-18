#include "Arduino.h"
#include <Wire.h>
#include "Adafruit_TCS34725.h"

#ifndef ESP32_SETTING
#define ESP32_SETTING

// Sensor Pin
#define LPin 35 // A0
#define RPin 34 // A1
#define TRIG 5
#define ECHO 18
#define SDA 21
#define SCL 22

// Motor Pin
#define RR1 4
#define RR2 16
#define RR_PWM 15

#define LR1 32
#define LR2 23
#define LR_PWM 13

#define RF1 25
#define RF2 33
#define RF_PWM 12

#define LF1 27
#define LF2 36
#define LF_PWM 14

// Function
void setPin();
int ultraDis();

void LF(String, int);
void RF(String, int);
void LR(String, int);
void RR(String, int);

void forward(int); // move forward
void backward(int); // move backward
void turnLeft1(int); // strafe left
void turnRight1(int); // strafe right
void turnLeft2(int); // move forward-left
void turnRight2(int); // move forward-right
void turnLeft3(String, int); // normal turn left
void turnRight3(String, int); // normal turn right
void cycleLeft(int); // spin ccw in place
void cycleRight(int); // spin cw in place
void stopMotor(); // stop all motors

#endif