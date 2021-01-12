const int relaisPin = 3;
const int ledRed = 11;
const int ledYellow = 12;
const int ledGreen = 13;
#define MoisturePin A0 
#define WaterPin A5
float moistureValue = 0; 
float waterValue = 0;


void setup() {
  Serial.begin(9600);
  pinMode(ledRed, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(relaisPin, OUTPUT);
  Serial.println("Waterplanter 3000 started");
  pinMode(relaisPin, OUTPUT);
  digitalWrite(ledRed, HIGH);
}
 
void loop() {
  for (int i = 0; i <= 100; i++) 
 { 
   moistureValue = moistureValue + analogRead(MoisturePin); 
   waterValue = waterValue + analogRead(WaterPin); 
   delay(1); 
 } 
 moistureValue = moistureValue/100.0;
 Serial.println("Moisture:"); 
 Serial.println(moistureValue); 
 waterValue = waterValue/100.0; 
 Serial.println("Water level:"); 
 Serial.println(waterValue); 
 
 delay(30); 

 
}
