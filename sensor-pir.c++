// C++ code
//

int ledVerde = 5;
int ledVermelho = 3;
int sensor = 2;
int piezo = 4;
int deteccao = 0;

void setup()
{
  pinMode(ledVerde, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(sensor, INPUT);    
  Serial.begin(9600);        
}

void loop()
{
	deteccao = digitalRead(sensor);
      if(deteccao == HIGH) {
        digitalWrite(ledVerde, LOW);
        digitalWrite(ledVermelho, HIGH);
      
       
        deteccao = digitalRead(sensor);
         if(deteccao == LOW) {
          digitalWrite(ledVerde, HIGH);
          digitalWrite(ledVermelho, LOW);
         }
      } 
  
  
 
  }