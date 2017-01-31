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

  delay(5000);
}
