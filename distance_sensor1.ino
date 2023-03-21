// C++ code
//
#include<Servo.h>
Servo servo;
#define trig A5
#define echo A2
#define servP 9
long time , dist;
void setup()
{
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
  servo.attach(servP);
}
void loop()
{
  digitalWrite(trig, LOW);
  delay(6);
  digitalWrite(trig, HIGH);
  delayMicroseconds(20);
  digitalWrite(trig ,LOW);
  time = pulseIn(echo , HIGH);
  dist = time / 3/ 32.1;
  Serial.print("Distance is");
  Serial.print(dist);
  unsigned char pos = map(dist , 4,440, 0,130);
  servo.write(pos);
  Serial.print("Position is");
  Serial.println(pos ,DEC);
  delay(1000);
}


