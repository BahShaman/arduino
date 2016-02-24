/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int Green1Led = 12;
int Green2Led = 11;
int Green3Led = 10;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(Green1Led, OUTPUT);     
  pinMode(Green2Led, OUTPUT);     
  pinMode(Green3Led, OUTPUT);    
}

// the loop routine runs over and over again forever:
void loop(){
    int theDelay = 500;
    digitalWrite(Green1Led, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(Green2Led, LOW);   // turn the LED on (HIGH is the voltage level)
    delay(theDelay);               // wait for a second
    digitalWrite(Green2Led, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(Green1Led, LOW);   // turn the LED on (HIGH is the voltage level)
    delay(theDelay);               // wait for a second
    digitalWrite(Green3Led, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(Green2Led, LOW);   // turn the LED on (HIGH is the voltage level)
    delay(theDelay*2);               // wait for a second
    digitalWrite(Green2Led, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(Green3Led, LOW);   // turn the LED on (HIGH is the voltage level)
    delay(theDelay);               // wait for a second
    digitalWrite(Green1Led, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(Green2Led, LOW);   // turn the LED on (HIGH is the voltage level)
    delay(theDelay*2);               // wait for a second
}



void blinks(int Led, int HowMany){
  int i;
  for (i=0;i<HowMany;i++){
    digitalWrite(Led, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(200);               // wait for a second
  }
  for (i=HowMany;i>0;i--){
    digitalWrite(Led, LOW);    // turn the LED off by making the voltage LOW
    delay(200);               // wait for a second
  }
}
