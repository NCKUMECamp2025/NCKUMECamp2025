#include "motorControl.h"

//設定PWM輸出值(代表的是車子的速度)
int motorspeed = 250;

void setup(){ 
  Serial.begin(9600);
  //設定每一個PIN的模式
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

void loop() {

  forward(motorspeed);

  //backward();

  //turnLeft1();

  //turnRight1();

  //turnLeft2();

  //turnRight2();

  //turnLeft3();

  //turnRight3();

  //turnLeft4();

  //turnRight4();

  //cycleLeft();

  //cycleRight();

  //stopMotor();


  delay(2000);

}