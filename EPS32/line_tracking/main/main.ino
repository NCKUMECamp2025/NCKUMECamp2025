#include "ESP32Setting.h"

uint16_t Left, Right, Distance, R, G, B, C;

Adafruit_TCS34725 tcs = Adafruit_TCS34725(
    TCS34725_INTEGRATIONTIME_50MS,
    TCS34725_GAIN_4X
);

// vehicle & env setting
uint16_t speed = 150;
uint16_t black = 500;

void setup()
{
    Serial.begin(9600);

    setPin();

    if (tcs.begin())
        Serial.println("Color sensor connected");
    else
        Serial.println("Fail to connect color sensor");
}

void loop()
{
    // Get sensor data
    Left = analogRead(LPin);
    Right = analogRead(RPin);
    Distance = ultraDis(); // Not used here
    
    tcs.getRawData(&R, &G, &B, &C); // Not used here
    R /= C; G /= C; B /= C; // Not used here

    // Motor control
    if (Left > black)
    {
        turnRight3("+", speed);
        delay(100);
    }
    else if (Right > black) 
    {
        turnLeft3("+", speed);
        delay(100);
    }
    else 
    {
        forward(speed);
        delay(100);
    }
}
