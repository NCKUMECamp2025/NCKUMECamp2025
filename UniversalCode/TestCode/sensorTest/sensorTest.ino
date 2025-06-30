// sensorTest
const int LeftSensorPin = A0;
const int RightSensorPin = A1;

int L, R;

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    L = analogRead(LeftSensorPin);
    R = analogRead(RightSensorPin);
    Serial.println("L:" + String(L) + " R:" + String(R));
    delay(50);
}