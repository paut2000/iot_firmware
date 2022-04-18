//
// Created by kapers on 11.04.2022.
//

#ifndef UNTITLED_ABSTRACTDEVICE_H
#define UNTITLED_ABSTRACTDEVICE_H

class AbstractDevice {
public:

    AbstractDevice();

    String getSerialNumber();
    void setSerialNumber(String serialNumber);

    String getHelloMessage();
    String getGoodByeMessage();
    void setHelloMessage(String helloMessage);
    void setGoodByeMessage(String goodbyeMessage);

protected:

    String helloMessage = "default hello";
    String goodbyeMessage = "default goodbye";

private:

    String serialNumber;

};


#endif //UNTITLED_ABSTRACTDEVICE_H
