#include "GPSModule.h"

GPSModule::GPSModule(int uartNum, int rxPin, int txPin, uint32_t baud)
  : gps(),
    gpsSerial(uartNum),    // Pasamos directamente el número de UART
    baudRate(baud),
    _rxPin(rxPin),
    _txPin(txPin)
{}

void GPSModule::begin() {
  // Inicializa el puerto serie hardware: UART1 o UART2 según uartNum
  gpsSerial.begin(baudRate, SERIAL_8N1, _rxPin, _txPin);
}

void GPSModule::update() {
  // Lee datos NMEA mientras estén disponibles
  while (gpsSerial.available() > 0) {
    gps.encode(gpsSerial.read());
  }
}

bool GPSModule::isLocationUpdated() {
  return gps.location.isUpdated();
}

double GPSModule::getLatitude() {
  return gps.location.lat();
}

double GPSModule::getLongitude() {
  return gps.location.lng();
}
