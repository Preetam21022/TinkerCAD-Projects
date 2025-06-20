# Interfacing Temperature Sensor using Arduino

This project demonstrates how to interface a TMP36 temperature sensor with an Arduino Uno to read real-time temperature. The analog voltage from the sensor is read, converted into Celsius and Fahrenheit, and printed on the Serial Monitor. This is a beginner-friendly project for learning how analog sensors provide measurable physical data.

## 🧰 Required Components

- Arduino Uno R3  
- TMP36 Temperature Sensor  
- Jumper wires  
- Breadboard  

## 🔌 Circuit Connections

| TMP36 Pin | Connected To     |
|-----------|------------------|
| VCC       | 5V (Arduino)     |
| GND       | GND (Arduino)    |
| OUT       | A0 (Arduino)     |

## ⚙️ How It Works

1. **Analog Voltage Reading**  
   The TMP36 outputs an analog voltage that increases with temperature. This voltage is read using `analogRead(A0)`.

3. **Voltage Conversion**  
   The analog reading (0–1023) is converted to voltage:
   
   ```
    Voltage = analogRead × 5 / 1024
   ```
5. **Temperature Conversion**  
- TMP36 has a scale factor of **10 mV/°C** and an offset of **0.5 V**.
- The offset voltage is a fixed value added to the voltage output by the sensor, and it represents the voltage at 0°C. Therefore, to calculate the actual temperature, you need to subtract this offset from the measured voltage before converting it to Celsius.   
- To convert voltage to Celsius:
  ```
  Celsius = 100 × (Voltage − 0.5)
  ```
- To convert Celsius to Fahrenheit:
  ```
  Fahrenheit = (Celsius × 9/5) + 32
  ```

4. **Serial Monitor Output**  
The Arduino prints:
- Raw analog reading  
- Voltage reading  
- Temperature in Celsius and Fahrenheit  

## 💻 Tinkercad Simulation

🔗 [Click to open simulation in Tinkercad](https://www.tinkercad.com/things/034nbj4cssd-interfacingtemperature-sensor-using-arduino)

## 📺 Project Inspiration / Reference

🎥 [Watch the original video tutorial](https://youtu.be/Lk_oFu-3aw4?si=E0jiF9rHVmNAXMA5)

---

## 🧭 Real-Life Applications

- Room temperature monitoring  
- Home automation and HVAC systems  
- Educational experiments and data logging  
- Basic climate sensing in embedded projects
- Fire Alert System

---

## 🔧 Future Upgrades I Will Work On

- I will add an LCD screen to display temperature directly without needing the Serial Monitor.  .  
- I will try logging temperature data to an SD card for long-term analysis.  
- I may integrate a fan control system to react to rising temperatures automatically.
