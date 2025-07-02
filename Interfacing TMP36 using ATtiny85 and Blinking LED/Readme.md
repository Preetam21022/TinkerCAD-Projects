# 🌡️ Interfacing TMP35 using ATtiny85 and Blinking LED

This project demonstrates how to interface a TMP36 temperature sensor with an ATtiny85 microcontroller to display temperature ranges via a blinking RGB LED. Different colors indicate specific temperature ranges, helping provide visual temperature feedback without an LCD or display.

---

## 🔍 How the TMP36 Sensor Works

The TMP36 is an analog temperature sensor that outputs a voltage proportional to temperature. At 0°C, the output voltage is 0.5V, and it increases by 10mV per °C. The microcontroller reads this voltage and converts it into temperature using a simple formula.

---

## 🧾 Overview

The ATtiny85 reads the analog voltage output from the TMP36 sensor and converts it into a temperature value in Celsius. Based on the temperature, the RGB LED blinks in different colors representing distinct temperature ranges. The LED blinks on and off with a 500ms delay, providing a simple yet effective temperature indication system.

---

## 🧩 Components Used

| Name                 | Quantity | Description                   |
|----------------------|----------|-------------------------------|
| RCGB LED RGB         | 1        | RGB LED with Red, Green, Blue pins |
| DIP Switch DPST      | 1        | On/off switch for power control  |
| Coin Cell 3V Battery | 1        | Power supply                   |
| ATtiny85             | 1        | 8-bit microcontroller          |
| Temperature Sensor (TMP36) | 1    | Analog temperature sensor      |
| 220Ω Resistor        | 1        | Current limiting resistor for LED |

---

## 🔌 Circuit Connections

- TMP36 sensor output connected to ATtiny85 analog pin A2
- RGB LED pins connected to ATtiny85 pins 0 (Red), 1 (Blue), and 2 (Green) with 220Ω resistors
- DIP switch to power the circuit via the coin cell battery

---

## ⚙️ How It Works

1. The ATtiny85 reads analog voltage from the TMP36 sensor.
2. Converts this voltage to temperature in Celsius using the formula:  
   `Temperature (°C) = (Voltage - 0.5) * 100`
3. Compares the temperature to predefined ranges.
4. Lights up the RGB LED in colors representing the current temperature range.
5. The LED blinks with a 500 ms on/off delay to visually indicate temperature changes.

---

## 🌈 Temperature Ranges and LED Colors

| Temperature (°C) | LED Color  |
|------------------|------------|
| -40 to 10        | Purple     |
| 10 to 15         | Blue       |
| 15 to 21         | Cyan       |
| 21 to 25         | Green      |
| 25 to 30         | White      |
| 30 to 35         | Yellow     |
| 35 to 126        | Red        |

---

## 🔗 Tinkercad Simulation

[🔗 Open this project on Tinkercad](https://www.tinkercad.com/things/4nOALdL6FS1-interfacing-tmp35-using-attiny85-and-blinking-led)

---

## 📹 Source / Inspiration Video

[📺 Watch the project on YouTube](https://youtu.be/1mcgcK2fXbo?si=l9NHkD1YZUHh8Md_)

---

## 💡 Real-Life Applications

- Portable temperature monitoring devices
- Battery-powered temperature indicators
- Simple environmental monitoring
- Educational tool for microcontroller ADC and sensor interfacing

---

## 🛠️ My Future Plan

- Add Bluetooth or wireless connectivity for remote temperature monitoring.
- Integrate a small OLED display for numeric temperature readout.
- Optimize power consumption for longer battery life.

---
