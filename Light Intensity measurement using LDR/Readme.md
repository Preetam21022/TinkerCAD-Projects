# Light Intensity Measurement Using LDR

There are two projects demonstrate how to measure light intensity using a photoresistor (LDR) and Arduino. The light level is printed on the Serial Monitor, and the brightness of a red LED is adjusted based on ambient light. It's an ideal project for learning how to interface analog sensors and use PWM for LED control.

## ❓Question
Question: Why the value of maximum intensity differed?

## 🧰 Required Components

- Arduino Uno R3 (×2, if simulating multiple circuits in Tinkercad)  
- 2 × Photoresistors (LDR)  
- 2 × Red LEDs  
- 4 × 220Ω Resistors  
- 2 × Voltage Multimeters (optional, for monitoring)  
- Jumper wires  
- Breadboard  

## 🔌 Circuit Connections

| Component       | Arduino Pin |
|----------------|-------------|
| LDR (via voltage divider) | A0  |
| Red LED         | D10         |

> **Note:** Connect each LDR with a 220Ω resistor to form a voltage divider before connecting to A0.

## ⚙️ How It Works

1. **Reading Light Intensity**  
   The LDR forms a voltage divider. The voltage at A0 changes based on the amount of light falling on the sensor.

2. **Serial Monitor Output**  
   The raw analog value from A0 (range: 0–1023) is printed to the Serial Monitor every 100ms.

3. **LED Brightness Control**  
   - The analog value is mapped from 0–1023 to 0–255.  
   - This mapped value is used to set LED brightness via `analogWrite()` on pin 10.  
   - As light increases, LED brightness decreases, mimicking a basic auto-dimming light.

## 💻 Tinkercad Simulation

🔗 [Click to open simulation in Tinkercad](https://www.tinkercad.com/things/2cccGfRiNVK-light-intensity-measurement-using-ldr)

## 📺 Project Inspiration / Reference

🎥 [Watch the original video tutorial](https://youtu.be/4ibf6wHOIok?si=u74x_7mZFrJHzaAD)

---

## 🧭 Real-Life Applications

- Smart lighting systems that adjust based on room brightness  
- Light-activated garden or street lights  
- Ambient light monitoring in indoor environments  
- Educational analog-to-digital conversion projects  

---

## 🔧 Future Upgrades I Will Work On

- I will add an LCD to display light intensity readings directly without a computer.  
- I plan to use multiple LDRs to measure light from different directions and average the result.  
- I will include a pushbutton to toggle between automatic and manual brightness control.  
- I may experiment with RGB LEDs to change color based on different light levels.




