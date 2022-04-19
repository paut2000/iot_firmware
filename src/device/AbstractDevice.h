//
// Created by kapers on 11.04.2022.
//

#ifndef UNTITLED_ABSTRACTDEVICE_H
#define UNTITLED_ABSTRACTDEVICE_H

#include <Arduino.h>
#include <ArduinoJson.h>

#define BUFFER_SIZE 256

#define TO_DEVICE_TOPIC_PREFIX "/set/"
#define FROM_DEVICE_TOPIC_PREFIX "/get/"

class AbstractDevice {
public:

    AbstractDevice();

    String getSerialNumber();
    void setSerialNumber(String serialNumber);

    String serializeIntoHelloMessage();
    String serializeIntoGoodbyeMessage();

protected:

    virtual void parseData(StaticJsonDocument<BUFFER_SIZE> &jsonDocument) = 0;
    virtual void parseType(StaticJsonDocument<BUFFER_SIZE> &jsonDocument) = 0;

private:

    String serialNumber;

};


#endif //UNTITLED_ABSTRACTDEVICE_H
