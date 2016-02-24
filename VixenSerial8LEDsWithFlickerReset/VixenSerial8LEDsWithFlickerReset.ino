int LED0 = 2;
int LED1 = 3; 
int LED2 = 5; 
int LED3 = 6; 
int LED4 = 9; 
int LED5 = 10; 
int LED6 = 11;
int LED7 = 12;

int pins = 8;

int SSRELAY_OFF = 0;
int SSRELAY_ON = 255;

int SerialCommand[8];

int randhigh = 2;
int randlow = 0;

int delayhigh = 1000;
int delaylow = 500;

unsigned long timeout = 10000;
unsigned long currentMillis;
unsigned long previousMillis;

void setup(){
  reset();
  pinMode(LED0, OUTPUT);   // sets the pins as output
  pinMode(LED1, OUTPUT);   // sets the pins as output
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  pinMode(LED7, OUTPUT);   // sets the pins as output
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
      if (SerialCommand[i] == 0) {
        SerialCommand[i] = SSRELAY_OFF;
      } else {
        SerialCommand[i] = SSRELAY_ON;
      }
    }
    previousMillis = currentMillis;   
  }

  if(currentMillis - previousMillis > timeout) {
    //clear buffer
    while (Serial.avalable()>0){
      Serial.read();
    }
    for (int i =0;i<pins;i++){
      SerialCommand[i] = random(randlow,randhigh);
      Serial.print(i);
      Serial.print("=");
      Serial.println(SerialCommand[i]);
      if (SerialCommand[i] == 0) {
        SerialCommand[i] = SSRELAY_OFF;
      } else {
        SerialCommand[i] = SSRELAY_ON;
      }
    }
    delay(random(delaylow,delayhigh));
  }  

  Serial.println(currentMillis);
  Serial.println(previousMillis);

  analogWrite(LED0, SerialCommand[0]);
  analogWrite(LED1, SerialCommand[1]);
  analogWrite(LED2, SerialCommand[2]);
  analogWrite(LED3, SerialCommand[3]);
  analogWrite(LED4, SerialCommand[4]);
  analogWrite(LED5, SerialCommand[5]);
  analogWrite(LED6, SerialCommand[6]);
  analogWrite(LED7, SerialCommand[7]);
  
}

void reset(){
  analogWrite(LED0, SSRELAY_OFF);
  analogWrite(LED1, SSRELAY_OFF);
  analogWrite(LED2, SSRELAY_OFF);
  analogWrite(LED3, SSRELAY_OFF);
  analogWrite(LED4, SSRELAY_OFF);
  analogWrite(LED5, SSRELAY_OFF);
  analogWrite(LED6, SSRELAY_OFF);
  analogWrite(LED7, SSRELAY_OFF);
}

void test(){
  //turn them on in order
  analogWrite(LED0, SSRELAY_ON);
  delay(250);
  analogWrite(LED1, SSRELAY_ON);
  delay(250);
  analogWrite(LED2, SSRELAY_ON);
  delay(250);
  analogWrite(LED3, SSRELAY_ON);
  delay(250);
  analogWrite(LED4, SSRELAY_ON);
  delay(250);
  analogWrite(LED5, SSRELAY_ON);
  delay(250);
  analogWrite(LED6, SSRELAY_ON);
  delay(250);
  analogWrite(LED7, SSRELAY_ON);
  delay(250);

  reset();
  delay(250);
  
}
