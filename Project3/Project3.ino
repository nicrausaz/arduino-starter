const int sensorPin = A0;
const float baseTemp = 20.0;

void setup() {
  Serial.begin(9600); //open serial port
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop() {
  int sensorValue = analogRead(sensorPin); //get sensor value
  Serial.print(" value ");
  Serial.print(sensorValue);

  //convert sensor value with CAN
  float voltage = (sensorValue / 1024.0) * 5.0;
  Serial.print(" ,voltage ");
  Serial.print(voltage);

  //convert voltage to Celsius
  float temperature = (voltage - .5) * 100;
  Serial.print(" ,Celsius ");
  Serial.print(temperature);

  delay(2000);

  if (temperature < baseTemp) {
    // Less than 20C -- 1LED
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  } else if (temperature >= baseTemp && temperature <= baseTemp + 4) {
    // Between 20C and 24C -- 2LED
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
  } else {
    // More than 24C -- 3LED
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
  }
}
