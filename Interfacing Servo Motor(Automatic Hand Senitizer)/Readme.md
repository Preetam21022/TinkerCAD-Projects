# Interfacing Servo Motor (Automatic Hand Sanitizer)

This project demonstrates how to use a **servo motor** and an **ultrasonic distance sensor** to simulate an **automatic hand sanitizer dispenser**. When a hand is placed 2–4 cm away from the sensor, the servo rotates to simulate dispensing and resets after a delay.

## 🧰 Components Used

| Component                    | Quantity | Description                            |
|------------------------------|----------|----------------------------------------|
| Arduino Uno R3               | 1        | Microcontroller board                   |
| Ultrasonic Distance Sensor   | 1        | HC-SR04 (4-pin)                         |
| Continuous Micro Servo Motor | 1        | Used for motion (PWM controlled)        |
| Jumper Wires                 | Several  | For connections                         |
| Breadboard (optional)        | 1        | For assembling the circuit              |

## 🔌 Circuit Connections

- **Trig pin** of sensor → Arduino **pin 2**
- **Echo pin** of sensor → Arduino **pin 3**
- **Servo signal pin** → Arduino **PWM pin 5**
- **Sensor VCC** → **5V**
- **Sensor GND & Servo GND** → **GND**

## ⚙️ How It Works

1. The **ultrasonic sensor** sends out a sound pulse and waits for it to bounce back.
2. Distance is calculated using the formula:  
   `Distance = (Time × 0.034) / 2`
3. If an object (e.g., a hand) is detected between **2 cm to 4 cm**:
   - The servo motor rotates to simulate dispensing:
     - Rotates to **0°**
     - Waits
     - Goes back to **90°** (idle)
     - Then to **180°**
     - Then back to **90°** again

4. If no object is detected in range:
   - Servo is **detached** to save power and prevent unnecessary movement.

> 🔁 This process repeats every 0.5 seconds.

## 📐 Distance Formula Explained

- **Speed of sound** in air = 0.034 cm/µs
- **Formula**:  
  `Distance = (Duration × 0.034) / 2`  
  We divide by 2 because the signal travels to the hand and back.

## 💻 Tinkercad Simulation

🔗 [Click to open Tinkercad simulation](https://www.tinkercad.com/things/jXpBLpIxQhH-interfacing-servo-motorautomatic-hand-senitizer)

## 📺 Project Inspiration

🎥 [Watch the original project video](https://youtu.be/wB7nkLM9MPk?si=chj-swPPzEOtaD_g)

---

## 🧭 Real-Life Applications

- **Automatic hand sanitizer dispensers**
- **Touchless soap dispensers**
- **Smart faucets** with IR/ultrasonic sensors
- **Automatic pet feeders** with distance detection

---

## 🔧 Future Upgrades I Will Work On

- I will add an **IR sensor** to reduce false triggering in crowded areas.
- I plan to add **LED indicators** for system status (ready, in use, error).
- I will design a **3D printed enclosure** for real-world deployment.
