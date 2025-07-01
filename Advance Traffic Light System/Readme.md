# Advance Traffic Light System 🚦

A smart Arduino-based traffic light simulation with editable delay settings and password protection. Ideal for learning how to combine multiple components like LEDs, LCDs, keypads, and buzzers into an interactive embedded system.

---

## 🧩 Components Used

| Quantity | Component            |
|----------|----------------------|
| 1        | Arduino Uno R3       |
| 1        | RCGB RGB LED         |
| 3        | Pushbuttons          |
| 1        | 4x4 Keypad           |
| 1        | LCD 16x2 Display     |
| 1        | Piezo Buzzer         |
| 3        | 220Ω Resistors       |
| 3        | 1kΩ Resistors        |

---

## 🔌 Circuit Connections

- **RGB LED:**
  - Red → Pin 13
  - Green → Pin 12

- **Pushbuttons:**
  - Red (pr) → Pin 9
  - Yellow (py) → Pin 10
  - Green (pg) → Pin 11

- **Keypad:**
  - Columns → Pins 0, 1, 2, 3
  - Rows → Pins 4, 5, 6, 7

- **Piezo Buzzer:** Pin 8  
- **LCD Pins:** A0 to A5 (RS, E, D4, D5, D6, D7)

---

## 🚦 How It Works

### ➤ **Normal Mode (Default)**  
- Traffic lights operate based on button input:
  - Red → "STOP!"
  - Yellow → "Get Ready"
  - Green → "Go! Go! Go!"

### ➤ **Password Mode**
- Press `*` to activate passcode input  
- Default password: `6556`
- If correct, user can modify traffic light delays using:
  - `R` → Edit Red delay in Seconds
  - `Y` → Edit Yellow delay in Seconds
  - `G` → Edit Green delay in Seconds
  - Enter new delay, then press `C` to confirm
  - Press '#' to leave delay editing mode

- Incorrect password triggers buzzer and retry prompt

---

## 🖥️ Serial Monitor Output

Not used. All messages are displayed on the **LCD screen**.

---

## 🔗 Tinkercad Simulation

[Open Tinkercad Simulation](https://www.tinkercad.com/things/iwW9XggPzl5-advance-traffic-light-system)

---

## 🎬 Source Video

[Watch on YouTube](https://youtu.be/zWGb5faF6qs?si=TGCM7kA1bGrSJpW_)

---

## 💡 Real-Life Applications

- Pedestrian or vehicle traffic control systems
- Entry management systems with timing control
- Learning embedded UI for control systems

---

## 🔮 My Future Plan

I plan to:
- Add RTC (Real-Time Clock) to control timings based on time of day
- Add EEPROM to save delay settings permanently
- Add infrared or ultrasonic sensors for automated signal switching
- Use LCD I2C Display
- A system to change the password using that 4x4 Keypad and save the changed password 
