const int relaisPin = 3;
const int ledRed = 7;
const int ledYellow = 8;
const int ledGreen = 9;
const int ledRefill = 2;
#define MoisturePin A0
#define WaterPin A5
float moistureValue = 0;
float waterValue = 0;

// if the soil is dryer than this number, then start watering
#define plantneedswater 700
#define plantneedswatersoon 600
#define watertankempty 100

void setup()
{
    Serial.begin(9600);
    pinMode(ledRed, OUTPUT);
    pinMode(ledYellow, OUTPUT);
    pinMode(ledGreen, OUTPUT);
    pinMode(ledRefill, OUTPUT);
    pinMode(relaisPin, OUTPUT);
    pinMode(relaisPin, OUTPUT);
    Serial.println("Waterplanter 3000 started");
}

void loop()
{
    for (int i = 0; i <= 100; i++) {
        // read current moisture
        moistureValue = moistureValue + analogRead(MoisturePin);
        // read current water level
        waterValue = waterValue + analogRead(WaterPin);
        delay(1);
    }

    moistureValue = moistureValue / 100.0;
    // output the moisture
    Serial.println("Moisture:");
    Serial.println(moistureValue);
    waterValue = waterValue / 100.0;
    // output the water level
    Serial.println("Water level:");
    Serial.println(waterValue);

    // the soil is too dry, water!
    if (moistureValue >= plantneedswater) {
        digitalWrite(ledGreen, LOW);
        digitalWrite(ledYellow, LOW);
        digitalWrite(ledRed, HIGH);
        Serial.println("Starting watering");
        // turn on water
        digitalWrite(relaisPin, LOW);
        delay(500);
        // turn off water
        digitalWrite(relaisPin, HIGH);
        delay(5000);
    }
    // plant is ok
    else {
        Serial.println("Plant ok");
        digitalWrite(ledRed, LOW);
        digitalWrite(ledYellow, LOW);
        digitalWrite(ledGreen, HIGH);
    }
    // plant needs water soon
    if (moistureValue >= plantneedswatersoon) {
        Serial.println("Plant needs water soon!");
        digitalWrite(ledYellow, HIGH);
        digitalWrite(ledRed, LOW);
        digitalWrite(ledGreen, LOW);
    }
    // change the led to green
    else {
        digitalWrite(ledRed, LOW);
        digitalWrite(ledYellow, LOW);
        digitalWrite(ledGreen, HIGH);
    }
    // if the water tank is nearly empty the red led turns on
    if (waterValue <= watertankempty) {
        digitalWrite(ledRefill, HIGH);
        Serial.println("Watertank empty!");
    }
    // water tank ok
    else {
        digitalWrite(ledRefill, LOW);
    }
    delay(5000);
}
