# Capítulo 1

En este capítulo se llevarán a cabo algunas prácticas que le permitirán al estudiante evidenciar algunos de los conceptos descritos en este primer capítulo.

## Jerarquía de memoria

La memoría de un computador se entiende como aquel espacio en el cual se almacenan datos.
Los niveles de memoria que se pueden encontrar en un computador del más veloz al menos veloz se pueden enumerar de la siguiente manera: registros de la CPU, memoria cache, memoria RAM y memoria de intercambio (o *swap*).
Para evidenciar como impacta la forma como se acceden a los datos se implementará de dos maneras la suma de dos matrices de tamaño N x N.

Se ha escrito un programa en C que dependiendo del argumento que se le pase al aplicativo hará el acceso a los datos de la matriz o por fila y luego columna (ausencia de argumentos) o por columna y luego fila (ante la presencia de un argumento cualquiera).

* [addmat](cap01/addmat.c)

### Pre-requisitos

Ejecutar el siguiente comando para instalar el programa que determina el rendimiento de su aplicación 

```
sudo apt-get install linux-tools-common linux-tools-generic linux-cloud-tools-generic valgrind
```

### Compilación y ejecución del programa

El programa a compilar se llama `addmat.c`.
Este programa suma dos matrices (`a` y `b`) y guarda el resultado en una tercera matriz (`c`).
Para compilar el programa se ejecuta el comando

```
gcc -g addmat.c -o addmat
```

Para ejecutarlo y ver los *missess* por **filas** se ejecuta de la siguiente manera:

```
valgrind --tool=cachegrind ./addmat 
```

Y para la ejecución por **columnas** es:

```
valgrind --tool=cachegrind ./addmat 1
```

## Analizar los datos de salida
