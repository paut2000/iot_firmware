#include <Arduino.h>
#include <component/button/Button.h>

#include "mqtt/MQTTService.h"
#include "device/relay/Relay.h"

#define SSID "RT-GPON-BB70"
#define PASSWORD "KSMJUY8s"
#define PORT 1883
const IPAddress brokerIp(192, 168, 0, 3);

#define SERIAL_NUMBER "relay-asghg48fafg"

#define RELAY
//#define DHT
//#define RGBA_STRIP

MQTTService mqttService(SSID, PASSWORD, brokerIp, PORT);

Relay relay(D3);
Button button(D6);

void setup() {
    Serial.begin(9600);
    delay(1000);

    relay.setSerialNumber(SERIAL_NUMBER);

    mqttService.addCallback("/set/" + relay.getSerialNumber(), [](char* payload, unsigned int length){
        StaticJsonDocument<256> jsonMsg;
        deserializeJson(jsonMsg, payload);
        String action = jsonMsg["action"];
        if (action == "enable") {
            relay.turnOn();
        }
        if (action == "disable") {
            relay.turnOff();
        }
    });

    mqttService.setup(relay.getSerialNumber(),
                      relay.serializeIntoHelloMessage(),
                      relay.serializeIntoGoodbyeMessage());
}

void loop() {

    button.listenSwitch([](){
        relay.switchStatus();

        StaticJsonDocument<256> jsonDocument;
        jsonDocument["status"] = relay.getStatus();
        char buffer[256];
        serializeJsonPretty(jsonDocument, buffer, 256);
        mqttService.publish(("/get/" + relay.getSerialNumber()).c_str(), buffer);
    });

    mqttService.loop();
}
