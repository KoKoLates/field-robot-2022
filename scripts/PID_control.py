import time
class PID:
    def __init__(self, P, I, D):
        self.Kp, self.Ki, self.Kd = P, I, D
        self.sample_time = 0.1
        self.current_time = time.time()
        self.last_time = self.current_time

        self.PTerm = 0.0
        self.ITerm = 0.0
        self.DTerm = 0.0
        self.last_error = 0.0
        self.int_error = 0.0

    def update(self, feedback_value):
        error = feedback_value
        self.current_time = time.time()
        delta_time = self.current_time - self.last_time
        if delta_time >= self.sample_time:
            self.ITerm += error * delta_time
            self.DTerm = 0.0
            if delta_time:
                self.DTerm = (error - self.last_error) / delta_time
            self.last_time = self.current_time
            self.last_error = error
            return (self.Kp * error) + (self.Ki * self.ITerm) + (self.Kd * self.DTerm)
 