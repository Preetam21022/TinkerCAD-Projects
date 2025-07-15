# Smart Farm Automation With Security System


An all‑in‑one Smart Farm Controller that monitors and automates irrigation, lighting, climate, and security.  It uses soil moisture, light, temperature, humidity, motion and timing sensors, with LCD feedback, data logging, and manual overrides.

---

## 1. Project Inspiration  
Combining precision agriculture and home security, this project brings together environmental sensing, automatic actuation, and intruder detection in one compact Arduino solution.  

## 2. Problem Statement / Objective  
Farmers and hobby‑gardeners need a low‑cost, DIY system to:  
- Keep soil moisture within optimal range  
- Provide grow‑light control at night  
- Regulate temperature and humidity  
- Protect fields or greenhouses against intruders  
- Log events and allow password‑protected resets  

## 3. Project Overview  
- **Sensors**: Soil moisture, LDR (light), TMP36 (temperature), humidity pin, PIR (motion)  
- **Actuators**: Water pump, heat pump, mist sprayer, grow light, curtain motor, buzzer  
- **Interface**: 16×2 LCD displays live farm data and security messages  
- **Security**: PIR triggers buzzer and motion log; reset button shows motion history  
- **Control**: All modes auto‑cycle unless intruder is detected  
- **Data Logging**: Stores up to 20 motion start/end timestamps  

## 4. Components Used  

| Ref   | Qty | Component                                |
|-------|-----|------------------------------------------|
| U1    | 1   | Arduino Uno R3                           |
| U2    | 1   | TMP36 Temperature Sensor                 |
| SEN1  | 1   | Soil Moisture Sensor (analog)            |
| R6    | 1   | Photoresistor (LDR)                      |
| U3    | 1   | LCD 16×2 (parallel)                      |
| PIR1  | 1   | PIR Motion Sensor                        |
| U4    | 1   | ATtiny85 (motion interface)              |
| DMIST | 1   | Blue LED (mist sprayer indicator)        |
| DHEAT | 1   | Red LED (heat‑pump indicator)            |
| DLIGHT| 1   | Green LED (grow‑light indicator)         |
| DCURT | 1   | Orange LED (curtain motor indicator)     |
| M1    | 1   | DC Motor (curtain / pump)                |
| R1–R9 | 7   | 220 Ω Resistors                          |
| R10   | 1   | 1 k Ω Resistor                           |
| R1,R12| 2   | 10 k Ω Resistors (pull‑downs)            |
| Rpot1–3 | 3 | 250 k Ω Potentiometers (tests/calibration) |
| T1    | 1   | n‑MOSFET (pump/mist driver)              |
| D1    | 1   | Diode (motor protection)                 |
| S1    | 1   | Pushbutton (motion‑log reset)            |
| BAT1  | 1   | 9 V Battery (optional standalone power)  |

---

## 5. Circuit Diagram / Wiring  
*(Simulated in Tinkercad — see link in repo)*  
- **Farm loop**:  
  - Soil Sensor → A0  
  - Light Sensor (LDR) → A4  
  - Temp Sensor (TMP36) → A2  
  - Humidity → A1  
  - Pump → D9 (PWM) via MOSFET  
  - Heat Pump → D8  
  - Mist → D7  
  - Grow Light → D13  
  - Curtain Motor → D10 via motor driver  
- **Security loop**:  
  - PIR → D0  
  - Buzzer → A5  
  - Reset Button → D6 (+10 kΩ pull‑down)  
- **Interface**:  
  - LCD RS,E,D4–D7 → D12, D11, D5, D4, D3, D2  

---

## 6. Code Explanation  

1. **Initialization**  
   - Set pinModes for all sensors, actuators, and LCD.  
   - Run `Starting()` to calibrate PIR (5 s) and show “SYSTEM ACTIVATED.”  

2. **Intruder Detection**  
   - On PIR HIGH: sound buzzer (`n` pulses), log start timestamp, display “Motion Detected at X sec.”  
   - On PIR LOW: after `pause` ms of LOW, log end timestamp, display “Motion ended at Y sec.”  
   - Holding the reset button (`S1`) prints all logged motion events to Serial, resets timer and logs.  

3. **Farm Automation (when no intruder)**  
   - **Soil**: if dry (`soil < 400`), run pump at speed from `rpm` sensor.  
   - **Temperature**: convert TMP36 output → °C; control `heatPump` and `mist` (if too hot/cold).  
   - **Light**: map LDR → brightness %;  
     - brightness < 50% → grow light ON, curtain OPEN  
     - > 70% → light OFF, curtain CLOSE  
   - **Safety Alert**: if eco‑parameter out of safe bounds, continuous buzzer.  
   - **Display**: LCD shows `T:xx°C  L:yy%` (line 1) and `H:zz%  S:aa` (line 2).  

4. **Logging & Serial**  
   - Every 1 s, print sensor raw/converted values.  
   - Motion events stored in two arrays up to 20 entries.  

---

## 7. Working Demonstration  
1. On power‑up, LCD shows calibration progress.  
2. In normal mode, live data updates on LCD every second.  
3. If motion is detected, farm actions pause and security mode engages.  
4. Hold **Reset** button for > 1 s to view motion log in Serial and clear timers.  
5. Release button to resume farm control.  

---

## 8. Challenges Faced  
- **Resource Constraints**: Managing many sensors and actuators on limited I/O.  
- **Timing Conflicts**: Balancing farm loop delays with intruder logging.  
- **Power Management**: Simulating MOSFET‑driven loads in Tinkercad.  
- **LCD Flicker**: Clearing and redrawing without excessive flicker.  

---

## 9. Future Improvements  
- Add **servo‑based auto door lock** on security breach.  
- Integrate **fire detection (gas sensor + alarm)** for safety.  
- Swap to **I²C LCD** (PCF8574) to free digital pins.  
- Store farm settings and logs in **EEPROM** for persistence.  
- Extend to **Wi‑Fi** or **Bluetooth** for remote monitoring.  

---

*Simulation link:* https://www.tinkercad.com/things/2Pwhh9EOvcz-smart-farm-automation  
