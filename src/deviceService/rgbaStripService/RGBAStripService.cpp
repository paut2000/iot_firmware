//
// Created by kapers on 22.04.2022.
//

#include <device/rgbaStrip/RGBAStrip.h>
#include "RGBAStripService.h"

RGBAStripService::RGBAStripService(AbstractDevice *device, MQTTService *mqttService)
: AbstractDeviceService(device, mqttService) {}

void RGBAStripService::additionalLoopAction() {

}

void RGBAStripService::additionalSetupAction() {

}

void RGBAStripService::callback(StaticJsonDocument<512> jsonMsg) {
    RGBAStrip *strip = (RGBAStrip*) device;

    byte red = jsonMsg["red"];
    byte green = jsonMsg["green"];
    byte blue = jsonMsg["blue"];
    byte alfa = jsonMsg["alfa"];

    strip->setRGBA(red, green, blue, alfa);
}
