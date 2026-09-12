void setup() {
  // put your setup code here, to run once:
  pinMode(8,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(2, INPUT);

}

void loop() {
  int buttonstate = digitalRead(2);

  if(buttonstate == HIGH) {

    digitalWrite(12, HIGH);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    digitalWrite(8, LOW);
    tone(6, 1000, 200);
    delay(1000);

    digitalWrite(12, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(10, LOW);
    digitalWrite(8, LOW);
    tone(6, 1000, 200);
    delay(1000);

    digitalWrite(12, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(8, LOW);
    tone(6, 1000, 200);
    delay(1000);

    digitalWrite(12, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(8, HIGH);
    tone(6, 1000, 200);
    delay(random(1000, 2000));

    digitalWrite(12, LOW);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    digitalWrite(8, LOW);
    delay(5000);
  }
}
