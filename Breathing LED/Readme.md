# Breathing LED

This simple Arduino project creates a "breathing" light effect by gradually increasing and decreasing the brightness of an LED using PWM (Pulse Width Modulation). It's an elegant way to learn analog output control with `analogWrite()`.

## 🧾 Overview

The LED fades in and out repeatedly, giving a calming breathing-like glow. It’s often used in power indicators for laptops or standby signals in consumer electronics.

## 🔩 Components Used

| Name   | Quantity | Component       |
|--------|----------|------------------|
| D1     | 1        | Red LED          |
| R1     | 1        | 110 Ω Resistor   |
| U1     | 1        | Arduino Uno R3   |

## 🔌 Circuit Connections

| Arduino Pin | Component |
|-------------|-----------|
| Pin 11      | Positive leg of LED (through 110 Ω resistor) |
| GND         | Negative leg of LED |

## ⚙️ How It Works

- The LED is connected to PWM pin 11.
- The program uses `analogWrite()` to vary the brightness between 0 and 255 in both directions.
- A small delay after each step creates the smooth transition.
- After completing one full cycle (fade in and fade out), there's a short pause before repeating.

## 💻 Serial Monitor Output

None. This project runs silently without any serial communication.

## 🔗 Tinkercad Simulation

[Tinkercad Simulation Link](https://www.tinkercad.com/things/5mmLPpgDFnQ-breathing-led)

## 📽️ Source / Inspiration Video

[Watch on YouTube](https://youtu.be/HfBXMuKdtLY?si=ZhKDMD67BoC3V6xG)

## 🌐 Real-Life Applications

- Sleep or standby indicator on laptops or smart devices
- Mood lighting and visual cues in gadgets
- Simple artistic lighting projects

## 🧠 My Future Plan

I plan to extend this project by adding:
- A **potentiometer** to control breathing speed
- An **RGB LED** to cycle through colors with the breathing effect
- A **button** to pause/resume or change the mode
