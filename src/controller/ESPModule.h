#ifndef ESPMODULE_H
#define ESPMODULE_H

// Clase base abstracta para módulos del ESP32
class ESPModule {
public:
  // Método para inicializar el módulo (se debe implementar en la clase derivada)
  virtual void begin() = 0;
  // Método para actualizar o procesar la información del módulo
  virtual void update() = 0;
};

#endif // ESPMODULE_H
