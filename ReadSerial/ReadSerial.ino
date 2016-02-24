
int LED1 = 5; 
int LED2 = 6; 
int LED3 = 7; 
int LED4 = 8; 
int LED5 = 9; 

int x;
char p, *l;
int ledup;

void setup(){
  Serial.begin(9600);
  Serial.println("hello world");
  reset();
  ledup = LED1;
}

void loop(){
  if(Serial.available()>0){
     p = Serial.read();
     Serial.println(p);
     if(ledup>LED5){
        ledup=LED1;
      }
     if(p=='S'){
       ledup=LED5;
     }else{
       if(p=='1'){
         analogWrite(ledup,255);
       }else{
         analogWrite(ledup,0);
       }
     }
     ledup++;
     delay(10);
  }
 
}

void reset(){
  analogWrite(LED1, 0); 
  analogWrite(LED2, 0); 
  analogWrite(LED3, 0); 
  analogWrite(LED4, 0); 
  analogWrite(LED5, 0); 
}
