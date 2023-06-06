#!/bin/bash

# Escribir un script que, al ejecutarlo como root, reinicie el equipo después de 1 minuto. Si el usuario ejecutor no es root, informar y finalizar el programa.


if [ $EUID != 0 ]; then
   echo "Este script debe ser ejecutado como root."
   exit 1
fi

sleep 1m
reboot
