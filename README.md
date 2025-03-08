# Documentación del Repositorio

## Descripción General

Este repositorio tiene como objetivo desarrollar el código para el manejo de controladores del ESP32, en conjunto con un módulo Ublox NEO-6M, el cual se utilizará para obtener la ubicación actual del dispositivo. Se busca construir una solución modular, escalable y de fácil mantenimiento que facilite futuras ampliaciones o modificaciones.

## Estructura del Proyecto

La estructura del repositorio se organiza de la siguiente manera:

```
/src
   └── /Controllers
         ├── BaseController.cpp
         └── AnotherControllerExample.cpp
/main.cpp
```

### Detalle de la Estructura

- **src/**  
  Directorio raíz que contiene todo el código fuente del proyecto.

- **Controllers/**  
  Carpeta dedicada a los controladores, que son los componentes encargados de gestionar la interacción con el hardware (ESP32 y Ublox NEO-6M).  
  - **BaseController.cpp:**  
    Archivo base que contiene las funciones y métodos comunes que serán heredados o reutilizados en otros controladores.
  - **AnotherControllerExample.cpp:**  
    Ejemplo de un controlador adicional. Este archivo puede servir de plantilla o ser adaptado a nuevos requerimientos conforme el proyecto evolucione.

- **main.cpp**  
  Archivo principal del proyecto. Aquí se orquesta la inicialización del sistema y la integración de los distintos controladores.

## Uso de Programación Orientada a Objetos (POO)

Aunque no es un requisito absoluto, se recomienda utilizar la programación orientada a objetos por las siguientes razones:

- **Modularidad:**  
  La POO permite encapsular la lógica en clases, lo que facilita la separación de responsabilidades y la reutilización de código.

- **Escalabilidad:**  
  Al trabajar con clases, se puede extender o modificar el comportamiento de componentes individuales sin afectar la estructura global del sistema.

- **Mantenibilidad:**  
  Un diseño basado en POO facilita la comprensión y el mantenimiento del código, especialmente en proyectos colaborativos o a largo plazo.

Cabe destacar que la decisión de utilizar POO es discutible y puede ajustarse según las necesidades específicas del proyecto.

## Estándar de Commits

Se recomienda la instalación de la extensión **"Conventional commits"** en Visual Studio Code para que los mensajes de commit sean:

- **Más claros y descriptivos:**  
  Facilita la comprensión del historial de cambios y mejora la comunicación entre desarrolladores.

- **Estandarizados:**  
  Permite mantener un formato uniforme en los mensajes de commit, lo que es útil para la integración continua y el versionado semántico del proyecto.

La adopción de esta extensión ayudará a que el desarrollo sea más organizado y que los cambios en el repositorio sean fácilmente rastreables.

## Justificación Técnica

1. **Modularidad y Organización del Código:**  
   La estructura propuesta, separando la lógica de controladores en su propio directorio y dejando el archivo principal de arranque en `main.cpp`, facilita la localización y el mantenimiento del código. Esto es especialmente útil en proyectos embebidos donde la claridad y la separación de responsabilidades son críticas para la eficiencia del desarrollo.

2. **Escalabilidad:**  
   Implementar un diseño orientado a objetos permite que el sistema se expanda sin necesidad de una reestructuración completa. Se podrán agregar nuevos controladores o modificar los existentes de forma modular, adaptándose a futuras necesidades o mejoras en el hardware.

3. **Mantenibilidad:**  
   Un código bien organizado y documentado resulta en una mayor facilidad para identificar y corregir errores. Además, el uso de un estándar en los mensajes de commit (mediante "Conventional commits") mejora la colaboración y el seguimiento de cambios, haciendo que el proyecto sea más robusto en entornos colaborativos.

4. **Facilidad en la Colaboración:**  
   Al estandarizar la estructura del repositorio y los mensajes de commit, se facilita la integración de nuevos desarrolladores. Todos tienen un marco de referencia claro sobre cómo se organiza el proyecto y cómo se deben registrar los cambios, lo que reduce la curva de aprendizaje y minimiza errores en el manejo del código.

