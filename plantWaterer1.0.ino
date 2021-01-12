const int relaisPin = 3;
const int ledRed = 11;
const int ledYellow = 12;
const int ledGreen = 13;
#define SensorPin A0 
float sensorValue = 0; 


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
