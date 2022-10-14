#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
// The Max and Min PWM pulse has to be calibrated first.
#define MIN_PWM_WIDTH 500
#define MAX_PWM_WIDTH 2500

Adafruit_PWMServoDriver driver = Adafruit_PWMServoDriver();

void setup() {
  Serial.begin(9600);
  driver.begin();

  // Analog servos run around 50 HZ updates
  driver.setPWMFreq(60);
}

// 0 --> short one, 1 --> longer one
void loop() {
  int max_width = int(float(MAX_PWM_WIDTH)/1000000 *60 * 4096);
  int min_width = int(float(MIN_PWM_WIDTH)/1000000 *60 * 4096);
  driver.setPWM(0, 0, angleToPulse(30, max_width, min_width));
  driver.setPWM(1, 0, angleToPulse(90, max_width, min_width));
}

int angleToPulse(int ang, int max_w, int min_w){
  int pulse = map(ang, 0, 300, min_w, max_w);
  return pulse; 
}
