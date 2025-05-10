#ifndef MQTTCONTROLLER_H
#define MQTTCONTROLLER_H

#include <Arduino.h>
#include <PubSubClient.h>
#include "ESPModule.h"
#include <WiFi.h> 

class MQTTController : public ESPModule {
public:
  // Constructor: se le pasa una referencia al WiFiClient, el servidor, puerto y opcionalmente un ID de cliente.
  MQTTController(WiFiClient &client, const char* server, uint16_t port, const char* clientID = "ESP32Client");

  void begin() override;
  void update() override;

  // Función para publicar datos en un tópico dado
  bool publishData(const char* topic, const char* payload);

private:
  PubSubClient mqttClient;
  const char* mqttServer;
  uint16_t mqttPort;
  const char* clientID;
};

#endif // MQTTCONTROLLER_H
