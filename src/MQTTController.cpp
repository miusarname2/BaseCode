#include "controller/MQTTController.h"

MQTTController::MQTTController(WiFiClient &client, const char* server, uint16_t port, const char* clientID)
  : mqttClient(client), mqttServer(server), mqttPort(port), clientID(clientID) {}

void MQTTController::begin() {
  mqttClient.setServer(mqttServer, mqttPort);
}

void MQTTController::update() {
  // Si no está conectado, se intenta reconectar
  if (!mqttClient.connected()) {
    while (!mqttClient.connected()) {
      Serial.print("Conectando a MQTT...");
      if (mqttClient.connect(clientID)) {
        Serial.println(" Conectado a MQTT");
      } else {
        Serial.print("Fallo, rc=");
        Serial.print(mqttClient.state());
        Serial.println(" Reintentando en 5 segundos...");
        delay(5000);
      }
    }
  }
  mqttClient.loop();
}

bool MQTTController::publishData(const char* topic, const char* payload) {
  return mqttClient.publish(topic, payload);
}
