/*
  F1 Starting Grid Lights Sequence
  --------------------------------
  Author: Jason Mungure

  Press the button and the red lights come on one stage at a time, each with a
  beep. After the last stage, a RANDOM delay follows, then all lights go out
  together - "lights out and away we go".

  Hardware (see README for the full wiring table):
    - 4 LED stages on pins 12, 11, 10, 8 (each through a 220 ohm resistor)
    - buzzer on pin 6
    - push button on pin 2 with a 10 kohm pull-down resistor
      (pin reads LOW when released, HIGH when pressed)
*/

// ---------------------------------------------------------------------------
// Pin assignments
// ---------------------------------------------------------------------------
// The stages light up in the order they appear in this array.
const int LIGHT_PINS[] = {12, 11, 10, 8};
const int NUM_LIGHTS   = 4;

const int BUZZER_PIN = 6;
const int BUTTON_PIN = 2;

// ---------------------------------------------------------------------------
// Timing (milliseconds)
// ---------------------------------------------------------------------------
const int STAGE_DELAY_MS   = 1000;  // time between light stages
const int BEEP_FREQ_HZ     = 1000;  // beep pitch
const int BEEP_LENGTH_MS   = 200;   // beep duration
const int LIGHTS_OUT_MIN   = 1000;  // shortest random hold before lights out
const int LIGHTS_OUT_MAX   = 2000;  // random() excludes the upper limit -> max 1999 ms
const int RESET_DELAY_MS   = 500;   // pause before the next start can be triggered

void setup() {
  for (int i = 0; i < NUM_LIGHTS; i++) {
    pinMode(LIGHT_PINS[i], OUTPUT);
  }
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);       // external 10 kohm pull-down resistor

  // random() is a pseudo-random generator: without a seed it produces the SAME
  // sequence after every reset, so the "random" lights-out time would be
  // predictable. Reading an unconnected analog pin gives electrical noise,
  // which makes a different seed on each power-up.
  randomSeed(analogRead(A0));       // A0 must be left unconnected
}

void loop() {
  if (digitalRead(BUTTON_PIN) == HIGH) {
    startSequence();
  }
}

// Runs one full start: lights on stage by stage, random hold, lights out.
void startSequence() {
  // 1. Turn the stages on one after another, with a beep for each.
  for (int i = 0; i < NUM_LIGHTS; i++) {
    digitalWrite(LIGHT_PINS[i], HIGH);
    tone(BUZZER_PIN, BEEP_FREQ_HZ, BEEP_LENGTH_MS);

    // After the last stage, skip the fixed delay: the random hold follows.
    if (i < NUM_LIGHTS - 1) {
      delay(STAGE_DELAY_MS);
    }
  }

  // 2. Hold all lights on for a random time, so the start cannot be anticipated.
  delay(random(LIGHTS_OUT_MIN, LIGHTS_OUT_MAX));

  // 3. Lights out - all stages off at the same moment.
  for (int i = 0; i < NUM_LIGHTS; i++) {
    digitalWrite(LIGHT_PINS[i], LOW);
  }

  delay(RESET_DELAY_MS);
}
