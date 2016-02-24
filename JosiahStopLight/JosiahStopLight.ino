int LED1 = 5; 
int LED2 = 6; 
int LED3 = 7; 
int LED4 = 8; 
int LED5 = 9; 

void setup(){
  
}

void loop(){
  reset();
  stackLight();
  //otherLight();
  //redLight();
  //greenLight();
  //redLight();
  //greenLight();
}

void reset(){
  analogWrite(LED1, 0); 
  analogWrite(LED2, 0); 
  analogWrite(LED3, 0); 
  analogWrite(LED4, 0); 
  analogWrite(LED5, 0); 
}

void greenLight(){
  reset();
  analogWrite(LED2,255); 
  delay(7000);
}

void redLight(){
  reset();
  analogWrite(LED3,255); 
  delay(2000);
  reset();
  analogWrite(LED4,255);   
  delay(5000);
}

void otherLight(){
  reset(); 
  analogWrite(LED5,10); 
  delay(250);
  reset(); 
  analogWrite(LED1,255); 
  delay(250);
  reset(); 
  analogWrite(LED5,10); 
  delay(250);
  reset(); 
  analogWrite(LED1,255); 
  delay(250);
  reset(); 
  analogWrite(LED5,255); 
  delay(250);
  reset(); 
  analogWrite(LED1,255); 
  delay(250);
  reset(); 
  analogWrite(LED5,255); 
  delay(250);
  reset(); 
  analogWrite(LED1,255); 
  delay(250);
  reset(); 
  analogWrite(LED5,255); 
  delay(250);
  reset(); 
  analogWrite(LED1,255); 
  delay(250);
  reset(); 
  analogWrite(LED5,255); 
  delay(250);
  reset(); 
  analogWrite(LED1,255); 
  delay(250);
  reset(); 
  analogWrite(LED5,255); 
  delay(250);
  reset(); 
  analogWrite(LED1,255); 
  delay(250);
  reset(); 
  analogWrite(LED5,255); 
  delay(250);
  reset(); 
  analogWrite(LED1,255); 
  delay(250);
  reset(); 
  analogWrite(LED5,255); 
  delay(250);
  reset(); 
  analogWrite(LED1,255); 
  delay(250);
  reset(); 
  analogWrite(LED5,255); 
  delay(250);
  reset(); 
  analogWrite(LED1,255); 
  delay(250);
}

void stackLight(){
  for(int i =0;i<255;i++){
    analogWrite(LED5,i); 
    delay(10);
  }
}
