//
// Created by kapers on 05.04.2022.
//

#include <Arduino.h>

#include "MQTTService.h"

MQTTService::MQTTService(
        String ssid,
        String password,
        const IPAddress mqtt_server,
        const int port
) {
    this->ssid = ssid;
    Serial.println(ssid);
    this->password = password;
    this->mqtt_server = mqtt_server;
    this->port = port;

    mqttClient = new PubSubClient(wiFiClient);
}

void MQTTService::connectWifi() {
    delay(10);

    Serial.print("\nConnecting to ");
    Serial.print(ssid);
    Serial.print(" with password ");
    Serial.println(password);

    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    randomSeed(micros());

    Serial.println("\nWiFi connected\nIP address: ");
    Serial.println(WiFi.localIP());
}

void MQTTService::setupServer() {
    mqttClient->setServer(mqtt_server, port);
    connectToServer();
}

void MQTTService::loop() {
    if (!mqttClient->connected()) {
        connectToServer();
    }
    mqttClient->loop();
}

void MQTTService::setup(String clientId,
                        String helloMessage,
                        String goodbyeMessage) {
    this->clientId = clientId;
    this->helloMessage = helloMessage;
    this->goodbyeMessage = goodbyeMessage;

    connectWifi();
    setupServer();
}

void MQTTService::connectToServer() {
    while (!mqttClient->connected()) {
        Serial.print("Client ID: ");
        Serial.println(clientId);
        Serial.print(HELLO_TOPIC);
        Serial.print(" : ");
        Serial.println(helloMessage);
        Serial.print(GOODBYE_TOPIC);
        Serial.print(" : ");
        Serial.println(goodbyeMessage);
        Serial.print("Attempting MQTT connection...");
        if (mqttClient->connect(clientId.c_str(), GOODBYE_TOPIC, 2, false, goodbyeMessage.c_str())) {
            Serial.println("connected");
            publish(HELLO_TOPIC, helloMessage.c_str());
        } else {
            Serial.print("failed, rc=");
            Serial.println(mqttClient->state());

            delay(5000);
        }
    }
}

void MQTTService::publish(const char* topic, const char* payload) {
    mqttClient->publish(topic, payload);
}

void MQTTService::setCallback(const char* topic, std::function<void(char *, uint8_t *, unsigned int)> callback) {
    mqttClient->subscribe(topic);
    mqttClient->setCallback(callback);
}
