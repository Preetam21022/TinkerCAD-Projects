# Motion Controlled Colour Changer

This Arduino-based project changes the color of RGB LEDs when motion is detected using a PIR sensor. It also activates a piezo buzzer to alert on motion. Ideal for beginner-friendly motion alert systems or ambient light changers based on human presence.

## 🔩 Components Used

| Quantity | Component              |
|----------|------------------------|
| 1        | Arduino Uno R3         |
| 3        | RCBG RGB LEDs          |
| 1        | PIR Motion Sensor      |
| 1        | Piezo Buzzer           |
| 9        | 220Ω Resistors         |

## ⚙️ Circuit Connections

- **PIR Sensor** connected to digital pin **7**
- **Piezo Buzzer** connected to pin **6**
- **RGB LEDs** connected as:
  - **Red** → Pin 2  
  - **Blue** → Pin 3  
  - **Green** → Pin 4  
- Each LED pin goes through a 220Ω resistor

> ⚠️ Note: RCBG LEDs are used instead of RCGB, so colors must be assigned using `RBG_color()` in the code.

## 🧠 How It Works

- When **no motion** is detected:
  - RGB LEDs display **magenta**
  - Buzzer is OFF

- When **motion is detected**:
  - RGB LEDs change to **blue**
  - Buzzer turns ON
  - System waits until motion stops before changing state again

## 🖥️ Serial Monitor Output

This version does not use serial output but relies on visual and audio feedback via RGB LEDs and buzzer.

## 🔗 Tinkercad Simulation

[Click here to open simulation](https://www.tinkercad.com/things/8K9EcKHfNF0-motion-controlled-colour-changer)

## 🎥 Source/Reference Video

[Watch on YouTube 1](https://youtu.be/KbChIqEH3qI?si=PkuAL6mB_xNHYZIL)
[Watch on YouTube 2](https://youtu.be/YyA0JHWJY-g?si=dpXOHkMQwdn2HWi1)

## 💡 Real-Life Applications

- Motion-activated decorative lighting
- Room occupancy alerts
- Smart home visual alarms

## 🔮 My Future Plan

I plan to:
- Add a display to show real-time motion status
- Log motion events using an SD card module
- Add more LED strips for better visual feedback
- Use standard RCGB LEDs to make RGB control more intuitive
