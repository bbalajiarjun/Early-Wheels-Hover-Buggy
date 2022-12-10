#include <Servo.h>
Servo Forward_Left;
Servo Forward_Right;
char Incoming_value = 0;
int pc_Flag = 0;

int y; // value from the analog pin
int x;
int dZone = 15;
char pcinput;
void setup() {
// Attach the ESC on pin 9
Serial.begin(9600);
Forward_Left.attach(9,1000,2000);
Forward_Right.attach(10,1000,2000);
}
void loop() {
BT();
if(pc_Flag == 0){
y = analogRead(A0);
x = analogRead(A1);
// reads the value of the potentiometer (value between 0 and 1023)
y = map(y, 0, 1023, 0, 180);
x = map(x, 0, 1023, 0, 180);// scale it to use it with the servo library (value between 0 and 180)
// Send the signal to the ESC

if(x > 180 - dZone){//Left
Forward_Left.write(30);
Forward_Right.write(0);

}else if(x < dZone){//Right
Forward_Left.write(0);
Forward_Right.write(30);

}else if(y > 180 - dZone){//Forward
Forward_Left.write(y-140);
Forward_Right.write(y-140);

}else if(y < dZone){ //Supposed to be backwards
Forward_Left.write(0);
Forward_Right.write(0);

}else{
Forward_Left.write(0);
Forward_Right.write(0);

}
  }
  else if(pc_Flag == 1){
Forward_Left.write(0);
Forward_Right.write(0);
  }
}

//Bluetooth function 
void BT()
{
  if(Serial.available() > 0)  
  {
    Incoming_value = Serial.read();     
    if(Incoming_value == '1') {
      pc_Flag = 1;
    }
    if(Incoming_value == '0') {
      pc_Flag = 0;
  }
  }                        
}                