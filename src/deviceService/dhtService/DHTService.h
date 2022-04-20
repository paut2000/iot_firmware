//
// Created by kapers on 21.04.2022.
//

#ifndef UNTITLED_DHTSERVICE_H
#define UNTITLED_DHTSERVICE_H


#include <deviceService/AbstractDeviceService.h>

class DHTService : public AbstractDeviceService {
public:

    DHTService(AbstractDevice *device, MQTTService *mqttService);

protected:

    void additionalLoopAction() override;
    void callback(StaticJsonDocument<BUFFER_SIZE> jsonMsg) override;
    void additionalSetupAction() override;

};


#endif //UNTITLED_DHTSERVICE_H
