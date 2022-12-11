#include<Servo.h>

#define ESC_PIN 2

Servo esc;

void setup() 
{
  esc.attach(ESC_PIN, 1000, 2000);
  pinMode(A0, INPUT);
  Serial.begin(9600);
//  esc.write(180);
//  delay(8000);
//  esc.write(10);
//  delay(2000);
//  esc.write(10);  
}

void loop() 
{
  int joystickValue = analogRead(A0);
  joystickValue = constrain(joystickValue, 550, 1023);  //Read upper half of joystick value from center.
  int mmotorSpeed = map(joystickValue, 550, 1023, 0, 180);
  Serial.println(joystickValue);
  esc.write(mmotorSpeed);  
}
