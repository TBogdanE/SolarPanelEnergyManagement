#line 1 "C:\\Users\\bogda\\Documents\\Coding\\ProiectLicenta\\SolarPanelEnergyManagement\\Arduino\\main\\modules\\photoresistorSensor\\ldr.cpp"
#include "ldr.h"

LDRSensor::LDRSensor(int LDRpin) {
    _LDRpin = LDRpin;
}
    
   int LDRSensor::getRawLDRValue() {
        return analogRead(_LDRpin);
    }
    
    float LDRSensor::getLDRPercentage() {
        int rawLDR = getRawLDRValue();
        float brightness =  map(rawLDR, 0, 1023, 100, 0);
        return brightness;
    }