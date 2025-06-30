//右後馬達控制設定
const byte RIGHT1 = 8; //IN1
const byte RIGHT2 = 13; //IN2
const byte RIGHT_PWM = 9; //ENA
//右左後馬達控制設定
const byte LEFT1 = 12; //IN3
const byte LEFT2 = 11; //IN4
const byte LEFT_PWM = 10; //ENB

//右前馬達控制設定
const byte RIGHT3 = 2; //IN1
const byte RIGHT4 = 4; //IN2
const byte RIGHT2_PWM = 3; //ENA
//左前馬達控制設定
const byte LEFT3 = 5; //IN3
const byte LEFT4 = 7; //IN4
const byte LEFT2_PWM = 6; //ENB

//設定PWM輸出值(代表的是車子的速度)
byte motorspeed = 250;

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

// 移動函式
void forward(){//前進
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

void backward(){ //後退
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

void turnLeft1(){//左平移(左前、右後輪往後,右前、左後輪往前)
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

void turnRight1(){//右平移(左前、右後輪往前,右前、左後輪往後) , 左平移
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

void turnLeft2(){//左前斜移(左前、右後輪不動,右前、左後輪往前)
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

void turnRight2(){//右前斜移(左前、右後輪往前,右前、左後輪不動) , 左前

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

void turnLeft3(){//左前迴旋(左前、左後輪往後,右前、右後輪不動)
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

void turnRight3(){//右前迴旋(左前、左後輪往前,右前、右後輪不動) , 左前
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

void turnLeft4(){//左後迴旋(左前輪往後,右前輪往前,左後、右後輪不動)
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

void turnRight4(){//右後迴旋(左前輪往前,右前輪往後,左後、右後輪不動) , 左後
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

void cycleLeft(){//逆時針迴旋(左前、左後輪往後,右前、右後輪往前)
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

void cycleRight(){//順時針迴旋(左前、左後輪往前,右前、右後輪往後) , 逆時針
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

void stopMotor() {//停車
  analogWrite(LEFT_PWM, 0);
  analogWrite(RIGHT_PWM, 0);
}


void loop() {

  forward();

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