int LED1 = 5; 
int LED2 = 6; 
int LED3 = 7; 
int LED4 = 8; 
int LED5 = 9; 
byte ledup;
char p;

void setup(){
  Serial.begin(9600);
  Serial.println("hello world");
  reset();
  ledup = LED1;
  messages();
}

void loop(){
  if(Serial.available()>0){
     p = Serial.read();
     Serial.write(p);
  }
}

void messages(){
  Serial.println("messages");
  byte mybit;
  mybit=B00100111;
  Serial.println(mybit); 
}

void set()

void reset(){
  analogWrite(LED1, 0); 
  analogWrite(LED2, 0); 
  analogWrite(LED3, 0); 
  analogWrite(LED4, 0); 
  analogWrite(LED5, 0); 
}
