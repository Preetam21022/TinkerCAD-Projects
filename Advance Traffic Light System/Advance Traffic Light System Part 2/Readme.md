# 🚦 Advance Traffic Light System – Part 2

This project builds on a basic traffic light system by adding **keypad-controlled delay configuration**, **LCD status display**, **password protection**, and **mode switching** via DIP switches and pushbuttons. It features real-time countdown on the LCD, editable light durations, and testing options for individual lights.

---

## 🧾 Overview

The system is password-protected (6556) to access editing mode. Once unlocked, the user can configure the duration of **Red**, **Yellow**, and **Green** lights through a 4x4 keypad. A piezo buzzer provides feedback. The system runs in either **automatic cycle mode** or **button-controlled mode** using SPST DIP switches and pushbuttons.

The LCD (I2C) displays light status and countdown. Delays can be updated, saved, and reset as needed.

---

## 🔧 Components Used

| Name                  | Quantity | Description                                |
|-----------------------|----------|--------------------------------------------|
| RCGB LED RGB          | 1        | RGB LED used for signal indication         |
| 220 Ω Resistor        | 2        | Current limiters for LED                   |
| 10 kΩ Resistor        | 4        | Pull-down for pushbuttons                  |
| Arduino Uno R3        | 1        | Microcontroller                            |
| Pushbuttons           | 4        | Manual control of signal lights            |
| Piezo Buzzer          | 1        | Audio feedback                             |
| 4x4 Keypad            | 1        | User input for passcode & delay            |
| I2C 16x2 LCD (PCF8574)| 1        | For displaying mode, prompts, countdown    |
| DIP Switch (SPST x4)  | 1        | Manual switch to toggle between modes      |

---

## 🔌 Circuit Modes and Controls

### 🔐 Mode: Password + Delay Configuration

- **Press `*`** to enter password mode.
- **Type `6556`** using the keypad.
- On success: LCD shows **Editing Enabled**.
- You can now change delays:

| Key | Function                |
|-----|-------------------------|
| `R` | Change Red light delay  |
| `Y` | Change Yellow delay     |
| `G` | Change Green delay      |
| `C` | Confirm each entry      |
| `#` | Exit editing mode       |

> **Note**: Delays are entered in seconds and internally converted to milliseconds.

---

### 🔁 Mode: Automatic Traffic Cycle

- Controlled via **pushbuttons (S1–S4)**.
- Enabled when **DIP Switch (SPST) is OFF**.
- Lights cycle through:
  - Red → Yellow → Green with respective delays.
- Countdown is shown on LCD.

---

### 🧪 Test Mode (Manual Testing)

- Enabled when **DIP Switch is ON**.
- Lights and states are triggered using pushbuttons:
  - **A**: Start loop (cycle mode)
  - **R**: Test Red light
  - **Y**: Test Yellow light
  - **G**: Test Green light

---

## 📺 Project Links

- 🔗 **Tinkercad Simulation**: [Click Here](https://www.tinkercad.com/things/5urL8O215Vv-advance-traffic-light-system-part-2)
- 📹 **YouTube Video**: [Watch Demo](https://youtu.be/zWGb5faF6qs?si=oghBjzeA3YCVBKBA)

---

## ⚠️ Known Issues / Challenges

1. **Loop Exit Timing**:  
   The `A`-loop (traffic cycle) can **only be interrupted** with `#` during certain periods, particularly **just before a timer ends**. You want it to exit **immediately** at any moment.

2. **LCD Power Toggle Issue**:  
   LCD can't be powered off and back on using a switch while running — it needs **resetting the simulation** to work again. This limits LCD power control.

---

## 🛠️ Button Map and Reference

| Label | Function                       |
|-------|--------------------------------|
| A     | Start traffic cycle            |
| R     | Red light test                 |
| Y     | Yellow light test              |
| G     | Green light test               |
| #     | Reset (disable keypad & lock)  |
| *     | Enable keypad and password     |

> Reminder: Ensure SPST switches are turned ON/OFF correctly to match the intended mode.

---

## 💡 Future Improvements

- Implement **interrupts or non-blocking timers** to allow `#` to break out of loops immediately.
- Use **transistor control or software power toggle** to **reinitialize LCD** after switch OFF.
- Store edited delay values in **EEPROM** for persistence.
- Add **night mode** or **pedestrian mode** with a toggle.
- Integrate **RTC module** for time-based control.

---

## 🔐 Default Password

- `6556`

---

## 🧠 Summary

This is a feature-rich, modular traffic light simulation with editable timing, password protection, and real-time feedback. It's a great project to explore keypad interfacing, display control, and modular traffic automation logic.

