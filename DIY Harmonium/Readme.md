# DIY Harmonium

This project recreates a simple 13-key harmonium using Arduino Uno, pushbuttons, and a piezo buzzer. Each button corresponds to one musical note from an octave, including both shuddha (natural), komal (flat), and kori (sharp) swaras based on Indian classical music.

## 🧰 Components Used

| Component     | Quantity | Description                     |
|--------------|----------|---------------------------------|
| Arduino Uno  | 1        | Microcontroller                 |
| Pushbuttons  | 13       | One for each note               |
| Piezo Buzzer | 1        | To produce sound                |
| Resistors    | 13       | 220Ω pull-down resistors        |
| Breadboard   | 1        | For assembling the circuit      |
| Jumper Wires | Several  | For connections                 |

## 🔌 Circuit Connections

- Each pushbutton is connected to a digital/analog pin (A4, A5, 2–12).
- The other side of each button goes to GND through a resistor.
- The piezo buzzer is connected to pin 13 (`bP` in code).
- All components share a common GND.

## 🎶 How It Works

- When a button is pressed, it triggers a tone using the `tone()` function.
- The pitch of the tone is matched to the corresponding musical note.
- Each note's frequency is defined using a `struct Note` array.

### 🎵 Notes and Frequencies

| Note Name | Type   | Frequency (Hz) |
|-----------|--------|----------------|
| Sa        | Shuddha | 261.63         |
| Re*       | Komal   | 277.18         |
| Re        | Shuddha | 293.66         |
| Ga*       | Komal   | 311.13         |
| Ga        | Shuddha | 329.63         |
| Ma        | Shuddha | 349.23         |
| Ma*       | Tivra   | 369.99         |
| Pa        | Shuddha | 392.00         |
| Dha*      | Komal   | 415.30         |
| Dha       | Shuddha | 440.00         |
| Ni*       | Komal   | 466.16         |
| Ni        | Shuddha | 493.88         |
| Sa*       | Shuddha | 523.25         |

## 💻 Tinkercad Simulation

🔗 [Click to open Tinkercad simulation](https://www.tinkercad.com/things/3TvFShec0r7-harmonium)

## 📺 Project Inspiration

🎥 [Watch the original project video](https://youtu.be/mPCI9Ln15rc?si=Py8VV5NOamAqN9lD)

---

## 🧭 Real-Life Applications

- Teaching basic music theory and swaras
- Digital harmonium or synth learning tool
- Embedded sound project experiments
- Fun DIY musical instrument for kids and beginners

---

## 🔧 Future Upgrades I Will Work On

- I’ll add **octave selection** using an extra button to switch between high and low tones.
- I plan to include an **LCD screen** to show the name of the note being played.
- I may use **velocity-sensitive input (pressure-based)** for advanced dynamics.
- I will try recording and replaying note sequences using Arduino memory.
