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

void forward(int motorspeed); //直走
void backward(int motorspeed); //後退
void turnLeft1(int motorspeed); //左平移
void turnRight1(int motorspeed); //右平移
void turnLeft2(int motorspeed); //左前移動
void turnRight2(int motorspeed); //右前移動
void turnLeft3(int motorspeed); //左前迴旋
void turnRight3(int motorspeed); //右前迴旋
void turnLeft4(int motorspeed); //左後迴旋
void turnRight4(int motorspeed); //右後迴旋
void cycleLeft(int motorspeed); //逆時針迴旋
void cycleRight(int motorspeed); //順時針迴旋
void stopMotor();

void set();
#endif