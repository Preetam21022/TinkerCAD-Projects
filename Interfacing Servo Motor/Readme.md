# Interfacing Servo Motor

This Arduino project demonstrates the basic control of a **positional servo motor** using the `Servo.h` library. The servo is programmed to sweep smoothly from 0° to 180° and back continuously.

## 📋 Overview

- The servo motor is attached to digital pin 2.
- A `for` loop is used to increment and decrement the servo's position.
- The `delay()` function ensures smooth movement.

## 🔩 Components Used

| Name     | Quantity | Component               |
|----------|----------|-------------------------|
| U1       | 1        | Arduino Uno R3          |
| SERVO1   | 1        | Positional Micro Servo  |

## 🔌 Circuit Connections

| Component     | Arduino Pin |
|---------------|-------------|
| Servo Signal  | Pin 2       |
| Servo VCC     | 5V          |
| Servo GND     | GND         |

> 💡 Tip: If the servo jitters or doesn't respond properly, consider powering it with an external power supply (e.g. 5V battery pack).

## ⚙️ How It Works

1. The `Servo` object is attached to pin 2.
2. In the `loop()`, the servo angle is gradually increased from 0° to 180°.
3. Then it's decreased from 180° to 0°, creating a continuous back-and-forth sweeping motion.

## 🖥️ Serial Monitor Output

Not used in this project.

## 🔗 Tinkercad Simulation

[Open Tinkercad Project](https://www.tinkercad.com/things/bReONAAHjJ6-interfacing-servo-motor)

## 📽️ Source / Inspiration Video

[Watch on YouTube](https://youtu.be/_tsl8B3Mrdg?si=BL_JkZ66Jt_8qNOh)

## 🌐 Real-Life Applications

- Robotic arms
- Pan/tilt camera mounts
- Animatronics
- DIY automation systems

## 🧠 My Future Plan

I plan to:
- Add pushbuttons to manually control the servo's position
- Integrate a potentiometer for analog control
- Use ATtiny85 instead of Arduino Uno for a compact setup
