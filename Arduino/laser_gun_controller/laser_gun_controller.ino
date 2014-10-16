#include <Servo.h>

Servo horizontal, vertical;
#define LASER 11

void setup(){
  horizontal.attach(9);
  vertical.attach(10);
  pinMode(LASER, OUTPUT);
  Serial.begin(9600);
}

void loop(){}

void serialEvent(){
  int h = Serial.parseInt();
  int v = Serial.parseInt();
  int l = Serial.parseInt();
  
  if(Serial.read() == '\n'){
    horizontal.writeMicroseconds(h);
    delay(1);
    vertical.writeMicroseconds(v);
    delay(1);
    digitalWrite(LASER, l);
  }
}
