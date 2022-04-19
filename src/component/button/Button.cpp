//
// Created by kapers on 11.04.2022.
//

#include <Arduino.h>

#include "Button.h"

Button::Button(const int pin) {
    this->pin = pin;
    pinMode(pin, INPUT);
    prevVal = LOW;
}

void Button::listenSwitch(void (*action)()) {
    int val = digitalRead(pin);
    if (prevVal != val) {
        delay(50);
        val = digitalRead(pin);
        if (prevVal != val) {
            (*action)();
            prevVal = val;
        }
    }
}
