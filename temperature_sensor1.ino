#include<Servo.h>
int pin_temp = A0;
int pin_servo = 9;
Servo myServo;
void setup()
{
  myServo.attach(pin_servo);
  Serial.begin(9600);
  myServo.write(0);
}
void loop()
{
  int analog_value = analogRead(pin_temp);
  float temp = (((analog_value*5.0)/1024.0)-0.5)*100;
  Serial.println(temp);
  if(temp >= 32)
  {
    myServo.write(90);
  }
  else
  {
    myServo.write(0);
  }
  delay(50);
}

