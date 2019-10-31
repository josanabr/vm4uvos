# Guía para la instalación de máquina virtual con Linux y Docker
**John Sanabria - john.sanabria@correounivalle.edu.co**

## Resumen
En este documento se da una descripción de los pasos que se requieren para desplegar una máquina virtual con Linux y Docker.

## Requerimientos
Para llevar a cabo este despliegue se hace necesario tener instalados los siguientes paquetes de software:
* **Vagrant versión 2.2.6**. Sugiero hacer la instalación desde los repositorios provistos por la empresa que construyó Vagrant.
* **VirtualBox versión 6.0.14r133895**. Sugiero hacer la instalación desde los repositorios provistos por la empresa que mantiene VirtualBox.

## Validando la instalación
Para validar la instalación de los paquetes por favor abra una terminal y ejecute los siguientes comandos:

```
vagrant version
```

```
vboxmanage -v
```

La salida al ejecutar estos comandos en mi terminal fue algo como lo que se ve en este [video](https://asciinema.org/a/277015).

## Desplegando la máquina virtual
Para desplegar la máquina virtual clonar este repositorio de GitHub.

```
git clone https://github.com/josanabr/vm4uvos.git
```

Ir al directorio vm4uvos

```
cd vm4uvos
```

Descargar la plantilla del sistema operativo Linux

```
vagrant box add ubuntu/xenial64
```

Aprovisionar la máquina

```
vagrant up
```

## Validando el despliegue

Ejecutar el siguiente comando para ingresar a la máquina virtual

```
vagrant ssh
```

Ejecutar el siguiente comando para validar que Docker está operando de forma correcta

```
docker images
```

## Saliendo de la máquina virtual

Para salir de la máquina virtual se ejecuta el comando

```
exit
```

Para detener la máquina virtual se ejecuta el comando

```
vagrant halt
```

## Volver a usar la máquina virtual

Ejecutar el comando

```
vagrant up --no-provision
```

---

## Instalando XV6

La nueva version de XV6 está diseñada para trabajar sobre sistemas RISC-V.
RISC-V es otra arquitectura de computador y trataremos de continuar sobre la arquitectura x86.
De todos modos, la mayoría del código relativo a la arquitectura de un computador está oculto para el desarrollador (incluso las llamadas al sistema).
Para facilitar el soporte a múltiples plataformas de hardware, lo que se busca es que la mayoría de las operaciones relativas a la arquitectura del computador se escriban en lenguaje máquina y queden circunscritas a partes del código muy particulares.

Se describirán ahora los pasos para hacer la instalación de XV6 en la máquina virtual desplegada anteriormente.

Ingresar via SSH a la máquina virtual, `vagrant ssh`. 
Se procede a clonar el repositorio de XV6.
Para ello se sugiere ir al directorio `/vagrant` dentro de la máquina virtual.
Una vez en este directorio (ejecutar `pwd` y el comando debería arrojar por pantalla `/vagrant`) ejecutar el siguiente comando:

```
git clone https://github.com/mit-pdos/xv6-public.git
```

Para compilar este sistema operativo se hace necesario la instalación de varios paquetes y para ello se usa la siguiente línea de comandos:

```
sudo apt-get install qemu ghostscript mpage
```

Estos paquetes permitirán la compilación del sistema operativo y la generación del archivo PDF con el código del sistema operativo. 

Para compilar el sistema operativo y su posterior ejecución se debe ingresar al directorio `xv6-public`, el cual se creó después de llevar a cabo la clonación, `cd xv6-public`.  
Ahora se ejecuta el siguiente comando:

```
make qemu-nox
```

Este sistema es muy básico y tiene muy pocos comandos.
De hecho, este sistema no tiene un comando que permita la salida del sistema. 
Para salir del sistema operativo se sugiere ejecutar los siguientes pasos:

* Abrir otra terminal
* Ingresar con `vagrant ssh` a la máquina virtual
* Buscar el comando `make qemu-nox` e identificar su `pid`, `ps ax | grep qemu-nox`
* Con el número obtenido anteriormente, procede a eliminar el proceso, `kill -9 <pid_encontrado>`

Una vez ejecute estos pasos usted podrá volver a la terminal anterior y el sistema operativo ya habrá terminado su ejecución.

Para compilar el manual de XV6 se ejecuta el siguiente comando:

```
make xv6.pdf
```

