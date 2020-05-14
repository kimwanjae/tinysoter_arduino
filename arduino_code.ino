#include <Servo.h>
#define OFFMODE -1
#define ONMODE 0
#define BLINKMODE 1

Servo myservo;
const int pinLED = 13;
char ch;
int state = OFFMODE;

void setup() {
  pinMode(pinLED,OUTPUT);
  myservo.attach(9);
  Serial.begin(9600);
}

void loop() {
  if(Serial.available()){
    ch = Serial.read();
  }
  if(ch=='a'){
    digitalWrite(pinLED,HIGH);
    myservo.write(180);
    delay(150);
  }else if(ch=='b'){
    digitalWrite(pinLED,LOW);
    myservo.write(0);
    delay(150);
  }else if(ch=='c'){
    myservo.write(90);
    delay(150);
    digitalWrite(pinLED,LOW);
  }
}
