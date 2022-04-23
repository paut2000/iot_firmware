//
// Created by kapers on 22.04.2022.
//

#ifndef UNTITLED_RGBASTRIP_H
#define UNTITLED_RGBASTRIP_H

#include <GRGB.h>

#include <device/AbstractDevice.h>

#define TYPE "RGBAStrip"

class RGBAStrip : public AbstractDevice {
public:

    RGBAStrip(const uint8_t pinR = 0, const uint8_t pinG = 0, const uint8_t pinB = 0);

    void setRGBA(byte red, byte green, byte blue, byte alfa);

protected:

    void parseData(StaticJsonDocument<512> &jsonDocument) override;
    void parseType(StaticJsonDocument<512> &jsonDocument) override;

private:

    GRGB *strip;

    byte red = 0;
    byte green = 0;
    byte blue = 0;
    byte alfa = 0;

};


#endif //UNTITLED_RGBASTRIP_H
