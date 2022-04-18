//
// Created by kapers on 05.04.2022.
//

#ifndef UNTITLED_TEST_H
#define UNTITLED_MQTTSERVICE_H

#include <ESP8266WiFi.h>
#include <PubSubClient.h>

#include "device/AbstractDevice.h"

#define HELLO_TOPIC "/device/new"
#define GOODBYE_TOPIC "/device/died"

class MQTTService {
public:

    MQTTService(
            String ssid,
            String password,
            const IPAddress mqtt_server,
            const int port
    );

    void setup(String clientId,
               String helloMessage,
               String goodbyeMessage);
    void loop();

    void publish(const char* topic, const char* message);
    void addCallback(String topic, void (*callback)(char*, unsigned int));

private:

    void connectWifi();
    void setupServer();
    void connectToServer();

    String ssid;
    String password;

    IPAddress mqtt_server;
    int port;
    String clientId;

    String helloMessage;
    String goodbyeMessage;

    WiFiClient wiFiClient;
    PubSubClient *mqttClient;

    unsigned int callbackQuantity = 0;

    struct Callback {
        String topic;
        void (*callback)(char*, unsigned int);
    } *callbacks;

};



#endif //UNTITLED_TEST_H
