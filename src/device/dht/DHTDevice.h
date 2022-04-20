//
// Created by kapers on 21.04.2022.
//

#ifndef UNTITLED_DHTDEVICE_H
#define UNTITLED_DHTDEVICE_H


#include <device/AbstractDevice.h>
#include <DHT.h>

#define TYPE "DHT"

class DHTDevice : public AbstractDevice {
public:

    DHTDevice(uint8_t pin, uint8_t type, int updateFrequency);

    void setup();

    float readHumidity();
    float readTemperature();

    int getUpdateFrequency() const;
    void setUpdateFrequency(int updateFrequency);

protected:

    void parseData(StaticJsonDocument<BUFFER_SIZE> &jsonDocument) override;
    void parseType(StaticJsonDocument<BUFFER_SIZE> &jsonDocument) override;

private:

    DHT *dht;

    int updateFrequency;

};


#endif //UNTITLED_DHTDEVICE_H
