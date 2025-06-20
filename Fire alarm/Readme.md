# Fire Alarm System Using Arduino

This project simulates a basic fire alarm system using a gas sensor and a temperature sensor. It detects dangerous gas levels and high temperatures, then responds by activating LEDs and a buzzer. The system provides real-time monitoring and alerts, ideal for safety learning in embedded systems.

🧰 Required Components
---

Arduino Uno R3

Gas Sensor (e.g., MQ2)

Temperature Sensor (TMP36)

Piezo Buzzer

Blue LED

Red LED

1 × 1kΩ Resistor (for gas sensor)

2 × 220Ω Resistors (for LEDs)

Jumper wires

Breadboard

🔌 Circuit Connections
----
| Component           | Arduino Pin |
|--------------------|-------------|
| Gas Sensor (Analog)| A1          |
| Temperature Sensor | A0          |
| Blue LED           | D4          |
| Red LED            | D7          |
| Buzzer (Piezo)     | D2          |

Note: Use a 1kΩ resistor with the gas sensor and 220Ω resistors with LEDs.

⚙️ How It Works
-------
Temperature Monitoring
The TMP36 sensor outputs voltage based on ambient temperature. The code converts this to Celsius.

Gas Detection
The gas sensor reads analog values to detect the presence of gas.

Alert Conditions

If temperature < 10°C → Blue LED turns on (too cold).

If temperature > 40°C or gas level ≥ 100 → Red LED and buzzer activate (danger alert).

Serial Monitor Output
The temperature (in °C) and gas sensor readings are printed every second.

💻 Tinkercad Simulation
-----
🔗 [Click to open simulation in Tinkercad](https://www.tinkercad.com/things/gm912P1NuBT-fire-alarm)

📺 Project Inspiration / Reference
----
🎥 [Watch the original video tutorial](https://youtu.be/fwwI4R_97DI?si=AWYpawvV2IXtobLx)

🧭 Real-Life Applications
----
Basic home fire detection system prototype

Safety systems for labs and small rooms

Educational tool for understanding sensor integration

Entry-level gas and temperature alert system simulation

🔧 Future Upgrades I Will Work On
------
I will add a 16x2 LCD to display live temperature and gas readings without using the Serial Monitor.

I plan to include pushbuttons to triggering emergency alarm and a manual reset button to stop the buzzer after alerts.

I will add an RGB LED for clearer status display: green (safe), yellow (warning), red (danger).

I’ll try to include a motion sensor in future to auto-trigger alerts only when someone is in the room.

