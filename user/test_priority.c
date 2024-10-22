#include "kernel/types.h"
#include "user/user.h"

int main(void) {
    int i;

    for (i = 0; i < 20; i++) {
        if (fork() == 0) {
            // Este es el proceso hijo
            printf("Ejecutando proceso %d\n", i);
            sleep(10);  // Detener el proceso por unos segundos
            exit(0);    // Terminar el proceso
        }
    }

    // Esperar a que todos los procesos hijos terminen
    for (i = 0; i < 20; i++) {
        wait(0);
    }

    exit(0);
}
