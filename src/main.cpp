#define RELAY
//#define DHT
//#define RGBA_STRIP

#include <Arduino.h>

#include "mqtt/MQTTService.h"

#ifdef RELAY
#include "device/relay/Relay.h"
#include "component/button/Button.h"
#include "deviceService/relayService/RelayService.h"
#endif // RELAY

#ifdef DHT
#include "device/dht/DHTDevice.h"
#include "deviceService/dhtService/DHTService.h"
#endif // DHT

#ifdef RGBA_STRIP
#include "<"device/rgbaStrip/RGBAStrip.h"
#include "<"deviceService/rgbaStripService/RGBAStripService.h"
#endif // RGBA_STRIP

#define SSID "RT-GPON-BB70"
#define PASSWORD "KSMJUY8s"
#define PORT 1883
const IPAddress brokerIp(192, 168, 0, 3);

#define SERIAL_NUMBER "relay-asghg48fafg"

MQTTService mqttService(SSID, PASSWORD, brokerIp, PORT);

#ifdef RELAY

Relay device(D3, LOW);
Button button(D6);
RelayService deviceService(&device, &mqttService, &button);

#endif // RELAY

#ifdef DHT

#define DHTTYPE DHT22

DHTDevice device(D6, DHTTYPE, 300000);
DHTService deviceService(&device, &mqttService);

#endif // DHT

#ifdef RGBA_STRIP

RGBAStrip device(D2, D3, D1);
RGBAStripService deviceService(&device, &mqttService);

#endif // RGBA_STRIP

void setup() {
    Serial.begin(9600);
    delay(1000);

    device.setSerialNumber(SERIAL_NUMBER);

    deviceService.setup();
}

void loop() {
    deviceService.loop();
}
