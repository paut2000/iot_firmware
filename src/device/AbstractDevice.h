//
// Created by kapers on 11.04.2022.
//

#ifndef UNTITLED_ABSTRACTDEVICE_H
#define UNTITLED_ABSTRACTDEVICE_H


class AbstractDevice {
public:

    AbstractDevice();

    const char* getSerialNumber();
    void setSerialNumber(const char* serialNumber);

    const char* getHelloMessage();
    const char* getGoodByeMessage();

protected:

    char* helloMessage = nullptr;
    char* goodbyeMessage = nullptr;

private:

    const char* serialNumber;

};


#endif //UNTITLED_ABSTRACTDEVICE_H
