char flag = '1'; // flag for the execuate signal

void setup() {
 pinMode(8,OUTPUT); // the relay info pin
 Serial.begin(9600);
}

void loop() {
  if(Serial.available()){
    flag = Serial.read();
    Serial.println(Num);
  } 
  
  delay(10);
  
  if(flag == '1'){
    digitalWrite(8,LOW);
  }
  else{
    digitalWrite(8,HIGH);
  }
}
