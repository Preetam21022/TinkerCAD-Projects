# Interfacing NeoPixel Strip with Arduino

This project demonstrates how to control a short **NeoPixel RGB LED strip** using an **Arduino Uno**.  
It lights up the LEDs one by one in a chasing sequence, switching between red, green, and blue colors.

## 🧰 Components Used

| Component         | Quantity | Description                        |
|------------------|----------|------------------------------------|
| Arduino Uno R3    | 1       | Microcontroller board              |
| NeoPixel Strip    | 1       | 4 RGB LEDs with WS2812/WS2811 chip |
| Jumper Wires      | Several | For connections                    |

## 🔌 Circuit Connections

- NeoPixel DIN (data in) → Pin 2 of Arduino  
- NeoPixel VCC → 5V  
- NeoPixel GND → GND  

> ⚠️ Important: A **1000 µF capacitor** across VCC and GND and a **300–500Ω resistor** between Arduino Pin 2 and DIN are often recommended to protect the strip. However, Tinkercad simulation works without them.

## 🌈 How It Works

- The NeoPixel strip is initialized with `Adafruit_NeoPixel`.
- The `chase()` function lights up one LED at a time in a running pattern.
- The loop cycles through **red**, **green**, and **blue** colors, giving a chasing light animation.

### ⚙️ Chase Function Logic

```cpp
static void chase(uint32_t c) {
  for (uint16_t i = 0; i < strip.numPixels() + 4; i++) {
    strip.setPixelColor(i, c);      // Light up current LED
    strip.setPixelColor(i - 4, 0);  // Turn off the trailing LED
    strip.show();
    delay(500);
  }
}
