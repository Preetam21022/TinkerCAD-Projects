# \[Ultra Sonic Sensor with RGB LED]

This project demonstrates how to use an Ultrasonic Sensor (HC-SR04) with an Arduino Uno to measure distance and visually represent it using LEDs. It’s a beginner-friendly setup that also prints live distance data to the Serial Monitor.

## 🧰 Required Components

* Arduino Uno
* HC-SR04 Ultrasonic Sensor
* RGB LED or separate Red, Green, Blue LEDs
* Resistors (220Ω)
* Breadboard
* Jumper wires

## 🔌 Circuit Connections

| Component       | Arduino Pin |
| --------------- | ----------- |
| HC-SR04 Trigger | D2          |
| HC-SR04 Echo    | D3          |
| Red LED         | D4          |
| Blue LED        | D5          |
| Green LED       | D6          |

*Note: Use separate LEDs or a common cathode RGB LED.*

## ⚙️ How It Works

1. **Signal Transmission**
   The ultrasonic sensor sends a sound pulse using the Trig pin.

2. **Echo & Distance Calculation**
   The Echo pin receives the reflected signal. Distance is calculated using:

   ```
   Distance = (Time × 0.034) / 2
   ```

3. **LED Output**
   Based on distance, the RGB LED shows:

   * Green: 50–74 cm
   * Red: 35–49 cm
   * Blue: <35 cm

4. **Serial Monitor Output**
   Real-time distance in cm is printed to the Serial Monitor.

## 💻 Tinkercad Simulation

🔗 \[Add your Tinkercad simulation link here]

## 📺 Project Inspiration / Reference

🎥 \[Add the YouTube video link or source here]

## 🧭 Real-Life Applications

* Obstacle detection in basic robots
* Parking assistance system prototypes
* Interactive sensor-based learning tools
* Simple home automation ideas

---

## 🔧 Future Upgrades I Will Work On

* I will add a buzzer to alert users when objects are too close.
* I plan to integrate a 16x2 LCD screen to show distance without needing a computer.
* I will try rotating the sensor with a servo motor to create a basic radar system.
* I will improve the RGB LED output using PWM for smooth fading based on distance.

---