//
// Created by kapers on 04.04.2022.
//

#include <Arduino.h>

#include "Relay.h"

Relay::Relay(const int pin) : AbstractDevice() {
    this->pin = pin;
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
    this->status = LOW;
}

void Relay::turnOn() {
    digitalWrite(pin, HIGH);
    this->status = HIGH;
}

void Relay::turnOff() {
    digitalWrite(pin, LOW);
    this->status = LOW;
}

void Relay::switchStatus() {
    if (status == LOW) {
        turnOn();
    } else {
        turnOff();
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
