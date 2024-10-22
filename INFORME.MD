# Tarea 2: Implementación del Sistema de Prioridades en xv6

## Funcionamiento del Sistema de Prioridades
Hemos modificado el programador de procesos en xv6 para que los procesos se ejecuten según su prioridad, la cual cambia dinámicamente usando un sistema de boost.

- **Prioridad**: Los procesos comienzan con prioridad 0. El número más bajo indica mayor prioridad.
- **Boost**: El boost controla cómo cambia la prioridad. Si la prioridad llega a 9, el boost se ajusta a -1. Si la prioridad baja a 0, el boost se ajusta a 1.

## Modificaciones realizadas
1. **Estructura de procesos**: Se añadieron los campos `priority` y `boost` en `proc.h`.
2. **Inicialización**: En la función `allocproc()`, los campos de prioridad se inicializan a 0 y boost a 1.
3. **Lógica de scheduler**: La prioridad de los procesos RUNNABLE se ajusta dinámicamente en el `scheduler()`.
4. **Pruebas**: Se creó un programa que genera 20 procesos y muestra cómo el sistema de prioridades los afecta.

## Dificultades encontradas
- Al ayudarme de inteligencia artificial tuve algunos errores en el código, específicamente en proc.c, ya que no se me especificó mucho donde debían ir los cambios y me las ingenié para que funcionara, creo que logré lo solicitado.
