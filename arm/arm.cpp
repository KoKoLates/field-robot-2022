#include "arm.h"

arm::arm(int i2c_address, int frequency){
  address = i2c_address; freq = frequency;  
}

void arm::initialize(){
  // Initialize the pwm server driver
  Adafruit_PWMServoDriver driver = Adafruit_PWMServoDriver(address);
  driver.begin(); driver.setPWMFreq(freq);

  maxPWM1 = int(float(2500)/1000000 *freq * 4096);
  maxPWM2 = int(float(2400)/1000000 *freq * 4096);
  minPWM = int(float(500)/1000000 *freq * 4096);
  maxAngle1 = 300; maxAngle2 = 180;
}

void arm::resetInit(){
  driver.setPWM(0, 0, angleToPulse1(50));
  driver.setPWM(1, 0, angleToPulse1(100));
  driver.setPWM(2, 0, angleToPulse2(0));
}

void arm::moveTo(int x, int y){
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

  driver.setPWM(0, 0, angleToPulse1(theta1));
  driver.setPWM(1, 0, angleToPulse1(theta2));
}

void arm::grab(){
  driver.setPWM(2, 0, angleToPulse2(180));
}

void arm::ungrab(){
  driver.setPWM(2, 0, angleToPulse2(0));
}

int arm::angleToPulse1(int angle){
  return map(angle, 0, maxAngle1, minPWM, maxPWM1);
}

int arm::angleToPulse2(int angle){
  return map(angle, 0, maxAngle2, minPWM, maxPWM2);
}
