#include "ESP32Setting.h"

uint16_t Left, Right, Distance, R, G, B, C;

Adafruit_TCS34725 tcs = Adafruit_TCS34725(
    TCS34725_INTEGRATIONTIME_50MS,
    TCS34725_GAIN_4X
);

// vehicle & env setting
uint16_t speed = 150;
uint16_t black = 500; uint16_t yellow = 300;
uint16_t pos = 1; // 0->left 1->mid 2->right
uint16_t ot = 15; // overtake distance :)

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
    if (Distance < ot)
    {
        if (pos++ == 0)
        {
            while (!(Left > black))
            {
                turnRight2(speed);
                delay(50);
            } 
        }
        else if (pos-- == 2)
        {
            while (!(Right > black))
            {
                turnLeft2(speed);
                delay(50);
            } 
        }
        else
        {
            int16_t toward = (random(100) % 2) == 0 ? -1 : 1;
            if (toward == -1)
                while (!(Right > yellow))
                {
                    turnLeft2(speed);
                    delay(50);
                } 
            else
                while (!(Right > black))
                {
                    turnLeft2(speed);
                    delay(50);
                }
            pos += toward;
        }
    }
    else
    {
        if (Left > black || (Left > yellow && Left < black))
        {
            turnRight3("+", speed);
            delay(100);
        }
        else if (Right > black || (Right > yellow && Right < black)) 
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

    Serial.print("Left:"); Serial.print(Left); Serial.print(";");
    Serial.print("Right:"); Serial.print(Right); Serial.print(";");
    Serial.print("Dis:"); Serial.print(Distance); Serial.print(";");
    Serial.print("RGB:"); Serial.print(R); Serial.print(G); Serial.print(B); Serail.println(";");
}
