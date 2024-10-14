#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

#define NUM_PROCESOS 20  // Número de procesos a crear

int main(int argc, char *argv[]) {
    for (int i = 0; i < NUM_PROCESOS; i++) {
        int pid = fork();  // Crear un nuevo proceso
        if (pid < 0) {
            printf(2, "Error en fork\n");  // Manejar error en fork
            exit(1);  // Salir con código de error
        }
        
        if (pid == 0) {  // Proceso hijo
            // Mostrar mensaje con el nombre y pid
            printf(1, "Ejecutando proceso hijo %d, pid: %d\n", i + 1, getpid());
            sleep(5);  // Hacer que el proceso duerma durante 5 segundos
            exit(0);  // Terminar el proceso hijo con estado 0
        }
    }

    // Esperar a que todos los procesos hijos terminen
    for (int i = 0; i < NUM_PROCESOS; i++) {
        int status;  // Variable para almacenar el estado del proceso
        wait(&status);  // Esperar que termine un proceso hijo
    }

    exit(0);  // Terminar el proceso principal con estado 0
}