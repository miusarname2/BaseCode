#include <Arduino.h>
#include "controller/GPSModule.h"

// put function declarations here:
GPSModule gpsModule(2,16,17,9600);

void setup() {
  Serial.begin(115200);
  gpsModule.begin();
}

void loop() {
  gpsModule.update();

  if (gpsModule.isLocationUpdated())
  {
    Serial.print("Latitud:");
    Serial.print(gpsModule.getLatitude(),6);
    Serial.print("Longitud");
    Serial.print(gpsModule.getLongitude(),6);
  }
  
}