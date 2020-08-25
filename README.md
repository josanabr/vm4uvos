# Guía para la instalación de máquina virtual con Linux y Docker
**John Sanabria - john.sanabria@correounivalle.edu.co**

## Resumen
En este documento se da una descripción de los pasos que se requieren para desplegar una máquina virtual con Linux y Docker desde la línea de comandos.

## Requerimientos
Para llevar a cabo este despliegue se hace necesario tener instalados los siguientes paquetes de software:
* **Vagrant versión 2.2.9**. Sugiero hacer la instalación desde los repositorios provistos por la empresa que construyó Vagrant [enlace](https://www.vagrantup.com/downloads).
* **VirtualBox versión 6.1.10r138449**. Sugiero hacer la instalación desde los repositorios provistos por la empresa que mantiene VirtualBox [enlace](https://www.virtualbox.org/wiki/Downloads).

## Validando la instalación
Para validar la instalación de los paquetes por favor abra una terminal y ejecute los siguientes comandos:

```
vagrant version
```

Debería aparecer `Vagrant 2.2.9`.

```
VBoxManage -v
```

Debería aparecer `6.1.10r138449`.

La salida al ejecutar estos comandos en mi terminal fue algo como lo que se ve en este [video](https://asciinema.org/a/277015).

## Desplegando la máquina virtual
Para desplegar la máquina virtual clonar este repositorio de GitHub.

```
git clone https://github.com/josanabr/vm4uvos.git
```

Ir al directorio `vm4uvos`

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

