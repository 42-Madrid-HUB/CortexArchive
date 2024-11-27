# Cortex_archive

``git clone --recursive git@github.com:42-Madrid-HUB/CortexArchive.git``
``make all``

**Descripción**  

`memtrack` es una herramienta diseñada para el manejo y seguimiento seguro de la memoria dinámica en C. Al clonar el repositorio `CortexArchive` y ejecutar `make all` dentro de la carpeta `memtrack`, se genera automáticamente una carpeta `lib/` en la raíz del proyecto. Esta carpeta contiene la biblioteca compilada de `memtrack`, que incluye todas las funciones necesarias para gestionar y liberar la memoria de manera eficiente, junto con los headers asociados.

Para utilizar esta biblioteca al compilar tus proyectos, necesitas:  
1. Incluir la carpeta `lib/` como ruta para los headers con `-Ilib`.  
2. Vincular la biblioteca compilada con `-Llib -lmemtrack`.  

Ejemplo de integración:
```bash
gcc -o my_program my_program.c -Ilib -Llib -lmemtrack
```  
