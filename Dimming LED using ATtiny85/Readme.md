# Dimming LED with ATtiny85

This project demonstrates how to control the brightness of an LED using a **potentiometer** and **PWM output** on the **ATtiny85 microcontroller**. It's a lightweight and efficient solution for analog brightness control in low-power embedded systems.

## 🧾 Overview

- The potentiometer's analog input is read and mapped to PWM range.
- The PWM signal is output on a digital pin to vary LED brightness.
- The ATtiny85 allows for compact and energy-efficient operation.

## 🔩 Components Used

| Name   | Quantity | Component              |
|--------|----------|------------------------|
| U1     | 1        | ATtiny85 Microcontroller |
| Rpot1  | 1        | 250 kΩ Potentiometer   |
| R1     | 1        | 47 Ω Resistor          |
| D1     | 1        | Red LED                |
| BAT1   | 1        | Coin Cell 3V Battery   |

## 🔌 Circuit Connections

| ATtiny85 Pin | Connected To        |
|--------------|---------------------|
| Pin 1 (PB1)  | LED (via 47 Ω R1)   |
| Pin A3 (PB3) | Potentiometer Wiper |
| GND          | Battery -           |
| VCC          | Battery +           |

## ⚙️ How It Works

1. The potentiometer reads a voltage between 0 and 3V (mapped to 0–1023).
2. The analog value is scaled down to a range of 0–255 using `map()`.
3. `analogWrite()` sends a PWM signal to control the LED brightness based on that value.

## 💻 Serial Monitor Output

Not used in this project as ATtiny85 does not have built-in serial monitor support.

## 🔗 Tinkercad Simulation

[Click to Open Simulation](https://www.tinkercad.com/things/21hjq3u3SUA-dimming-led-with-attiny85)

## 📽️ Source / Inspiration Video

[Watch on YouTube](https://youtu.be/_ueJ5UDtQZI?si=qy9q8HcwmEwH5lyr)

## 🌐 Real-Life Applications

- Battery-powered LED dimmers
- Mood lighting systems
- Microcontroller-based brightness control
- Light-sensitive indicators in embedded systems

## 🧠 My Future Plan

I plan to:
- Replace the potentiometer with an LDR for automatic ambient light-based dimming
- Add EEPROM functionality to store last brightness setting
- Integrate multiple LEDs for a soft fading effect
