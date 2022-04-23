//
// Created by kapers on 22.04.2022.
//

#include "RGBAStrip.h"

void RGBAStrip::parseData(StaticJsonDocument<512> &jsonDocument) {
    jsonDocument["device"]["data"]["red"] = red;
    jsonDocument["device"]["data"]["green"] = green;
    jsonDocument["device"]["data"]["blue"] = blue;
    jsonDocument["device"]["data"]["alfa"] = alfa;
}

void RGBAStrip::parseType(StaticJsonDocument<512> &jsonDocument) {
    jsonDocument["device"]["type"] = TYPE;
}

RGBAStrip::RGBAStrip(const uint8_t pinR, const uint8_t pinG, const uint8_t pinB) {
    this->strip = new GRGB(COMMON_CATHODE, pinR, pinG, pinB);
}

void RGBAStrip::setRGBA(byte red, byte green, byte blue, byte alfa) {
    this->red = red;
    this->green = green;
    this->blue = blue;
    this->alfa = alfa;

    strip->setBrightness(alfa);
    strip->setRGB(red, green, blue);
}
