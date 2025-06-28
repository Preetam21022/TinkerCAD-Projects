# Smart Hand Sanitizer

This project creates a **smart contactless hand sanitizer system** using a **positional servo motor** and an **ultrasonic distance sensor**. When a hand is detected within 10 cm, the servo rotates to simulate dispensing, then resets to its idle position.

## 🧰 Components Used

| Component                    | Quantity | Description                             |
|------------------------------|----------|-----------------------------------------|
| Arduino Uno R3               | 1        | Microcontroller board                    |
| Ultrasonic Distance Sensor   | 1        | HC-SR04 (4-pin)                          |
| Positional Micro Servo Motor | 1        | Servo with 0°–180° movement              |
| Jumper Wires                 | Several  | For circuit connections                  |
| Breadboard (optional)        | 1        | For neat wiring                          |

## 🔌 Circuit Connections

- **Trig pin** of sensor → Arduino **pin 2**
- **Echo pin** of sensor → Arduino **pin 3**
- **Servo signal pin** → Arduino **PWM pin 5**
- **Sensor VCC** → **5V**
- **Sensor GND & Servo GND** → **GND**

## ⚙️ How It Works

1. The **ultrasonic sensor** sends out a sound pulse and waits for the echo.
2. The time taken for the echo is used to calculate distance:
```

Distance = microseconds / 29 / 2

```
3. If the distance is less than 10 cm:
- The **servo rotates to 90°** to simulate dispensing.
4. If the distance is 10 cm or more:
- The **servo returns to 0°** (rest position).
5. The system runs continuously with a 100 ms delay between checks.

## 📐 Distance Formula Explained

- The speed of sound in air is approx. **0.034 cm/µs**
- To convert time (in microseconds) to distance:
```

Distance = (Duration × 0.034) / 2

```
In this code, it’s simplified as:
```

Distance = microseconds / 29 / 2

```

## 💻 Tinkercad Simulation

🔗 [Click to open Tinkercad simulation](https://www.tinkercad.com/things/h3zB0c6bTKq-smart-hand-senitizer)

## 📺 Project Inspiration

🎥 [Watch the original project video](https://youtu.be/uzn_jqsnIJA?si=ntJWf2FJ-REVOKGl)

---

## 🧭 Real-Life Applications

- **Automatic hand sanitizer stations**
- **Touchless liquid dispensers**
- **Smart washroom hygiene systems**

---

## 🔧 Future Upgrades I Will Work On

- I will add an **LED indicator** for standby and active modes.
- I plan to add a **buzzer sound** for better feedback.
- I will calibrate the detection range for different hand sizes.
