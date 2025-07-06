# Controlling RGB LED

This project demonstrates how to control an RGB LED using PWM on an Arduino Uno. The LED fades through 7 colors by varying intensity with a looped brightness ramp-down.

---

## 🔧 Components Used

| Name         | Quantity | Component              |
|--------------|----------|------------------------|
| U1           | 1        | Arduino Uno R3         |
| D1           | 1        | RCGB LED RGB           |
| R1           | 1        | 1 kΩ Resistor          |

---

## 🔌 Circuit Connections

| RGB Pin | Arduino Pin |
|---------|--------------|
| Red     | 9            |
| Green   | 7            |
| Blue    | 6            |
| Common  | GND (via 1kΩ resistor) |

- Connect each LED pin to its respective PWM pin.
- Use a common cathode RGB LED (RCGB).

---

## 🧠 How It Works

- The code uses a `for` loop to gradually decrease brightness (`n`) from 255 to 0.
- Each `setColor()` call applies one of 7 RGB color combinations.
- Colors: Blue → Green → Cyan → Red → Magenta → Yellow → White
- After cycling, the LED turns off.

---

## 🖥️ Serial Monitor Output

Not used in this project.

---

## 🔗 Tinkercad Simulation

[Click here to view](https://www.tinkercad.com/things/7OVm03CJ2MN-controlling-rgb-led)

---

## 📹 Source/Inspiration Video

[Watch on YouTube](https://youtu.be/Y5wmQkrL2Fc?si=X7YtmMjIJTd4-N8n)

---

## 💡 Real-Life Applications

- Ambient lighting systems  
- RGB mood lights  
- Smart home indicator LEDs  
- DIY color-matching lamps  

---

## 🛠️ My Future Plan

- Add pushbutton to switch between color modes  
- Add a potentiometer to control fade speed  
- Use LDR to auto-dim colors at night

---

## 🔍 How RGB LED Works

- RGB LEDs combine red, green, and blue light using PWM to form many colors.
- Common cathode LEDs have all cathodes connected to GND.
- Varying brightness on each pin mixes light to form the final visible color.

