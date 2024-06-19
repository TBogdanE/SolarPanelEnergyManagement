#include <Arduino.h>
#include "modules/temperatureSensor/temperature.h"
#include "modules/temperatureSensor/temperature.cpp"
#include "modules/photoresistorSensor/ldr.h"
#include "modules/photoresistorSensor/ldr.cpp"
#include "modules/thermistorSensor/thermistor.h"
#include "modules/thermistorSensor/thermistor.cpp"
#include "modules/infraredSensor/infrared.h"
#include "modules/infraredSensor/infrared.cpp"
#include "modules/voltageSensor/voltageSensor.h"
#include "modules/voltageSensor/voltageSensor.cpp"

#define DHT_PIN 9
#define DHT_TYPE DHT11
#define LDR_PIN A1
#define THER_PIN A3
#define IR_PIN A4
#define V_PIN A0

TemperatureSensor tempSensor(DHT_PIN, DHT_TYPE);
LDRSensor ldrSensor(LDR_PIN);
ThermistorSensor thermSensor(THER_PIN);
InfraredSensor irSensor(IR_PIN);
VoltageSensor vSensor(V_PIN);

class Data
{

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
    float voltageValue;
    Data() : relay1(false), relay2(false), relay3(false), relay4(false),
             socketRelay(false), invtobatRelay(false), paneltoinvRelay(false), temperatureValue(0),
             humidityValue(0), brightnessValue(0), windValue(0), currentValue(0), voltageValue(0) {}
};

Data systemData;

void setup()
{
    Serial.begin(9600);
    tempSensor.begin();
}

void loop()
{
    systemData.temperatureValue = tempSensor.readTemperature();
    systemData.humidityValue = tempSensor.readHumidity();
    systemData.brightnessValue = ldrSensor.getLDRPercentage();
    systemData.brightnessValue = thermSensor.readTemperature();
    systemData.brightnessValue = thermSensor.readTemperature();
    systemData.voltageValue = vSensor.getVoltage();
    Serial.print(systemData.voltageValue);

    /*Serial.print("Temperature: ");
    Serial.print(systemData.temperatureValue);
    Serial.print(" °C, Humidity: ");
    Serial.print(systemData.humidityValue);
    Serial.println(" %");
    Serial.print("Temperature: ");
    Serial.print(systemData.brightnessValue);
    Serial.println(" °C");
    Serial.print(irSensor.getWindSpeed());
    */

    delay(2000); // Adjust delay as needed
}
