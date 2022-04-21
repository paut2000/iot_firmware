//
// Created by kapers on 21.04.2022.
//

#include <device/dht/DHTDevice.h>
#include "DHTService.h"

void DHTService::additionalLoopAction() {
    DHTDevice* dht = (DHTDevice*) device;

    float humidity = dht->readHumidity();
    float temperature = dht->readTemperature();

    if (isnan(humidity) || isnan(temperature)) {
        Serial.println(("Failed to read from DHT sensor!"));
        return;
    }

    StaticJsonDocument<BUFFER_SIZE> jsonDocument;
    jsonDocument["temperature"] = temperature;
    jsonDocument["humidity"] = humidity;
    char buffer[BUFFER_SIZE];
    serializeJsonPretty(jsonDocument, buffer, BUFFER_SIZE);
    mqttService->publish(("/get/" + device->getSerialNumber()).c_str(), buffer);

    EspClass::deepSleep(dht->getUpdateFrequency() * 1000);
}

void DHTService::callback(StaticJsonDocument<BUFFER_SIZE> jsonMsg) {

}

DHTService::DHTService(AbstractDevice *device, MQTTService *mqttService) : AbstractDeviceService(device, mqttService) {}

void DHTService::additionalSetupAction() {
    ((DHTDevice*) device)->setup();
}
