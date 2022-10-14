#ifndef _TEST_H_
#define _TEST_H_

#include "Arduino.h"

class test{
  private:
    int max_pwm, min_pwm;
  public:
    test(int, int, int);
    int angleToPulse(int);
};

#endif
