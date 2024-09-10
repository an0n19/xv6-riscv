# TAREA 1 -> yosoytupadre.c

1. Cree el archivo yosoytupadre.c en carpeta user
2. Implemente llamada al sistema getppid (no confundir con getpid) en sysproc.c, definir en syscall.h, agregar en syscall.c y añadir una entrada en usys.pl
3. Modifiqué el MakeFile cosa de que leyera el codigo agregado
4. Probe ejecutando QEMU y escribiendo yosoytupadre

NOTA: Me guié de la materia de la clase + Chat GPT para orientarme, tuve algunos problemas debido a cambio de tipo de variables y posición donde declararlas, error más común fue el que no me reconocía getppid, cosa que gracias a la IA mencionada y mis apuntes pude corregir.