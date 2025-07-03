#include "sensorSetting.h"

void set()
{
    pinMode(TRIG, OUTPUT);
    pinMode(ECHO, INPUT);

    pinMode(S0, OUTPUT);
    pinMode(S1, OUTPUT);
    pinMode(S2, OUTPUT);
    pinMode(S3, OUTPUT);
    pinMode(OUT, INPUT);
    digitalWrite(S0, HIGH);
    digitalWrite(S1, LOW);
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

int getColor(bool s2Val, bool s3Val)
{
    digitalWrite(S2, s2Val);
    digitalWrite(S3, s3Val);
    delay(10);
    
    return pulseIn(OUT, LOW); // 感測顏色強度（數值越小表示頻率越高 → 顏色越強） 
}