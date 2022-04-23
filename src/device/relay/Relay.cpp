//
// Created by kapers on 04.04.2022.
//

#include <Arduino.h>

#include "Relay.h"

Relay::Relay(const int pin, const bool onVal) : AbstractDevice() {
    this->onVal = onVal;
    this->pin = pin;
    pinMode(pin, OUTPUT);
    digitalWrite(pin, !onVal);
    this->status = false;
}

void Relay::turnOn() {
    digitalWrite(pin, onVal);
    this->status = true;
}

void Relay::turnOff() {
    digitalWrite(pin, !onVal);
    this->status = false;
}

void Relay::switchStatus() {
    if (status == true) {
        turnOff();
    } else {
        turnOn();
    }
}

bool Relay::getStatus() {
    return this->status;
}

void Relay::parseData(StaticJsonDocument<BUFFER_SIZE> &jsonDocument) {
    jsonDocument["device"]["data"]["status"] = status;
}

void Relay::parseType(StaticJsonDocument<BUFFER_SIZE> &jsonDocument) {
    jsonDocument["device"]["type"] = TYPE;
}
