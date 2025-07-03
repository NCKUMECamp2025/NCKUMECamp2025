#include "Arduino.h"

#ifndef SENSOR_SETTING
#define SENSOR_SETTING

#define LPin A0
#define RPin A1
#define TRIG 9
#define ECHO 10

#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define OUT 8

int ultraDis();
int getColor(bool, bool);

void set();

#endif