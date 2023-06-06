#!/bin/bash


# d) Escribir un script que recibe 2 parámetros: una cadena de caracteres y el path a un archivo
# de texto plano. Se deberá buscar dicha cadena dentro del archivo e imprimir por consola 
# "Palabra encontrada" en caso de encontrarla, o "Palabra no encontrada" en caso contrario.
#  Controlar que sea correcta la cantidad de parámetros.


if [[ $# -ne 2 ]]; then
   echo "Cantidad de parámetros incorrecta. Use: $0 <cadena> <archivo>"
   exit 1
fi

cadena=$1
archivo=$2

if grep -q "$cadena" "$archivo"; then
   echo "Palabra encontrada"
else
   echo "Palabra no encontrada"
fi
