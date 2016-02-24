/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int Green1led = 12;
int Green2led = 11;
int Green3led = 10;

byte LedPattern = B00000000;


// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(Green1led, OUTPUT);     
  pinMode(Green2led, OUTPUT);     
  pinMode(Green3led, OUTPUT);    
}

// the loop routine runs over and over again forever:
void loop() {
  //blinks(Green1Led,4);
  //blinks(Green2Led,2);
  //blinks(Green3Led,3);
  //delay(1000);               // wait for a second
}

void blinks(int Led, int HowMany){
  int i;
  for (i=0;i<HowMany;i++){
    digitalWrite(Led, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(200);               // wait for a second
    digitalWrite(Led, LOW);    // turn the LED off by making the voltage LOW
    delay(200);               // wait for a second
  }
}

void blinkall(byte pattern){
  int led1 = LOW;
  int led2 = LOW;
  int led3 = LOW;

  Serial.print(pattern);
  if (pattern & 1){
    led1 = HIGH  ;  
  }else{
    led1 = LOW;
  }

  if (pattern & 2){
    led2 = HIGH;    
  }else{
    led2 = LOW;    
  }

  if (pattern & 4){
    led3 = HIGH;    
  }else{
    led3 = LOW;    
  }

    digitalWrite(Green1led, led1);
    Serial.print("Led 1: ");
    Serial.println(led1);

    digitalWrite(Green2led, led2);
    Serial.print("Led 2: ");
    Serial.println(led2);

    digitalWrite(Green3led, led3);
    Serial.print("Led 3: ");
    Serial.println(led3);

    int theDelay = pattern << 3;
    theDelay = pattern << 3;
    Serial.print("delay is ");
    Serial.println(theDelay);
    delay(100);
}

