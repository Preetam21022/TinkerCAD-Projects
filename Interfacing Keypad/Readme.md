# Interfacing Keypad with Arduino (with and without LCD)

This project demonstrates how to interface a 4×4 matrix keypad with an Arduino Uno. The pressed key is detected and displayed either on the Serial Monitor or on a 16×2 LCD. This is a foundational project that teaches how keypads can be used for user input in embedded systems.

## 🧰 Required Components

- Arduino Uno R3 (×2 for dual setup)  
- 2 × 4×4 Matrix Keypads  
- 1 × 16×2 LCD Display  
- 1 × 250kΩ Potentiometer (for LCD contrast)  
- 1 × 1kΩ Resistor  
- Jumper wires  
- Breadboard  

## 🔌 Circuit Connections (Serial Monitor Version)

| Keypad Rows    | Arduino Pins 6–9 |
|----------------|------------------|
| Keypad Columns | Arduino Pins 2–5 |

> ⚠️ **Do not use pins 0 and 1** for keypad or other I/O when using Serial Monitor — these pins are used for USB communication and will interfere with `Serial.print()`.

## 🔌 Circuit Connections (LCD Version)

| LCD Pin | Arduino Pin |
|---------|-------------|
| RS      | D13         |
| E       | D12         |
| D4      | D11         |
| D5      | D10         |
| D6      | D9          |
| D7      | D8          |
| V0 (Contrast) | Potentiometer Center Pin |

| Keypad Rows    | Arduino Pins 4–7 |
|----------------|------------------|
| Keypad Columns | Arduino Pins 0–3 |

> ⚠️ **LCD version does not use Serial Monitor**, so pins 0 and 1 can be used for keypad safely.

## ⚙️ How It Works

### Version 1: Without LCD (Using Serial Monitor)
- The keypad is connected to digital pins.
- Pressed keys are read using the `Keypad` library.
- The result is printed to the Serial Monitor.
- **Important:** Pins 0 and 1 are avoided to ensure Serial communication works.

### Version 2: With LCD Display
- Keypad input is shown on a 16x2 LCD screen using the `LiquidCrystal` library.
- This version doesn't use the Serial Monitor, so pins 0 and 1 are available for keypad input.

## 💻 Tinkercad Simulation

🔗 [Click to open simulation in Tinkercad](https://www.tinkercad.com/things/cA60SjgzPkf-interfacing-keypad)

## 📺 Project Inspiration / Reference

🎥 [Watch the original video tutorial](https://youtu.be/4Mf0bHzimAE?si=C9iUcVwbY5nZFnP8)

---

## 🧭 Real-Life Applications

- ATM machines and digital locks  
- User input in embedded systems  
- Menus and navigation systems in DIY electronics  
- Entry systems in smart security setups  

---

## 🔧 Future Upgrades I Will Work On

- I will add an LCD + Serial hybrid setup that shows input on both simultaneously.  
- I plan to integrate buzzer feedback with each key press.  
- I will test using a 3x4 keypad and compare wiring logic.  
- I may create a menu system controlled entirely by the keypad.
