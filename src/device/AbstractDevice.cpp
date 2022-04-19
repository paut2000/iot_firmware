//
// Created by kapers on 11.04.2022.
//

#include <Arduino.h>

#include "AbstractDevice.h"

AbstractDevice::AbstractDevice() {

}

String AbstractDevice::getSerialNumber() {
    return this->serialNumber;
}

void AbstractDevice::setSerialNumber(String serialNumber) {
    this->serialNumber = serialNumber;
}

String AbstractDevice::serializeIntoHelloMessage() {
    StaticJsonDocument<BUFFER_SIZE> jsonDocument;
    jsonDocument.createNestedObject("device");
    jsonDocument["device"]["serialNumber"] = serialNumber;
    jsonDocument["device"]["toDeviceTopic"] = TO_DEVICE_TOPIC_PREFIX + serialNumber;
    jsonDocument["device"]["fromDeviceTopic"] = FROM_DEVICE_TOPIC_PREFIX + serialNumber;

    parseType(jsonDocument);

    jsonDocument["device"].createNestedObject("data");
    parseData(jsonDocument);

    char buffer[BUFFER_SIZE];
    serializeJsonPretty(jsonDocument, buffer, BUFFER_SIZE);

    return {buffer};
}

String AbstractDevice::serializeIntoGoodbyeMessage() {
    StaticJsonDocument<BUFFER_SIZE> jsonDocument;
    jsonDocument["serialNumber"] = serialNumber;

    char buffer[BUFFER_SIZE];
    serializeJsonPretty(jsonDocument, buffer, BUFFER_SIZE);

    return {buffer};
}
