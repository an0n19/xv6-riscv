#include "/home/kali/xv6-riscv/kernel/types.h"
//#include "/home/kali/xv6-riscv/kernel/stat.h"
#include "/home/kali/xv6-riscv/user/user.h"
//#include "/home/kali/xv6-riscv/kernel/syscall.h"


int main() {
    int ppid = getppid();  // Llamar a la nueva syscall para obtener el PID del proceso padre
    printf("El PID de mi padre es: %d\n", ppid);
    exit(0);
}