#include <Arduino.h>
#include "mqtt/MQTTService.h"
#include "device/relay/Relay.h"

#define SSID "RT-GPON-BB70"
#define PASSWORD "KSMJUY8s"
#define PORT 1883

const IPAddress brokerIp(192, 168, 0, 3);

MQTTService mqttService(SSID, PASSWORD, brokerIp, PORT);

Relay relay(0);

void setup() {
    Serial.begin(9600);
    delay(1000);

    relay.setSerialNumber("relay-asghg48fafg");
    relay.setHelloMessage("hello, guy");
    relay.setGoodByeMessage("goodbye, guy");

    mqttService.addCallback("/set/" + relay.getSerialNumber(), [](char* payload, unsigned int length){
        Serial.println(length);
        Serial.println(payload);
    });


    mqttService.setup(relay.getSerialNumber(), relay.getHelloMessage(), relay.getGoodByeMessage());
}

void loop() {
    delay(1000);

    mqttService.loop();
}
