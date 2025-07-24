#include "ESP32Setting.h"

// 感測器黑線基準值（可微調）
int black = 500;
int baseSpeed = 150;
int avoidspeed = 200;

// PID 參數
float Kp = 0.5;
float Ki = 0.0;
float Kd = 0.25;

float error = 0;
float previousError = 0;
float integral = 0;
float derivative = 0;

int lane = 3;

int tmp = 0;
int pre_dis;

void go_straight();
void avoid_obs();

void setup() {
  Serial.begin(9600);
  setPin();
  pre_dis=0;
}

void loop() {
  
  
  if( tmp == 0 )
  {
    tmp = 1;
    pre_dis = ultraDis();
  }
  
  //int leftSensor = analogRead(LPin);
  //int rightSensor = analogRead(RPin);
  int dis = 0.5*pre_dis + 0.5*ultraDis();
  pre_dis = dis;
  int obs = 30;

  if( dis < obs )
  {
    avoid_obs();
   
  }
  else
  {
    go_straight();
  }
  
}

void avoid_obs()
{

  stopMotor();
  delay(500);

  int r = random(0,100);
  r %= 2;
  if( lane == 1 ) r = 0;
  if( lane == 5 ) r = 1;

  if( r == 0 ) //right
  {
    turnRight2(avoidspeed);
    delay(500);
    while(analogRead(RPin) < black )
    {
      turnRight2(baseSpeed);
      delay(100);
    }

    stopMotor();
    delay(1000);
    lane++;

  }else if( r == 1  ) //left
  {
    turnLeft2(avoidspeed);
    delay(500);
    while(analogRead(LPin) < black )
    {
      turnLeft2(baseSpeed);
      delay(70);
    }

    stopMotor();
    delay(1000);
    lane--;
  }


}

void go_straight()
{
  int leftSensor = analogRead(LPin);
  int rightSensor = analogRead(RPin);
  error = rightSensor - leftSensor;

  // PID 計算
  integral += error;
  derivative = error - previousError;
  previousError = error;

  float correction = Kp * error + Ki * integral + Kd * derivative;

  int leftSpeed = baseSpeed - correction;
  int rightSpeed = baseSpeed + correction;

  leftSpeed = constrain(leftSpeed, 0, 255);
  rightSpeed = constrain(rightSpeed, 0, 255);

  // 控制四輪同步差速前進
  LR("+", leftSpeed);
  RR("+", rightSpeed);
  LF("+", leftSpeed);
  RF("+", rightSpeed);
}
