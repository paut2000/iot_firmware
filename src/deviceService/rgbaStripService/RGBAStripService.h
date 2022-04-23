//
// Created by kapers on 22.04.2022.
//

#ifndef UNTITLED_RGBASTRIPSERVICE_H
#define UNTITLED_RGBASTRIPSERVICE_H


#include <deviceService/AbstractDeviceService.h>

class RGBAStripService : public AbstractDeviceService {
public:

    RGBAStripService(AbstractDevice *device, MQTTService *mqttService);

private:

    void additionalLoopAction() override;
    void additionalSetupAction() override;
    void callback(StaticJsonDocument<512> jsonMsg) override;

};


#endif //UNTITLED_RGBASTRIPSERVICE_H
