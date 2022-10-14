#include "test.h"
#include "Arduino.h"

test::test(int max_pulse_width, int min_pulse_width, int freq) {
  max_pwm = int(float(max_pulse_width)/1000000 *freq * 4096);
  min_pwm = int(float(min_pulse_width)/1000000 *freq * 4096);
}

int test::angleToPulse(int angle) {
  int pulse = map(angle, 0, 300, min_pwm, max_pwm);
  return pulse;
}
