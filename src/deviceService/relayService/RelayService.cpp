//
// Created by kapers on 20.04.2022.
//

#include <device/relay/Relay.h>
#include "RelayService.h"

Relay *relayGlobal;
MQTTService* mqttServiceGlobal;
void RelayService::additionalLoopAction() {
    relayGlobal = (Relay*) device;
    mqttServiceGlobal = mqttService;

    button->listenSwitch([](){
        relayGlobal->switchStatus();

        StaticJsonDocument<BUFFER_SIZE> jsonDocument;
        jsonDocument["status"] = relayGlobal->getStatus();
        char buffer[BUFFER_SIZE];
        serializeJsonPretty(jsonDocument, buffer, BUFFER_SIZE);
        mqttServiceGlobal->publish(("/get/" + relayGlobal->getSerialNumber()).c_str(), buffer);
    });
}

void RelayService::callback(StaticJsonDocument<256> jsonMsg) {
    Relay *relay = (Relay*) device;

    String action = jsonMsg["action"];

    if (action == "enable") {
        relay->turnOn();
    }
    if (action == "disable") {
        relay->turnOff();
    }
}

RelayService::RelayService(AbstractDevice *device, MQTTService *mqttService, Button *button)
: AbstractDeviceService(device, mqttService) {
    this->button = button;
}
