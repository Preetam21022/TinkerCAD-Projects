# Interfacing NeoPixel Jewel with Arduino

This project showcases how to use an Arduino to drive a NeoPixel Jewel (a circular arrangement of 7 WS2812 RGB LEDs). With the help of the Adafruit NeoPixel library, you can create colorful animations like color wipes, rainbows, and theater chases.

## 🧰 Required Components

- NeoPixel Jewel (7 WS2812 LEDs)  
- Arduino or ATtiny microcontroller  
- 2.2kΩ Resistor (for data line protection)  
- 1µF, 16V Electrolytic Capacitor (across VCC and GND)  
- USB Type A power connector  
- Pushbutton (optional for interactivity)  
- IR sensor (optional, included in Tinkercad layout)  
- Breadboard and jumper wires  

## 🔌 Circuit Connections

| Component       | Description                         |
|----------------|-------------------------------------|
| NeoPixel DIN    | Digital Pin 1 (or any PWM-capable)  |
| NeoPixel VCC    | 5V (from Arduino or USB)            |
| NeoPixel GND    | GND                                 |
| 2.2kΩ Resistor  | Between Arduino pin and NeoPixel DIN|
| 1µF Capacitor   | Across NeoPixel VCC and GND         |

> **Important:** Always connect GND before applying power to NeoPixels to prevent voltage spikes.

## ⚙️ How It Works

1. **NeoPixel Initialization**  
   The `Adafruit_NeoPixel` library is used to set up the strip with 7 LEDs. The data pin is defined, and timing is handled internally.

2. **Color Effects**  
   - **Color Wipe**: Fills the strip one pixel at a time with red, green, or blue.  
   - **Theater Chase**: Blinking lights like theater marquees.  
   - **Rainbow**: Smooth color flow across the pixels.  
   - **Rainbow Cycle**: Loops through the color spectrum.  
   - **Theater Chase Rainbow**: Combines theater effect with rainbow colors.

3. **Custom Functionality**  
   The `Wheel()` function maps color transitions between Red → Green → Blue and cycles smoothly through the RGB spectrum.

## 💻 Tinkercad Simulation

🔗 [Click to open simulation in Tinkercad](https://www.tinkercad.com/things/bzWjIEaTlXQ-interfacing-neopixel-jewel)

## 📺 Project Inspiration / Reference

🎥 [Watch the original video tutorial](https://youtu.be/PpIga1yRjRg?si=nRwPNNydf9yaGHVB)

---

## 🧭 Real-Life Applications

- RGB visual indicators in wearable tech  
- Creative lighting for DIY decorations  
- Status indicators for smart systems  
- Educational RGB programming exercises  

---

## 🔧 Future Upgrades I Will Work On

- I will add a pushbutton to change modes interactively.  
- I plan to control the NeoPixel Jewel using an IR remote and the included IR sensor.  
- I’ll test brightness control and power-saving animations.  
- I’ll expand the setup to multiple Jewels for advanced patterns.
