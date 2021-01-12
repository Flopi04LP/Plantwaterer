// Relais Steuerpin an Arduino 8
const int relaisPin = 3;
 
void setup() {
  Serial.begin(9600);
  pinMode(ledRed, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(relaisPin, OUTPUT);
  Serial.println("TEST");
  pinMode(relaisPin, OUTPUT);
}
 
void loop() {
  for (int i = 0; i <= 100; i++) 
 { 
   sensorValue = sensorValue + analogRead(SensorPin); 
   delay(1); 
 } 
 sensorValue = sensorValue/100.0; 
 Serial.println(sensorValue); 
 delay(30); 

 
}
