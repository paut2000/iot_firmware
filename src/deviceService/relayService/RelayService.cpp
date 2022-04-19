//
// Created by kapers on 20.04.2022.
//

#include <device/relay/Relay.h>
#include "RelayService.h"

void RelayService::additionalLoopAction() {

}

void RelayService::callbackSetup() {
    mqttService->addCallback("/set/" + device->getSerialNumber(), [](char* payload, unsigned int length) {
        Relay *relay = (Relay*) device;
        StaticJsonDocument<256> jsonMsg;
        deserializeJson(jsonMsg, payload);
        String action = jsonMsg["action"];
        if (action == "enable") {
            relay.turnOn();
        }
        if (action == "disable") {
            relay.turnOff();
        }
    });
}
