//
// Created by kapers on 21.04.2022.
//

#include "DHTDevice.h"

void DHTDevice::parseData(StaticJsonDocument<BUFFER_SIZE> &jsonDocument) {
    jsonDocument["device"]["data"]["humidity"] = dht->readHumidity();
    jsonDocument["device"]["data"]["temperature"] = dht->readTemperature();
}

void DHTDevice::parseType(StaticJsonDocument<BUFFER_SIZE> &jsonDocument) {
    jsonDocument["device"]["type"] = TYPE;
}

DHTDevice::DHTDevice(uint8_t pin, uint8_t type, int updateFrequency) {
    this->updateFrequency = updateFrequency;
    this->dht = new DHT(pin, type);
}

float DHTDevice::readHumidity() {
    return dht->readHumidity();
}

float DHTDevice::readTemperature() {
    return dht->readTemperature();
}

int DHTDevice::getUpdateFrequency() const {
    return updateFrequency;
}

void DHTDevice::setUpdateFrequency(int updateFrequency) {
    DHTDevice::updateFrequency = updateFrequency;
}

void DHTDevice::setup() {
    dht->begin();
}

