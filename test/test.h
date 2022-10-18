#ifndef _TEST_H_
#define _TEST_H_

#include "Arduino.h"
#include <Adafruit_PWMServoDriver.h>

class test{
  private:
    int max_pwm, min_pwm, freq_value;
    Adafruit_PWMServoDriver driver;
    
  public:
    test(int, int, int);
    int angleToPulse(int);
    void initialize();
    void moveTo(int, int);
    void degreeTo(int, int);
    void resetInit();
    void grab();
    void rel();
};

#endif
