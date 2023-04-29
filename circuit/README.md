# Circuit Designs
`Electric components` 、 `circuit designs` <br>

__1. Computational Unit__ <br>

* Arduino Mega / Arduino Nano -> `controller`
* Raspberry Pi 4
* NVIDIA Jetson Nano

__2.Electrical Unit__ <br>

* IBT2 -> `H-Bridge`
* Voltage Converter `HW319-V6.0`
* Voltage Indicator
* Battery (`12v`) / Battery pack (`5v/2a`)
* Emergency Button `LA38`

__3.Sensors and Acuator__ <br>

* Step Motor / Servo Motor
* Relay `SRD-05VDC-SL-C` -> water pump


## Implements
**Testing** | `controller`、 `H-bridge`、 `regulator` and `DC motor`. <br>
* Testing the driven part that connect the DC motor with H-Bridge and `12v` DC Battery.
* Using the Arduino Mega as the controller for `PWN` signal inputs.
* Check the general switch and emergency button work.

![image](./images/circuit_01.jpg) ![image](./circuit.png)

**Water-proof container** <br>
* The voltage for each components are indicating strictly.
* The all important unit for controll and operation are places inside the water-proof container both for robotic cart and for the dummy arm.
* There are maly three type of voltage being managed. `12v` for DC motor driven; two `5v` one is for the main controller and other sensors, the other is for the servo motor on the robotic arm which is driven by the servo driver (`PCA9685`).

![image](./images/circuit_02.JPG) ![image](./images/circuit_05.jpg)

---
[`Components Lists`](./components_list.pdf)