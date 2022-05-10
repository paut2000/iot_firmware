//
// Created by kapers on 05.04.2022.
//
#pragma once

#ifndef UNTITLED_TEST_H
#define UNTITLED_MQTTSERVICE_H

#include <ESP8266WiFi.h>
#include <PubSubClient.h>

#include "device/AbstractDevice.h"

#define HELLO_TOPIC "/device/new/"
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
    void loop(const char* topic, std::function<void(char *, uint8_t *, unsigned int)> callback);

    void publish(const char* topic, const char* message);
    void publishRetain(const char* topic, const char* message);
    void setCallback(const char* topic, MQTT_CALLBACK_SIGNATURE);

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

};

#endif //UNTITLED_TEST_H
