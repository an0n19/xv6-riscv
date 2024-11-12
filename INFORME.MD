# TAREA 3 -> Protección de Memoria en xv6

1. Primero cree un branch a partir de la tarea_1 ya que al parecer en tarea_2 no subi la versión final donde ejecutaba correctamente qemu, por tiempoo preferí hacer esto en lugar de encontrar el error, dejandolo para siguientes entregas.
2. Recalcar que para la creación de esta tarea me fui guiando de los consejos de chat gpt, como se nota en algunos de los comentarios de los algoritmos.
3.  Implementación de las Funciones mprotect y munprotect. La función mprotect toma una dirección de memoria y una longitud, y marca la región de memoria correspondiente como solo lectura. La función munprotect funciona de manera similar, pero revierte la protección de solo lectura, restaurando el permiso de escritura para las páginas afectadas.
4. Modificación de la Tabla de Páginas. Para implementar la protección de solo lectura, se modificó la tabla de páginas en xv6. El bit de escritura (W) se utiliza para habilitar o deshabilitar la escritura en una página específica.
5. Para probar las nuevas funcionalidades, se creó un programa en el espacio de usuario llamado tarea_3.c que posee las instrucciones dadas en el github entregado por el profesor.
6. INtegración con syscalls. Añadí la llamada al sistema para mprotect y munprotect en el archivo sysproc.c

PROBLEMAS: Creo logré reeeealizar correctamente la parte de creación de funciones, podía ejecutar correctamente qemu antes de hacer la integración en el sistema, donde empecé a recibir muchos errores y no logré corregir a tiempo para la hora límite, sin embargo estoy seguro son errores menores y no están relacionados con el grueso del código que propuse.