//
// Created by kapers on 11.04.2022.
//

#include <Arduino.h>

#include "AbstractDevice.h"

const char *AbstractDevice::getSerialNumber() {
    return this->serialNumber;
}

void AbstractDevice::setSerialNumber(const char *serialNumber) {
    this->serialNumber = serialNumber;
}

const char *AbstractDevice::getHelloMessage() {
    return helloMessage;
}

const char *AbstractDevice::getGoodByeMessage() {
    return goodbyeMessage;
}

AbstractDevice::AbstractDevice() {

}
