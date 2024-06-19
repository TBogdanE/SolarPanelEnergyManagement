#include <Arduino.h>
#include "modules/temperatureSensor/temperature.h"
#include "modules/temperatureSensor/temperature.cpp"
#include "modules/photoresistorSensor/ldr.h"
#include "modules/photoresistorSensor/ldr.cpp"

#define DHT_PIN 9
#define DHT_TYPE DHT11
#define LDR_PIN A1

TemperatureSensor tempSensor(DHT_PIN, DHT_TYPE);
LDRSensor ldrSensor(LDR_PIN);

class Data {

    public:
        int relay1;
        int relay2;
        int relay3;
        int relay4;
        int socketRelay;
        int invtobatRelay;
        int paneltoinvRelay;
        float temperatureValue;
        float humidityValue;
        float brightnessValue;
        float windValue;
        float currentValue;
        Data() : relay1(false), relay2(false), relay3(false), relay4(false),
                 socketRelay(false), invtobatRelay(false), paneltoinvRelay(false), temperatureValue(0),
                 humidityValue(0), brightnessValue(0), windValue(0), currentValue(0){}
};

Data systemData;

void setup() {
    Serial.begin(9600);
    tempSensor.begin();
}

void loop() {
    systemData.temperatureValue = tempSensor.readTemperature();
    systemData.humidityValue = tempSensor.readHumidity();
    systemData.brightnessValue = ldrSensor.getLDRPercentage();

    /*Serial.print("Temperature: ");
    Serial.print(systemData.temperatureValue);
    Serial.print(" °C, Humidity: ");
    Serial.print(systemData.humidityValue);
    Serial.println(" %");*/
    Serial.print("LDR Value: ");
    Serial.print(systemData.brightnessValue);


    delay(2000);  // Adjust delay as needed
}
