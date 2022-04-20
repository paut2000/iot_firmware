#include <Arduino.h>
#include <component/button/Button.h>
#include <deviceService/relayService/RelayService.h>

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

#ifdef RELAY

Relay device(D3);
Button button(D6);

RelayService deviceService(&device, &mqttService, &button);

#endif // RELAY

void setup() {
    Serial.begin(9600);
    delay(1000);

    device.setSerialNumber(SERIAL_NUMBER);

    deviceService.setup();
}

void loop() {
    deviceService.loop();
}
