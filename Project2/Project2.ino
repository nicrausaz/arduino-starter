// init state of button
int switchState = 0;

void setup() {
  //init inputs/outputs
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(2, INPUT);
}

void loop() {
  // switchState = LOW(-) or HIGH(+)
  switchState = digitalRead(2);
  if (switchState == LOW) {
    digitalWrite(3, HIGH); // Green LED on
    digitalWrite(4, LOW); // Red LED off
    digitalWrite(5, LOW); // Red LED off

  } else {
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);

    delay(250); // sleep 1/4 seconds
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    delay (250);
  }
}
