# Arduino-F1-Starting-Lights-Sequence

## Overview
A small-scale replica of the Formula 1 starting grid light sequence built with Arduino UNO.
4 pairs of red LEDs that light up one by one, pause for a randomised delay, 
then turn off simultaneously to simulate a race start.

## Components Used
- Arduino UNO R3
- 8x Red LEDs
- 8x 220Ω resistors
- Breadboard
- Jumper wires

## How It Works
- Each pair of LEDs is connected to a separate digital output pin (8, 10, 11, 12)
- LEDs illuminate sequentially with a 1 second delay between each
- A randomised delay (1000–3000ms) simulates the unpredictable lights-out moment
- All LEDs turn off simultaneously to signal the race start
- Sequence loops continuously

## Skills Demonstrated
- Arduino IDE programming
- Circuit design and breadboard wiring
- Digital output control
- Randomised timing logic

## Author
Jason: Mechanical Engineering Student, OVGU Magdeburg
