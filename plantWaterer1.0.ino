const int relaisPin = 3;
const int ledRed = 11;
const int ledYellow = 12;
const int ledGreen = 13;
#define SensorPin A0 
#define WaterPin A5
float sensorValue = 0; 


void setup() {
  Serial.begin(9600);
  pinMode(ledRed, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(relaisPin, OUTPUT);
  pinMode(SensorPin, INPUT); // ?
  Serial.println("TEST");
  
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

 if (sensorValue > 1000){
 Serial.println("the soil sensor is currently in the air");
 }
  
  if (sensorValue > 750 && sensorValue < 1000){
  Serial.println("Es ist Zeit, die Pflanze zu bewässern");
  digitalWrite(relaisPin, HIGH);
  delay(5000);  
  digitalWrite(relaisPin, LOW);  
  }
  
}
