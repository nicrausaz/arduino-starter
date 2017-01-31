const int sensorPin = A0;
const float baseTemp = 20.0;

void setup() {
  Serial.begin(9600); //open serial port
  for (int i = 3; i <= 5; i++) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  int sensorValue = analogRead(sensorPin); //get sensor value
  float voltage = (sensorValue / 1024.0) * 5.0; //convert sensor value with CAN
  float temperature = (voltage - .5) * 100; //convert voltage to Celsius

  printSerial(sensorValue, voltage, temperature);
  delay(2000);

  if (temperature < baseTemp) {
    // Less than 20C -- 1LED
    lightItUp(1);

  } else if (temperature >= baseTemp && temperature <= baseTemp + 4) {
    // Between 20C and 24C -- 2LED
    lightItUp(2);

  } else {
    // More than 24C -- 3LED
    lightItUp(3);
  }
}

void printSerial(int sensorValue, float voltage, float temperature) {
  Serial.print("value: ");
  Serial.println(sensorValue);
  Serial.print("voltage: ");
  Serial.println(voltage);
  Serial.print("Celsius: ");
  Serial.println(temperature);
}

void lightItUp(int number) {
  if (number == 1) {
    digitalWrite(3, HIGH);
  } else if (number == 2) {
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  } else {
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
  }
}

