//
// Created by kapers on 20.04.2022.
//

#ifndef UNTITLED_RELAYSERVICE_H
#define UNTITLED_RELAYSERVICE_H


#include <deviceService/AbstractDeviceService.h>
#include <component/button/Button.h>

class RelayService : public AbstractDeviceService {
public:

    RelayService(AbstractDevice *device, MQTTService *mqttService, Button *button);

private:

    void additionalLoopAction() override;
    void callback(StaticJsonDocument<BUFFER_SIZE> jsonMsg) override;
    void additionalSetupAction() override;

    Button *button;

};


#endif //UNTITLED_RELAYSERVICE_H
