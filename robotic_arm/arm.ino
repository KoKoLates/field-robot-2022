#include "arm.h"
arm a(0x40, 60);
char flag = '0';

void setup() {
  Serial.begin(9600);
  a.initialize();

}

void loop() {
  if(Serial.available()){
    flag = Serial.read();
  }
  switch(flag){
    case '0':
      a.resetInit();
      break;
    case '1':
      a.moveTo(20, 0);
      break;
    case '3':
      a.grab();
      break;
    case '4':
      a.moveTo(30, 30);
      break;
    case '5':
      a.ungrab();
      break;
  }
}
