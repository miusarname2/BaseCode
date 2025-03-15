#include <WiFi.h>
#include "controller/GPSModule.h"
#include "controller/MQTTController.h"

// Configuración WiFi
const char* ssid = "TU_SSID";
const char* password = "TU_PASSWORD";

// Configuración MQTT
const char* mqtt_server = "DIRECCION_DEL_BROKER"; // Por ejemplo: "192.168.1.100"
const uint16_t mqtt_port = 1883;

WiFiClient wifiClient;
MQTTController mqttController(wifiClient, mqtt_server, mqtt_port);
GPSModule gpsModule(2, 16, 17, 9600);

// Función para conectar a la red WiFi
void setupWiFi() {
  delay(10);
  Serial.println();
  Serial.print("Conectando a ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.println("WiFi conectado");
  Serial.print("Dirección IP: ");
  Serial.println(WiFi.localIP());
}

void setup() {
  Serial.begin(115200);
  setupWiFi();
  
  // Inicializamos el controlador MQTT y el módulo GPS
  mqttController.begin();
  gpsModule.begin();
}

void loop() {
  // Actualizamos el controlador MQTT y el módulo GPS
  mqttController.update();
  gpsModule.update();

  // Si el GPS tiene nueva ubicación, se publica por MQTT en formato JSON
  if (gpsModule.isLocationUpdated()) {
    double lat = gpsModule.getLatitude();
    double lon = gpsModule.getLongitude();

    String payload = String("{\"lat\":") + String(lat, 6) + ",\"lon\":" + String(lon, 6) + "}";
    Serial.print("Publicando: ");
    Serial.println(payload);

    mqttController.publishData("esp32/gps", payload.c_str());
  }
}
