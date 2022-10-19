#ifndef _ARM_H_
#define _ARM_H_
#include "Arduino.h"
#include <Adafruit_PWMServoDriver.h>

class arm{
  private:
    int address, freq;
    Adafruit_PWMServoDriver driver;
    int maxPWM1, maxPWM2, minPWM, maxAngle1, maxAngle2;
    
  public:
    arm(int, int);
  
    
    void initialize();
    void resetInit();
    void moveTo(int x, int y);

    // grabber
    void grab();
    void ungrab();

    //
    int angleToPulse1(int);
    int angleToPulse2(int);
  
};

#endif
