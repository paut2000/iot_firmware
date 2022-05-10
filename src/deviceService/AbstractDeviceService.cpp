//
// Created by kapers on 20.04.2022.
//

#include <device/relay/Relay.h>
#include "AbstractDeviceService.h"

AbstractDeviceService::AbstractDeviceService(AbstractDevice *device, MQTTService *mqttService)
: device(device), mqttService(mqttService) {}

void AbstractDeviceService::setup() {
    additionalSetupAction();

    mqttService->setup(device->getSerialNumber(),
                       device->serializeIntoHelloMessage(),
                       device->serializeIntoGoodbyeMessage());

    mqttService->setCallback(("/set/" + device->getSerialNumber()).c_str(),
                             [this](char *topic, uint8_t * payload, unsigned int length) {
        String strTopic(topic);
        if (!strTopic.equals("/set/" + device->getSerialNumber())) return;
        StaticJsonDocument<BUFFER_SIZE> jsonMsg;
        deserializeJson(jsonMsg, payload);
        callback(jsonMsg);
    });
}

void AbstractDeviceService::loop() {
    mqttService->loop(("/set/" + device->getSerialNumber()).c_str(),
                      [this](char *topic, uint8_t * payload, unsigned int length) {
                          String strTopic(topic);
                          if (!strTopic.equals("/set/" + device->getSerialNumber())) return;
                          StaticJsonDocument<BUFFER_SIZE> jsonMsg;
                          deserializeJson(jsonMsg, payload);
                          callback(jsonMsg);
                      });
    additionalLoopAction();
}
