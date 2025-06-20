# Potentiometer as a Voltage Divider

This project demonstrates the voltage divider principle using potentiometers. By rotating the potentiometer knob, you can vary the output voltage between its terminals. It’s a simple and effective project to understand how analog control works in electronics and how voltage is divided across resistive components.

## 🧰 Required Components

- 2 × 10kΩ Potentiometers  
- 2 × 5kΩ Resistors  
- 2 × 9V Batteries  
- 4 × Voltage Multimeters  
- Jumper wires  
- Breadboard  

## 🔌 Circuit Connections

- Connect one of terminal of each potentiometer at a time across the 9V battery terminals.This will become lowest resistance terminal and rotating from this to the other terminal will increase resistance as well as voltage.
- The middle (wiper) pin of each potentiometer is connected to a multimeter to observe the output voltage.
- Use 5kΩ resistors in parallel or series with the potentiometer to compare behavior.
- Multimeters (Meter1–Meter4) are used to measure:
  - Full battery voltage  
  - Voltage across fixed resistors  
  - Voltage from potentiometer wiper  

## ⚙️ How It Works

1. **Voltage Divider Principle**  
   A potentiometer is a three-terminal variable resistor. When connected across a voltage source, it acts as a voltage divider.

2. **Wiper Output**  
   Rotating the knob moves the wiper, changing the voltage at its middle pin. This allows you to control the output voltage.

3. **Observing with Multimeters**  
   - One multimeter shows full battery voltage  
   - Others show the voltage across different parts of the divider circuit  
   - You can see in real-time how the output voltage varies with knob position

## 💻 Tinkercad Simulation

🔗 [Click to open simulation in Tinkercad](https://www.tinkercad.com/things/kmKQvLrfU7N-potentiometer-as-a-voltage-divider)

## 📺 Project Inspiration / Reference

🎥 [Watch the original video tutorial](https://youtu.be/ap0gxamW8Cs?si=-JQQxBa-ckvhWX4r)

---

## 🧭 Real-Life Applications

- Volume control knobs in audio devices  
- Manual brightness adjustment in lights  
- Analog input for sensors and control systems  
- Basic analog testing and voltage calibration circuits  

---

## 🔧 Future Upgrades I Will Work On

- I will connect the potentiometer output to an Arduino analog pin to read the value digitally.  
- I’ll add an LED matrix and control its brightness using the potentiometer output  
- I plan to experiment with digital potentiometers for automated control.  
- I may add a display to show the exact voltage reading in volts using Arduino and an LCD.
