//serialecho
//mboscia

char chr = 1;

void setup(){
  Serial.begin(38400);
  Serial.println("hello world");
}

void loop(){
 if (Serial.available()){
   chr = Serial.read();
   Serial.print(chr);
 }
}
