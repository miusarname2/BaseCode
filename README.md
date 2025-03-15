# Documentación del Repositorio

## Descripción General

Este repositorio tiene como objetivo desarrollar un sistema modular para el manejo de controladores del ESP32. La aplicación integra un módulo GPS (Ublox NEO-6M) para obtener la ubicación actual del dispositivo y un controlador MQTT para enviar periódicamente esta información a un servidor. Se busca construir una solución escalable, modular y de fácil mantenimiento que permita futuras ampliaciones o modificaciones.

## Estructura del Proyecto

La estructura del repositorio está organizada de la siguiente manera:

```
├── .gitignore
├── .vscode
│   ├── extensions.json
│   └── settings.json
├── README.md
├── include
│   └── README
├── lib
│   └── README
├── platformio.ini
├── src
│   ├── controller
│   │   ├── ESPModule.h
│   │   ├── GPSModule.h
│   │   └── MQTTController.h
│   ├── MQTTController.cpp
│   └── main.cpp
└── test
    └── README
```

### Detalle de la Estructura

- **.vscode/**  
  Configuraciones específicas para Visual Studio Code, ayudando a mantener un entorno de desarrollo coherente.

- **include/** y **lib/**  
  Carpetas reservadas para incluir archivos y bibliotecas adicionales, en caso de ser necesario.

- **platformio.ini**  
  Archivo de configuración para PlatformIO, donde se definen la plataforma, placa, framework y dependencias (por ejemplo, *TinyGPSPlus* y *PubSubClient*).

- **src/**  
  Directorio que contiene el código fuente del proyecto.
  
  - **controller/**  
    Carpeta dedicada a los módulos o controladores del sistema.
    
    - **ESPModule.h:**  
      Clase base abstracta para los módulos del ESP32. Todas las clases controladoras heredan de esta clase, garantizando una interfaz común (`begin()` y `update()`).
      
    - **GPSModule.h:**  
      Módulo encargado de gestionar el procesamiento de datos del GPS. Utiliza la librería *TinyGPSPlus* para parsear las tramas NMEA y obtener la ubicación.
      
    - **MQTTController.h:**  
      Módulo que administra la conexión MQTT. Extiende de **ESPModule** y se encarga de la conexión, reconexión y publicación de datos a un broker MQTT.
      
  - **MQTTController.cpp:**  
    Implementación de la clase **MQTTController**, que contiene la lógica para establecer y mantener la conexión MQTT y publicar los mensajes.
    
  - **main.cpp:**  
    Archivo principal del proyecto. Se encarga de inicializar la conexión WiFi, instanciar y actualizar los módulos (GPS y MQTT). Aquí se orquesta el envío de la ubicación en formato JSON cada vez que el GPS actualice la posición.

- **test/**  
  Espacio reservado para pruebas unitarias o de integración que aseguren el correcto funcionamiento del sistema.

## Uso de Programación Orientada a Objetos (POO)

El proyecto se ha diseñado utilizando un enfoque orientado a objetos por las siguientes razones:

- **Modularidad:**  
  La POO permite encapsular la lógica en clases. Cada módulo (por ejemplo, GPSModule y MQTTController) tiene responsabilidades bien definidas, lo que facilita la separación de funcionalidades y la reutilización de código.

- **Escalabilidad:**  
  Gracias al diseño basado en clases y la herencia de la clase **ESPModule**, es sencillo agregar nuevos controladores o extender los existentes sin alterar la estructura global del sistema.

- **Mantenibilidad:**  
  Un código organizado y modular facilita la localización de errores, la realización de modificaciones y la integración de nuevas funcionalidades. Además, el uso de estándares en los mensajes de commit (mediante la extensión "Conventional commits") permite un historial de cambios claro y uniforme, mejorando la colaboración en equipos.

## Flujo de Trabajo y Funcionalidad

1. **Inicialización:**  
   - En `main.cpp`, se inicia la conexión WiFi y se instancian los módulos.
   - Se llama al método `begin()` de cada módulo para realizar las configuraciones iniciales.

2. **Actualización Continua:**  
   - En el `loop()`, se invoca el método `update()` de cada módulo.
   - **GPSModule:** Procesa continuamente la información del GPS. Cuando detecta una nueva ubicación, habilita la actualización.
   - **MQTTController:** Verifica y mantiene la conexión al broker MQTT, reconectándose automáticamente en caso de desconexión, y se encarga de enviar los datos en el formato deseado.

3. **Publicación de Datos:**  
   - Cuando el GPS actualiza su ubicación, se crea un mensaje JSON con la latitud y longitud.
   - Este mensaje se publica en el tópico definido a través del **MQTTController**.

## Estándar de Commits

Se recomienda utilizar la extensión **"Conventional commits"** en Visual Studio Code para lograr:
- **Mensajes claros y descriptivos:**  
  Facilita la comprensión del historial de cambios y mejora la comunicación entre desarrolladores.
- **Estandarización de mensajes:**  
  Mantiene un formato uniforme que resulta útil para la integración continua y el versionado semántico.

Adoptar este estándar contribuye a un desarrollo más organizado y a un seguimiento eficiente de los cambios en el repositorio.

## Justificación Técnica

1. **Modularidad y Organización del Código:**  
   Separar la lógica de controladores en su propio directorio y centralizar la inicialización en `main.cpp` permite una estructura clara, facilitando el mantenimiento y la extensión del sistema.

2. **Escalabilidad:**  
   La utilización de clases y la herencia de **ESPModule** posibilitan agregar nuevos módulos (por ejemplo, nuevos sensores o métodos de comunicación) sin reestructurar el proyecto por completo.

3. **Mantenibilidad:**  
   La modularidad, junto con una buena documentación y el uso de commit messages estandarizados, reduce la curva de aprendizaje y simplifica la identificación y corrección de errores.

4. **Facilidad en la Colaboración:**  
   Una estructura bien definida y documentada permite que nuevos miembros del equipo comprendan rápidamente el flujo y la organización del código, facilitando la integración y la colaboración en el proyecto.