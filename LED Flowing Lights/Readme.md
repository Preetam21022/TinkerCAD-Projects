# LED Flowing Lights

This Arduino project demonstrates a simple flowing light animation using multiple LEDs. It's a great beginner-level project to understand arrays, loops, and sequential control of digital outputs in Arduino.

## 🧾 Overview

The program turns on each LED one by one, creating a flowing effect. After all LEDs are on, they are turned off in the same sequence. The concept can be extended to more LEDs easily by **updating the pin array**.

## 🔩 Components Used

| Name | Quantity | Component      |
|------|----------|----------------|
| D1   | 1        | Red LED        |
| D2   | 1        | Red LED        |
| D3   | 1        | Red LED        |
| R1   | 1        | 1 kΩ Resistor  |
| R2   | 1        | 1 kΩ Resistor  |
| R3   | 1        | 1 kΩ Resistor  |
| U1   | 1        | Arduino Uno R3 |

## 🔌 Circuit Connections

| Arduino Pin | Component Connection |
|-------------|----------------------|
| 3           | LED 1 (through 1kΩ resistor) |
| 5           | LED 2 (through 1kΩ resistor) |
| 10          | LED 3 (through 1kΩ resistor) |
| GND         | All LED negative legs |

## ⚙️ How It Works

- Three LEDs are connected to digital pins 3, 5, and 10.
- In the `setup()` function, all pins are set as OUTPUT.
- The `loop()` function turns each LED ON in sequence with a delay, then turns them OFF one by one.
- This creates a continuous "flowing" or "chasing" light effect.

## 💻 Serial Monitor Output

None. This is a purely visual output project.

## 🔗 Tinkercad Simulation

[Tinkercad Simulation Link](https://www.tinkercad.com/things/9J4YeV8S7pe-led-flowing-lights)

## 📽️ Source / Inspiration Video

[Watch on YouTube](https://youtu.be/jfH_3k5It7o?si=unf2O_yU_yfyFHDn)

## 🌐 Real-Life Applications

- Indicator lights
- Traffic light simulations
- LED chasers for decoration
- Intro to LED arrays for students

## 🧠 My Future Plan

I plan to:
- Add more LEDs for longer flowing sequences
- Introduce direction reversal (ping-pong effect)
- Use a **potentiometer** to control flow speed
- Add **button control** for pause/play or direction toggle
