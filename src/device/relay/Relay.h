//
// Created by kapers on 04.04.2022.
//

#ifndef UNTITLED_RELAY_H
#define UNTITLED_RELAY_H

#include "device/AbstractDevice.h"

#define TYPE "Relay"

class Relay : public AbstractDevice {
public:

    Relay(int pin);

    bool getStatus();

    void turnOn();
    void turnOff();
    void switchStatus();

protected:

    void parseData(StaticJsonDocument<BUFFER_SIZE> &jsonDocument) override;
    void parseType(StaticJsonDocument<BUFFER_SIZE> &jsonDocument) override;

private:

    int pin;
    bool status;

};


#endif //UNTITLED_RELAY_H
