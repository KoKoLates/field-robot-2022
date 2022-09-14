#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

#define MIN_PWM_PULSE 650
#define MAX_PWM_PULSE 2350

Adafruit_PWMServoDriver driver = Adafruit_PWMServoDriver(0x40);

void setup() {
  Serial.begin(9600);
  driver.begin();

  // Analog servos run around 60 HZ updates
  driver.setPWMFreq(50);
}


void loop() {
  driver.setPWM(0, 0, 550);
}
