#include <Arduino.h>
#include "mqtt/MQTTService.h"
#include "device/relay/Relay.h"

#define SSID "POCO X3 Pro"
#define PASSWORD "ven8sinvsqeuatv"
#define PORT 1883

const IPAddress brokerIp(192, 168, 68, 156);

MQTTService mqttService(SSID, PASSWORD, brokerIp, PORT);

Relay relay(D1);

void setup() {
    Serial.begin(9600);
    delay(1000);

    relay.setSerialNumber("relay-asghg48fafg");

    mqttService.addCallback(strcat((char*) "/set/", relay.getSerialNumber()), [](char* payload, unsigned int length){
        Serial.println(length);
        Serial.println(payload);
    });


    mqttService.setup(relay.getSerialNumber(), relay.getHelloMessage(), relay.getGoodByeMessage());
}

void loop() {
    delay(1000);

    mqttService.loop();
}
