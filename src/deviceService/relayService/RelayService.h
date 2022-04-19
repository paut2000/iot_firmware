//
// Created by kapers on 20.04.2022.
//

#ifndef UNTITLED_RELAYSERVICE_H
#define UNTITLED_RELAYSERVICE_H


#include <deviceService/AbstractDeviceService.h>

class RelayService : AbstractDeviceService {
private:

    void additionalLoopAction() override;
    void callback(char* payload, unsigned int length) override;

};


#endif //UNTITLED_RELAYSERVICE_H
