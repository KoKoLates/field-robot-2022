#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
// The Max and Min PWM pulse has to be calibrated first.
#define MIN_PWM_WIDTH 500
#define MAX_PWM_WIDTH 2500
#define SERVO_OFFSET 50

Adafruit_PWMServoDriver driver = Adafruit_PWMServoDriver(0x40);
uint8_t servo_num = 2;

void setup() {
  Serial.begin(9600);
  driver.begin();

  // Analog servos run around 50 HZ updates
  driver.setPWMFreq(60);
}


void loop() {
  int max_width = int(float(MAX_PWM_WIDTH)/1000000 *60*4096);
  int min_width = int(float(MIN_PWM_WIDTH)/1000000 *60*4096);

//  for( int angle =0; angle < 181; angle += 20){
//    delay(500);
//    driver.setPWM(0, 0, angleToPulse(angle, max_width, min_width));
//  }
//
//  delay(1000);

  driver.setPWM(0, 0, angleToPulse(45, max_width, min_width)); 
}

int angleToPulse(int ang, int max_w, int min_w){
  int pulse = map(ang, 0, 180, min_w, max_w);
  return pulse; 
}
