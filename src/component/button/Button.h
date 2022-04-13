//
// Created by kapers on 11.04.2022.
//

#ifndef UNTITLED_BUTTON_H
#define UNTITLED_BUTTON_H

class Button {
public:

    Button(const int pin);

    void listenSwitch(void (*action)());
    void listenSingleClick(void (*action)());
    void listenDoubleClick(void (*action)());
    void listenTripleClick(void (*action)());

private:

    int pin;
    bool prevVal;

};


#endif //UNTITLED_BUTTON_H
