#include <Servo.h> 

Servo servo;

int servoPin = 3;
int pirPin = 4;
int ledV = 2;

int estadoAtualSensor;

void setup()
{
  Serial.begin(9600);
  pinMode(pirPin, INPUT);
  pinMode(ledV, OUTPUT);
  servo.attach(servoPin);
}

void loop(){
  
  int estadoPIR = digitalRead(pirPin);
  
  if(estadoPIR == HIGH) {
    servo.write(180);
    digitalWrite(ledV, HIGH);
    delay(100);
    
 } else {
  	servo.write(0);
    digitalWrite(ledV, LOW);
    delay(100);
  }
}

