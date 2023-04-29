# Field Robot 2022
`NTU BME` 、 `field robot` 、 `2022` <br>

The hardware and source codes using for field robot competition 2022. The competition is taking place in NTU October, 2022 and consists in various task including object detecting, gripping, water punmping, lane tracking and climbing.

## Features
* System consists of NVIDIA Jetson Nano and Arduino Mega 2560, with transmission via serial (`I2C` / `UART`).
* Implements a lane `tracking` algorithm for synthetic grass paths using opencv image processing, allowing robot to follow along the appropriate path.
* Using `object detect` and image processing algorithms to locate the fruit position.
* Design the robotic arm and apply the `inverse kinematic` to control the arm by giving the object position.

## Overview
* [**circuit designs**](./circuit/) with electrical components and wire works.
* [**soruce**](./src/) controlling and operational Algorithms.
* [**scripts**](./scripts/) lane detection and tracking function codes, image adjustments testing for white balancing and `HSV` color ranger finder and picker.
* [**robotic cart**](./robotic_cart/) with hardware designs in `CAD` for the robot.
* [**robotic arm**](./robotic_arm/) servo moter and driver calibration, dummay arm design and source codes for controlling.
* [**resouces**](./assets/resources/) / [**documents**](./assets/2022-field-robot-rule-manual.pdf) / [**images**](./assets/images/)


