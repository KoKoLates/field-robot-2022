#include "test.h"
#include "Arduino.h"

test::test(int max_pulse_width, int min_pulse_width, int freq) {
  max_pwm = int(float(max_pulse_width)/1000000 *freq * 4096);
  min_pwm = int(float(min_pulse_width)/1000000 *freq * 4096);
  freq_value = freq;
}

void test::initialize(){
  Adafruit_PWMServoDriver driver = Adafruit_PWMServoDriver(0x40);
  driver.begin();

  // Analog servos run around 60 HZ updates
  driver.setPWMFreq(freq_value);
}

int test::angleToPulse(int angle) {
  int pulse = map(angle, 0, 300, min_pwm, max_pwm);
//  int pulse = map(angle, 0, 180, min_pwm, max_pwm); // sg90
  return pulse;
}

void test::degreeTo(int a, int b){
  driver.setPWM(0, 0, angleToPulse(a));
  driver.setPWM(1, 0, angleToPulse(b));  
}

void test::resetInit(){
  driver.setPWM(0, 0, angleToPulse(50));
  driver.setPWM(1, 0, angleToPulse(100));
}

void test::moveTo(int x, int y){
  double a1 = 21.375; 
  double a2 = 24.000;
  double l = sqrt(pow(x, 2)+ pow(y, 2)); // ratation axis to end direation distance

  double a = y / l;
  double b = (pow(l, 2) + pow(a1, 2) - pow(a2, 2))/(2 * l * a1);
  double c = (pow(a1, 2) + pow(a2, 2) - pow(l, 2))/(2 * a1 * a2);

  double theta2 = atan2(a, sqrt(1 - pow(a, 2))) + atan2(sqrt(1 - pow(b, 2)), b);
  double theta3 = atan2(sqrt(1 - pow(c, 2)), c);
  theta2 = int(theta2 * 180 / PI);
  theta3 = int(theta3 * 180 / PI);
  int theta1 = 180 - theta2 - theta3;

  driver.setPWM(0, 0, angleToPulse(theta1));
  driver.setPWM(1, 0, angleToPulse(theta2));
}

void test::grab(){
  driver.setPWM(2, 0, angleToPulse(180));
}

void test::rel(){
  driver.setPWM(2, 0, angleToPulse(0));
}
