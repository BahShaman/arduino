int LED1 = 3; 
int LED2 = 5; 
int LED3 = 6; 
int LED4 = 9; 
int LED5 = 10; 
int LED6 = 11; 

int pins = 6;

int SerialCommand[6];

int randhigh = 255;
int randlow = 0;

unsigned long timeout = 10000;
unsigned long currentMillis;
unsigned long previousMillis;

void setup(){
  pinMode(LED1, OUTPUT);   // sets the pins as output
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  test();
  reset();
  Serial.begin(38400);
  Serial.println("hello world");
}

void loop(){
  
  currentMillis = millis();
  
  if (Serial.available() >= pins){
    for (int i =0;i<pins;i++){
      SerialCommand[i] = Serial.read();
    }
    Serial.println("resetting");
    previousMillis = currentMillis;   
  }

  if(currentMillis - previousMillis > timeout) {
    for (int i =0;i<pins;i++){
      SerialCommand[i] = random(randlow,randhigh);
    }
    delay(random(100,150));
  }  

  Serial.println(currentMillis);
  Serial.println(previousMillis);

  analogWrite(LED1, SerialCommand[0]);
  analogWrite(LED2, SerialCommand[1]);
  analogWrite(LED3, SerialCommand[2]);
  analogWrite(LED4, SerialCommand[3]);
  analogWrite(LED5, SerialCommand[4]);
  analogWrite(LED6, SerialCommand[5]);
  
}

void reset(){
  analogWrite(LED1, 0);
  analogWrite(LED2, 0);
  analogWrite(LED3, 0);
  analogWrite(LED4, 0);
  analogWrite(LED5, 0);   
  analogWrite(LED6, 0);   
}

void test(){
  //turn them on in order
  analogWrite(LED1, 255);
  delay(250);
  analogWrite(LED2, 255);
  delay(250);
  analogWrite(LED3, 255);
  delay(250);
  analogWrite(LED4, 255);
  delay(250);
  analogWrite(LED5, 255);
  delay(250);
  analogWrite(LED6, 255);
  delay(250);

  reset();
  delay(250);
  
  //all the way up
  for(int k=0;k<255;k++){
    for(int i=0;i<pins;i++){
      SerialCommand[i]=k;
    }
    
    analogWrite(LED1, SerialCommand[0]);
    analogWrite(LED2, SerialCommand[1]);
    analogWrite(LED3, SerialCommand[2]);
    analogWrite(LED4, SerialCommand[3]);
    analogWrite(LED5, SerialCommand[4]);
    analogWrite(LED6, SerialCommand[5]);    
    delay (10);
  }

  //all the way down
  for(int k=255;k>=0;k--){
    for(int i=0;i<pins;i++){
      SerialCommand[i]=k;
    }
    analogWrite(LED1, SerialCommand[0]);
    analogWrite(LED2, SerialCommand[1]);
    analogWrite(LED3, SerialCommand[2]);
    analogWrite(LED4, SerialCommand[3]);
    analogWrite(LED5, SerialCommand[4]);
    analogWrite(LED6, SerialCommand[5]);
    delay(10);
  }
  reset();
}
