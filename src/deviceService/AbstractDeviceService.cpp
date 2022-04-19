//
// Created by kapers on 20.04.2022.
//

#include "AbstractDeviceService.h"

AbstractDeviceService::AbstractDeviceService(AbstractDevice *device, MQTTService *mqttService)
: device(device), mqttService(mqttService) {}

void AbstractDeviceService::setup() {
    mqttService->addCallback("/set/" + device->getSerialNumber(), [](char *, unsigned int) {});
    mqttService->setup(device->getSerialNumber(),
                      device->serializeIntoHelloMessage(),
                      device->serializeIntoGoodbyeMessage());
}

void AbstractDeviceService::loop() {
    mqttService->loop();
    additionalLoopAction();
}
