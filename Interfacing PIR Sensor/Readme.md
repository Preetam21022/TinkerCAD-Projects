# Interfacing PIR Sensor

This project demonstrates how to interface a PIR (Passive Infrared) sensor with an Arduino and an I2C LCD display to detect motion. It features two versions:

---
## 🔍 How PIR Sensor Works
- Detects infrared radiation from humans.
- Outputs HIGH when motion is detected.
- Outputs LOW when no motion.
- Needs ~5–10 sec to stabilize after powering up.
---
## 🆙 Upgraded Version

### ✅ Features
- LCD shows motion start and end time.
- Pushbutton resets the timer and clears stored logs.
- Stores up to 20 motion start/stop events in arrays.
- Logs event history to Serial Monitor.
- LED turns ON during motion.

### 🔧 Components Used (Upgraded Version)

| Name     | Quantity | Component                         |
|----------|----------|-----------------------------------|
| U1       | 1        | Arduino Uno R3                    |
| D1       | 1        | Red LED                           |
| R1       | 1        | 110 Ω Resistor                    |
| PIR1     | 1        | PIR Sensor                        |
| U2       | 1        | LCD 16x2 (I2C, PCF8574-based)     |
| S1       | 1        | Pushbutton                        |
| R2       | 1        | 10 kΩ Resistor (for pushbutton)   |

---

## 🧪 Classroom Version

### ✅ Features
- LCD shows motion detected and ended times.
- LED turns on when motion is detected.
- Includes calibration and pause time logic.

### 🔧 Components Used (Classroom Version)

| Name     | Quantity | Component                         |
|----------|----------|-----------------------------------|
| U3       | 1        | Arduino Uno R3                    |
| D2       | 1        | Red LED                           |
| R3       | 1        | 110 Ω Resistor                    |
| PIR2     | 1        | PIR Sensor                        |
| U4       | 1        | LCD 16x2 (I2C, PCF8574-based)     |

---

## 🔌 Circuit Connections

### PIR Sensor
- VCC → 5V  
- GND → GND  
- OUT → Digital Pin 3  

### LED
- Anode → 110 Ω Resistor → Pin 2  
- Cathode → GND  

### Button (Upgraded version)
- One end → Digital Pin 4  
- Other end → GND via 10kΩ resistor  
- Pull-up via `pinMode(bp, INPUT)`  

---

## 🖥️ Serial Monitor Output (Upgraded)
On button press, prints:
```
Motion 1: Start = 12 sec, End = 17 sec
Motion 2: Start = 32 sec, End = 36 sec
```

---

## 📹 Source Video
[Watch the Demo](https://youtu.be/AUkYlbEnbIA?si=-W7deXdSWm8tltUx)

---

## 🔗 Tinkercad Simulation
[Try the Simulation](https://www.tinkercad.com/things/goaYk5jlRZY-interfacing-pir-sensor)

---

## 💡 Real-Life Applications
- Home security alarm
- Smart lighting automation
- Energy-efficient spaces

---

## 🔜 My Future Plan
- Add EEPROM storage to retain logs after reset.
- Send motion logs to IoT cloud platform.
- Add buzzer notification.

---
