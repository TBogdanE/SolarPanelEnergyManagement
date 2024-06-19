#include <Arduino.h>
#include "./modules/temperatureSensor/temperature.h"  // Adjust the path as per your folder structure

#define DHT_PIN 9    // Example pin number
#define DHT_TYPE DHT11 // Example DHT type, could be DHT11, DHT21, DHT22

TemperatureSensor tempSensor(DHT_PIN, DHT_TYPE);

void setup() {
    Serial.begin(9600);
    tempSensor.begin();
}

void loop() {
    float temperature = tempSensor.readTemperature();
    float humidity = tempSensor.readHumidity();

    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.print(" °C, Humidity: ");
    Serial.print(humidity);
    Serial.println(" %");

    delay(2000);  // Adjust delay as needed
}
