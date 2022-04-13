//
// Created by kapers on 05.04.2022.
//

#ifndef UNTITLED_TEST_H
#define UNTITLED_MQTTSERVICE_H

#include <ESP8266WiFi.h>
#include <PubSubClient.h>

#include "device/AbstractDevice.h"

class MQTTService {
public:

    MQTTService(
            const char* ssid,
            const char* password,
            const IPAddress mqtt_server,
            const int port
    );

    void setup(const char* clientId,
               const char* helloMessage,
               const char* goodbyeMessage);
    void loop();

    void publish(const char* topic, const char* message);
    void addCallback(String topic, void (*callback)(char*, unsigned int));

private:

    void connectWifi();
    void setupServer();
    void connectToServer();

    const char* ssid;
    const char* password;

    IPAddress mqtt_server;
    int port;
    const char* clientId;

    const char* helloMessage;
    const char* goodbyeMessage;

    WiFiClient wiFiClient;
    PubSubClient *mqttClient;

    unsigned int callbackQuantity = 0;

    struct Callback {
        String topic;
        void (*callback)(char*, unsigned int);
    } *callbacks;

};



#endif //UNTITLED_TEST_H
