# Field Robot 2022
`NTU BME` 、 `field robot` 、 `2022` <br>

The hardware and source codes using for field robot competition 2022. The competition is taking place in NTU October, 2022 and consists in various task including gripping, water punmping and climbing.

## Features
* System consists of NVIDIA Jetson Nano and Arduino Mega 2560, with transmission via serial (`I2C` / `UART`).
* Implements a lane `tracking` algorithm for synthetic grass paths using opencv image processing, allowing robot to follow along the appropriate path.
* Using `object detect` and image processing algorithms to locate the fruit position.
* Design the robotic arm and apply the `inverse kinematic` to control the arm by giving the object position.

## Overview
* [**Circuit Designs**](./circuit/) with Electrical Components and Wire works.
* [**Soruce Codes**](./src/) Controlling Operation Algorithms.
* [**Scripts**](./scripts/) Lane Detection and Tracking Function Codes. Image Adjustments Testing For White Balancing and `HSV` Color Ranger and Pickers.
* [**Robotic Cart**](./robotic_cart/) The Hardware Designs For the Robot.
* [**Robotic Arm**](./robotic_arm/) Servo Moter and Driver Calibration. Dummay Arm Design and Source Codes for Controlling in `Inverse Kinematic`.
* [**Resouces**](./assets/resources/) / [**Documents**](./assets/2022-field-robot-rule-manual.pdf) / [**Images**](./assets/images/)


