# Interfacing NeoPixel Strip with Arduino

This project demonstrates how to interface a **NeoPixel Strip** (WS2812 LEDs) with an Arduino Uno and control individual LEDs using the Adafruit NeoPixel library. The code creates a simple **color chase** animation using red, green, and blue colors.

## 🧰 Components Used

| Component        | Quantity | Description                           |
|------------------|----------|---------------------------------------|
| Arduino Uno R3   | 1        | Main microcontroller                  |
| NeoPixel Strip   | 1        | 4-pixel RGB strip (WS2812)            |
| Jumper Wires     | Several  | For wiring                            |
| Breadboard       | 1        | For circuit assembly (optional)       |

## 🔌 Circuit Connections

- **NeoPixel DIN** → Arduino **pin 2**
- **NeoPixel VCC** → Arduino **5V**
- **NeoPixel GND** → Arduino **GND**

> ⚠️ Add a 300–500Ω resistor between the Arduino data pin and the DIN pin of the NeoPixel to protect the first pixel. Also, it's recommended to add a 1000µF capacitor between VCC and GND of the strip to avoid startup current spikes.

## ⚙️ How It Works

- The NeoPixel library controls RGB LEDs over a single data line.
- The `chase()` function lights up one LED at a time in a “chasing” pattern.
- Each color (Red → Green → Blue) is shown in sequence using `strip.Color()` and `strip.show()`.

### 🚥 Color Chase Animation Logic

```cpp
for (i = 0; i < numPixels + 4; i++) {
    strip.setPixelColor(i, color);     // Light current LED
    strip.setPixelColor(i - 4, 0);     // Turn off previous LED
    strip.show();                      // Display change
    delay(500);                        // Wait before next step
}
````

The extra `+4` ensures all LEDs turn off after the chase passes through the entire strip.

## 💻 Tinkercad Simulation

🔗 [Click to open Tinkercad simulation](https://www.tinkercad.com/things/bWpCgaDVpHC-interfacing-neopixel-strip)

## 📺 Project Inspiration

🎥 [Watch the original project video](https://youtu.be/a80Vtd0Bf8c?si=r7ArvBdc3n7Hil92)

---

## 🧭 Real-Life Applications

* RGB lighting effects in costumes, toys, or displays
* Visual indicators for sensors or automation projects
* DIY LED animations in home decoration or art

---

## 🔧 Future Upgrades I Will Work On

* I will add a **pushbutton or IR remote** to change animations interactively.
* I plan to create **custom color patterns** and dynamic brightness effects.
* Later, I will add **sound-reactive lighting** using a microphone module.


