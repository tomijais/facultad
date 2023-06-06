#!/bin/bash

# Escribir un script que reciba como parámetro el path a un archivo y determine si existe o no y qué tipo de archivo es.

if [[ $# != 1 ]]; then
   echo "Cantidad de parámetros incorrecta. Uso: $0 <archivo>"
   exit 1
fi

archivo=$1

if [[ -e $archivo ]]; then
   echo "$archivo existe."
   if [[ -f $archivo ]]; then
      echo "$archivo es un archivo regular."
   elif [[ -d $archivo ]]; then
      echo "$archivo es un directorio."
   else
      echo "$archivo es un tipo de archivo desconocido."
   fi
else
   echo "$archivo no existe."
fi
