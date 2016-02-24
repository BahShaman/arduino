int LED1 = 5; 
int LED2 = 6; 
int LED3 = 7; 
int LED4 = 8; 
int howBright1;  
int howBright2;
int howBright3;
int howBright4;
int count;
int flickerOn;
int lightup;
int lastlightup;

void setup()
{ 
  count=0;
  flickerOn=0;
  lightup=LED1;
  lastlightup=LED4;
  Serial.begin(9600);
  Serial.println("starting up");
}

void loop() 
{ 
  String sLoop = "";
  sLoop = "loop" + count;
  Serial.println(sLoop);
  //Serial.flush();
  count++;
  if(count>1){
    count=0;
    if(flickerOn==0){
      reset();
      flickerOn=1;
    }else{
      reset();
      flickerOn=0;
    }  
  }
  
  if(flickerOn==1){
    flicker() ;
  }else{
    stepThrough(8);
  }
}

void reset(){
  analogWrite(LED1, 0); 
  analogWrite(LED2, 0); 
  analogWrite(LED3, 0); 
  analogWrite(LED4, 0); 
}

void flicker(){
  int cnt=0;
  while(cnt<100){
    howBright1 = random(0,255);     
    analogWrite(LED1, howBright1); 
    howBright2 = random(0,255);     
    analogWrite(LED2, howBright2); 
    howBright3 = random(0,255);     
    analogWrite(LED3, howBright3); 
    howBright4 = random(0,255);     
    analogWrite(LED4, howBright4); 
    delay(random(50,150)); 
    Serial.print("flicker ");
    Serial.println(cnt);
    cnt++;
  }
}

void stepThrough(int times){
  int cnt=0;
  while(cnt<times){
   if(lightup>LED4){
      lightup=LED1;
    }
    analogWrite(lastlightup,0);
    analogWrite(lightup,255);
    lastlightup=lightup;
    lightup++;
    delay(1000);
    cnt++;
  }
}
