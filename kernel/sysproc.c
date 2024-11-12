#include "types.h"
#include "riscv.h"
#include "defs.h"
#include "param.h"
#include "memlayout.h"
#include "spinlock.h"
#include "proc.h"
//#include "/home/kali/xv6-riscv/user/user.h"

uint64
sys_exit(void)
{
  int n;
  argint(0, &n);
  exit(n);
  return 0;  // not reached
}

uint64
sys_getpid(void)
{
  return myproc()->pid;
}

uint64
sys_fork(void)
{
  return fork();
}

uint64
sys_wait(void)
{
  uint64 p;
  argaddr(0, &p);
  return wait(p);
}

uint64
sys_sbrk(void)
{
  uint64 addr;
  int n;

  argint(0, &n);
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

uint64
sys_sleep(void)
{
  int n;
  uint ticks0;

  argint(0, &n);
  if(n < 0)
    n = 0;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(killed(myproc())){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

uint64
sys_kill(void)
{
  int pid;

  argint(0, &pid);
  return kill(pid);
}

// return how many clock tick interrupts have occurred
// since start.
uint64
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

uint64
sys_getppid(void) {
    struct proc *p = myproc();  // Obtener el proceso actual
    return p->parent->pid;      // Devolver el PID del proceso padre
}

int sys_mprotect(void) {
    void *addr;
    int len;  // Asegúrate de que len sea de tipo int

    // Cambiar `&addr` a `(void**)&addr` para pasar correctamente el tipo esperado
    if (argptr(0, &addr, sizeof(addr)) < 0)
            return -1;
        
        // Asegúrate de pasar la dirección de `len` correctamente
        if (argint(1, &len) < 0)
            return -1;
        
        return sys_mprotect(addr, len);  // Llamar a sys_mprotect, no a mprotect
}

int sys_munprotect(void) {
    void *addr;
    int len;

    // Cambiar `&addr` a `(void**)&addr` para pasar correctamente el tipo esperado
    if (argptr(0, &addr, sizeof(addr)) < 0)
        return -1;
    
    // Asegúrate de pasar la dirección de `len` correctamente
    if (argint(1, &len) < 0)
        return -1;
    
    return sys_munprotect(addr, len);  // Llamar a sys_munprotect, no a munprotect
}
