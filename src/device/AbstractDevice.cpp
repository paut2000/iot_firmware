//
// Created by kapers on 11.04.2022.
//

#include <Arduino.h>

#include "AbstractDevice.h"

String AbstractDevice::getSerialNumber() {
    return this->serialNumber;
}

void AbstractDevice::setSerialNumber(String serialNumber) {
    this->serialNumber = serialNumber;
}

String AbstractDevice::getHelloMessage() {
    return helloMessage;
}

String AbstractDevice::getGoodByeMessage() {
    return goodbyeMessage;
}

AbstractDevice::AbstractDevice() {

}

void AbstractDevice::setHelloMessage(String helloMessage) {
    this->helloMessage = helloMessage;
}

void AbstractDevice::setGoodByeMessage(String goodbyeMessage) {
    this->goodbyeMessage = goodbyeMessage;
}
