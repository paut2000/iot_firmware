//
// Created by kapers on 20.04.2022.
//

#ifndef UNTITLED_ABSTRACTDEVICESERVICE_H
#define UNTITLED_ABSTRACTDEVICESERVICE_H


#include <device/AbstractDevice.h>
#include <mqtt/MQTTService.h>

class AbstractDeviceService {
public:

    AbstractDeviceService(AbstractDevice *device, MQTTService *mqttService);

    void setup();
    void loop();

protected:

    virtual void additionalLoopAction() = 0;
    virtual void callback(char* payload, unsigned int length) = 0;

    AbstractDevice* device;
    MQTTService* mqttService;

};


#endif //UNTITLED_ABSTRACTDEVICESERVICE_H
