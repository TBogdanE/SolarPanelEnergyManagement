#ifndef LDR_H
#define LDR_H

class LDRSensor {
    public:
        LDRSensor(int LDRpin);
        void begin();
        int getRawLDRValue();
        float getLDRPercentage();
    private:
        int _LDRpin;
};

#endif