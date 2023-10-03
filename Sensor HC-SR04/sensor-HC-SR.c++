const int trigger = 7; 
const int echo    = 6; 
const int ledG    = 13;
const int ledY    = 12;
const int ledR    = 11;
const int buzzer  = 10;
float dist = 0;

void setup(){
  Serial.begin(9600);
  pinMode(trigger,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(ledG,OUTPUT);
  pinMode(ledY,OUTPUT);
  pinMode(ledR,OUTPUT);
}
void loop(){
  digitalWrite(trigger,LOW);
  delayMicroseconds(5);        
  digitalWrite(trigger,HIGH);  
  delayMicroseconds(10);      
  digitalWrite(trigger,LOW); 
  
  dist=pulseIn(echo,HIGH);      
  dist = dist/58;                  
  Serial.print ("Distancia = ");
  Serial.print (dist);         
  Serial.print (" cm");         
  Serial.write (10);            
  delay (200); 
  
  float echoRead = analogRead(dist);
  float buzzerPitch = map(dist, 1, 200, 120, 1500);
  
  if (dist < 40){
    digitalWrite(ledR, HIGH);
    digitalWrite(ledG, LOW);
    digitalWrite(ledY, LOW);
    tone(10, buzzerPitch, 1500);
    delay(1);
      }
  else if (dist > 40 && dist < 180){
    digitalWrite(ledY, HIGH);
    digitalWrite(ledG, LOW);
    digitalWrite(ledR, LOW);
    tone(10, buzzerPitch, 200);
    delay(1);
  } else {
    digitalWrite(ledG, HIGH);
    digitalWrite(ledR, LOW);
    digitalWrite(ledY, LOW);
    tone(10, buzzerPitch, 100);
    delay(1);
  }
    delay(100);
}                             



