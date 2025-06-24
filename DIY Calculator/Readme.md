# DIY Calculator using Arduino, Keypad, and LCD

This project is a basic calculator made using an Arduino Uno, a 4x4 matrix keypad, and a 16x2 LCD. It performs addition, subtraction, multiplication, and division between two numbers. The user enters input through the keypad, and the result is displayed on the LCD screen.

## 🧰 Required Components

- Arduino Uno R3  
- 4×4 Matrix Keypad  
- 16×2 LCD Display  
- 1 × 250kΩ Potentiometer (for LCD contrast)  
- 1 × 1kΩ Resistor (optional pull-down)  
- Jumper wires  
- Breadboard  

## 🔌 Circuit Connections

| Component       | Arduino Pin         |
|----------------|---------------------|
| LCD RS         | D13                 |
| LCD E          | D12                 |
| LCD D4         | D11                 |
| LCD D5         | D10                 |
| LCD D6         | D9                  |
| LCD D7         | D8                  |
| Keypad Rows    | D7, D6, D5, D4      |
| Keypad Columns | D3, D2, D1, D0      |
| Potentiometer (Middle Pin) | LCD V0 (Contrast Control) |

> **Note:** Use `LiquidCrystal` and `Keypad` libraries for this project.

## ⚙️ How It Works

1. **User Input**
   - The user enters a number using the keypad.
   - An operator (+, –, ×, ÷) is pressed.
   - The user enters the second number and presses `=` to get the result.

2. **Display on LCD**
   - The LCD shows both inputs and the result.
   - If division by zero is attempted, it displays “INVALID”.

3. **Clear Operation**
   - Pressing `c` resets the screen and calculation for new input.

## 💻 Tinkercad Simulation

🔗 [Click to open simulation in Tinkercad](https://www.tinkercad.com/things/7DS33MMIPEu-diy-calculator)

## 📺 Project Inspiration / Reference

🎥 [Watch the original video tutorial](https://youtu.be/dgGfoHlhugs?si=9fSZ5mWlXu-q1jzV)

---

## 🧭 Real-Life Applications

- Educational tool to understand calculator logic  
- Demonstration of interfacing keypad and LCD with Arduino  
- Foundation for more complex embedded system UI  
- Useful for prototyping simple handheld electronics  

---

## 🔧 Future Upgrades I Will Work On

- I will add support for multi-digit results and decimal input.  
- I plan to include memory functions (M+, M-, MR, MC) like a real calculator.  
- I will design a 3D printed enclosure for the complete calculator unit.  
- I may add a battery backup and reset switch for portability.
