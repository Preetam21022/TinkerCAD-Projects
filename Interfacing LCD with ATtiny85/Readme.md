# Interfacing LCD with ATtiny85

This project demonstrates how to connect and display text using a 16x2 LCD with an ATtiny85 microcontroller. It shows a welcome message along with a live seconds counter.

## 🧾 Overview

The LCD is driven in 4-bit parallel mode using digital pins of the ATtiny85. The microcontroller is powered by four 1.5V AA batteries. This minimal setup shows how to get an LCD working even with limited microcontroller pins.

## 🔩 Components Used

| Name         | Quantity | Component              |
|--------------|----------|------------------------|
| U1           | 1        | ATtiny85               |
| U2           | 1        | LCD 16 x 2             |
| R1           | 1        | 220 Ω Resistor         |
| BAT1         | 1        | 4x AA 1.5V Battery Pack|

## 🔌 Circuit Connections

| LCD Pin | ATtiny85 Pin |
|---------|---------------|
| RS      | 0             |
| E       | 1             |
| D4      | 2             |
| D5      | 3             |
| D6      | 4             |
| D7      | 5             |
| VSS/VDD/V0/Backlight | Connected appropriately with power and resistor |

The LCD is powered from the battery pack and uses a 220Ω resistor for the backlight.

## ⚙️ How It Works

- Displays "I am Preetam" on the first line.
- Shows "Hello!" on the second line.
- On the right side of the second line, it displays an updating seconds counter.
- Refresh rate is 1 second.

## 🖥️ Serial Monitor Output

N/A (ATtiny85 doesn't support serial print directly unless using additional software)

## 🔗 Tinkercad Simulation

[Tinkercad Simulation Link](https://www.tinkercad.com/things/fcsPvajB2TO-interfacing-lcd-with-attiny-85)

## 📽️ Source / Inspiration Video

[Watch on YouTube](https://youtu.be/LXPbTBR7AwI?si=3hVjmrPvwJLQxs67)

## 💡 Real-Life Applications

- Minimal embedded display systems
- Battery-operated LCD counters
- Display for compact sensor-based projects

## 📌 My Future Plan

I plan to upgrade this setup to work with **I2C LCD and TinyWireM** to reduce the number of used pins, and possibly add sensor readings to display on the screen.
