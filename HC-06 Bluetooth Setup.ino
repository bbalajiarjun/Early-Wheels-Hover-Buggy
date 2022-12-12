//Code adopted from milliohm.com
//https://miliohm.com/spp-c-and-hc-05-bluetooth-module-with-arduino-tutorial/
//Follow video if you need help

//Hover Buggy Bluetooth Setup:
//In the serial monitor of the Arduino IDE Type in the following commands:
//AT+NAME=hover buggy switch 
//AT+PIN=0000 
#include <SoftwareSerial.h> 
SoftwareSerial mySerial(3, 4); //Rx,Tx 
void setup() { 
  // put your setup code here, to run once: 
  Serial.begin(9600); 
  mySerial.begin(9600); 
} 

void loop() { 
  if (mySerial.available()) { 
    Serial.write(mySerial.read()); 
  } 
  if (Serial.available()) { 
    mySerial.write(Serial.read()); 
  } 
} 