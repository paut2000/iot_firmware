//
// Created by kapers on 04.04.2022.
//

#ifndef UNTITLED_RELAY_H
#define UNTITLED_RELAY_H

#include "device/AbstractDevice.h"

class Relay : public AbstractDevice {
public:

    Relay(int pin);

    bool getStatus();

    void turnOn();
    void turnOff();
    void switchStatus();

private:

    int pin;
    bool status;

};


#endif //UNTITLED_RELAY_H
