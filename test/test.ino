#include "test.h"
// The Max and Min PWM pulse has to be calibrated first.
test t(2500, 500, 60);
//test t(2400, 500, 50); // sg90
char flag = '0';

void setup() {
  Serial.begin(9600);
  t.initialize();
}

// 0 --> short one, 1 --> longer one
// A4 --> SDA, A5 --> SCL
// Initial status 0(a) --> 65, 1(b) --> 100 angle (degree)
void loop() {
  if(Serial.available()){
    flag = Serial.read();
  }
  switch(flag){
      case '1':
        t.moveTo(15, 15);
        break;
      case '2':
        t.moveTo(20, 20);
        break;
      case '3':
        t.moveTo(20, -10);
        break;

      case '4':
        t.moveTo(30, 0);
        break;
      case '0':
        t.resetInit();
        break;
    }
}
