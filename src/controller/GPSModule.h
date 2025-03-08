#ifndef GPSMODULE_H
#define GPSMODULE_H

#include <Arduino.h>
#include <TinyGPS++.h>
#include <HardwareSerial.h>
#include "ESPModule.h"

class GPSModule : public ESPModule {
public:
  GPSModule(int uartNum, int rxPin, int txPin, uint32_t baud = 9600);

  void begin() override;
  void update() override;

  bool isLocationUpdated();
  double getLatitude();
  double getLongitude();

private:
  TinyGPSPlus gps;             // Instancia para procesar datos NMEA
  HardwareSerial gpsSerial;    // Objeto para manejar la comunicación serial con el GPS
  uint32_t baudRate;           // Velocidad de comunicación
  int _rxPin, _txPin;          // Pines para la conexión del GPS
};

#endif // GPSMODULE_H
