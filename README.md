# F1 Starting Grid Lights – Arduino

A small-scale replica of the Formula 1 start sequence on an Arduino UNO. Press the button and the red lights come on stage by stage with a beep, hold for a **random** time, then all go out together: lights out and away we go.

[▶ Video of the build on LinkedIn](https://www.linkedin.com/in/jason-tapiwanashe-mungure)

## How it works
1. **Button press** (pin 2) starts the sequence.
2. **Four light stages** switch on one after another, 1 s apart, each with a 1 kHz beep.
3. **Random hold**: all lights stay on for 1.0–2.0 s. As in a real F1 start, drivers can't predict the exact moment.
4. **Lights out**: all stages switch off at the same time.
5. After a short pause the system waits for the next button press.

The randomness comes from `random()`, seeded with `randomSeed(analogRead(A0))`. Without a seed, the Arduino produces the same "random" sequence after every reset. Reading an unconnected analog pin gives electrical noise, so each power-up gets a different seed.

## Wiring

| Component | Arduino pin | Notes |
|---|---|---|
| Light stage 1 (red LED) | 12 | 220 Ω series resistor |
| Light stage 2 (red LED) | 11 | 220 Ω series resistor |
| Light stage 3 (red LED) | 10 | 220 Ω series resistor |
| Light stage 4 (red LED) | 8 | 220 Ω series resistor |
| Buzzer | 6 | driven with `tone()` |
| Push button | 2 | 10 kΩ pull-down resistor to GND |
| — | A0 | leave unconnected (random seed) |

## Components
- Arduino UNO R3
- Red LEDs and 220 Ω resistors
- Buzzer
- Push button and 10 kΩ resistor
- Breadboard and jumper wires

## Development process
- Built up in three steps: button input → traffic light sequencing → F1 lights.
- Simulated in **Tinkercad** before wiring the real circuit.
- Code refactored to use a pin array and loops instead of repeated `digitalWrite` blocks, so the number of stages or the timing can be changed in one place.

## Skills demonstrated
Arduino C++ · digital I/O · pull-down input circuits · pseudo-random timing · breadboard prototyping · circuit simulation (Tinkercad)

## Author
**Jason Mungure**, Mechanical Engineering student, OVGU Magdeburg
