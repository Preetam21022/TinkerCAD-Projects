# 🌞 Interfacing Photodiode

This project demonstrates how to interface a photodiode with an Arduino Uno to read light intensity in terms of analog value and voltage.

---

## 🔍 How the Photodiode Works

A photodiode is a light-sensitive semiconductor that converts light into current. When light hits the junction, it generates a small current that can be measured as a voltage using a resistor and analog pin on Arduino.

---

## 🧾 Overview

The photodiode senses the light intensity and gives an analog output. This analog value is read using Arduino’s analog pin and then converted into a voltage value (0–5V range). The result is displayed in the Serial Monitor in real-time.

---

## 🧩 Components Used

| Name         | Quantity | Description                    |
|--------------|----------|--------------------------------|
| Photodiode   | 1        | Light-sensing diode            |
| Arduino Uno R3 | 1      | Microcontroller board          |
| 220Ω Resistor| 1        | Limits current in the circuit |

---

## 🔌 Circuit Connections

- **Photodiode Anode (+)** → **+5V**
- **Photodiode Cathode (−)** → **A0** (analog input)
- **220Ω resistor** connected in series with photodiode to ground

---

## ⚙️ How It Works

1. Arduino reads analog output (0–85) from **A0**.
2. This value is mapped to a voltage between **0 and 5V**.
3. The readings are printed on the Serial Monitor.
4. Light falling on the photodiode changes its resistance, affecting the voltage.

---

## 🖥️ Serial Monitor Output
```
Analog Value: 75
Voltage Value: 4.41 V
Analog Value: 85
Voltage Value: 5 V
```


---

## 🔗 Tinkercad Simulation

[🔗 Click to open in Tinkercad](https://www.tinkercad.com/things/cJURm8J5jx2-interfacing-photodiode)

---

## 📹 Source / Inspiration Video

[📺 Watch the project on YouTube](https://youtu.be/Wap74FHeWWg?si=3Wc-ZbTuOfQh4j-t)

---

## 💡 Real-Life Applications

- Automatic light-based night lamps
- Solar panel direction control
- Digital lux meters
- Basic environmental monitoring

---

## 🛠️ My Future Plan

I plan to:
- Add an LCD to display voltage values.
- Log data using an SD card module.
- Experiment with LDR vs photodiode behavior.

---
