# Digital Thermometer & Fire Alarm System

This project integrates a digital thermometer and a fire alarm system using an Arduino Uno. It reads temperature using a TMP36 sensor and monitors air quality with a gas sensor. A 16x2 LCD shows real-time temperature, and emergency alerts are triggered through LEDs and a buzzer if dangerous conditions are detected.

## 🧰 Required Components

- Arduino Uno R3  
- TMP36 Temperature Sensor  
- Gas Sensor (e.g., MQ2)  
- RGB LED  
- Piezo Buzzer  
- 1 × 16x2 LCD Display  
- 1 × 250kΩ Potentiometer (for LCD contrast)  
- 1 × 1kΩ Resistor (for gas sensor)  
- 2 × 220Ω Resistors (for LEDs)  
- Jumper wires  
- Breadboard  

## 🔌 Circuit Connections

| Component         | Arduino Pin |
|------------------|-------------|
| Temperature Sensor (OUT) | A0      |
| Gas Sensor (OUT)         | A1      |
| Red LED (RGB)            | D8      |
| Green LED (RGB)          | D10     |
| Blue LED (RGB)           | D9      |
| Buzzer                   | D2      |
| LCD (RS, E, D4-D7)       | D13, D12, D4, D5, D6, D7 |
| Potentiometer (middle pin) | LCD V0 |

> **Note:** Use a 1kΩ resistor with the gas sensor, and 220Ω resistors with the RGB LED pins.

## ⚙️ How It Works

1. **Analog Readings**
   - The TMP36 outputs a voltage based on ambient temperature.
   - The gas sensor outputs a voltage that increases in the presence of smoke or gas.

2. **Temperature Calculation**
   - TMP36 outputs **0.5V at 0°C** with **10mV/°C**.
   - The Arduino reads analog value (0–1023) and converts it to voltage:
     ```
     Voltage = analogRead × 5 / 1024
     ```
   - Then temperature in Celsius:
     ```
     Celsius = (Voltage − 0.5) × 100
     ```

3. **LCD Display**
   - The temperature is displayed on the 16x2 LCD.
   - In emergencies, the LCD shows warning messages.

4. **Emergency Conditions**
   - **Temperature < 10°C:** Cold alert → Blue LED + Buzzer + LCD Warning  
   - **Temperature > 40°C:** High Temp Alert → Red LED + Buzzer  
   - **Gas Level ≥ 100:** Smoke Alert → Red LED + Buzzer  
   - **Both Smoke and High Temp:** Fire Alert → Red LED + LCD Fire Message + Buzzer  

5. **Serial Monitor Output**
   - The system also prints temperature and gas sensor values via Serial Monitor every second.

## 💻 Tinkercad Simulation

🔗 [Click to open simulation in Tinkercad](https://www.tinkercad.com/things/8ypzi9x6ZuC-digital-thermometer-amp-fire-alarm-system)

## 📺 Project Inspiration / Reference

🎥 [Watch the original video tutorial](https://youtu.be/RTNcZSVdwLY?si=CgLgIkbpRNOoamXr)

---

## 🧭 Real-Life Applications

- Fire detection and smoke alarm systems  
- Room and server temperature monitoring  
- Home or lab automation and safety tools  
- Embedded system training kits for safety response  

---

## 🔧 Future Upgrades I Will Work On

- I will add a 16x2 I2C LCD module to save digital pins and simplify wiring.  
- I will integrate a DHT22 sensor to include humidity monitoring.  
- I plan to store sensor data to an SD card for logging and later analysis.  
- I will implement a GSM module to send SMS alerts during emergencies.
