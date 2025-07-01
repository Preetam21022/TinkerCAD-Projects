# Dimming LED Bulb 💡

This simple Arduino project demonstrates how to control the brightness of an LED or small light bulb using a **potentiometer**. It uses **analogRead** to read the position of the potentiometer and **analogWrite** to adjust the brightness accordingly using **PWM (Pulse Width Modulation)**.

---

## 🔩 Components Used

| Quantity | Component              |
|----------|------------------------|
| 1        | Arduino Uno R3         |
| 2        | Light Bulb (LEDs)      |
| 1        | 250kΩ Potentiometer    |
| 1        | 20kΩ Potentiometer     |
| 2        | 220Ω Resistors         |
| 1        | 9V Battery             |

---

## ⚡ Circuit Connections

- **Bulb (LED):**  
  - Positive → Pin 3 (PWM)  
  - Negative → GND via 220Ω resistor  

- **Potentiometer:**  
  - VCC → 5V  
  - GND → GND  
  - Output → A0  

---

## 🔁 How It Works

- The potentiometer is used as an analog input device to generate a value between 0–1023.
- This value is then **mapped** to 0–255, which corresponds to the PWM signal range.
- The `analogWrite()` function sends the PWM signal to **Pin 3**, controlling the brightness of the LED bulb.
- The current brightness value is printed on the **Serial Monitor**.


## 🖥️ Serial Monitor Output

```
You are writing a value of 132
You are writing a value of 98
```

## 🔗 Tinkercad Simulation

[Click here to open the simulation](https://www.tinkercad.com/things/0yuueCmYp6h-dimming-led-bulb)

---

## 🎬 Source/Reference Video

[Watch on YouTube](https://youtu.be/zYtWBHV62WM?si=xH87ZwN14VYVM25G)

---

## 🌍 Real-Life Applications

- Light dimmers in homes
- Volume knobs in audio devices
- Fan speed control circuits

---

## 🔮 My Future Plan

I plan to:
- Replace the bulb with a relay and control an actual AC bulb safely
- Add an LCD to display the brightness level in real time
- Integrate a remote or touch-based interface for dimming control
