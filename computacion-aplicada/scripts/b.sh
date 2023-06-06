#!/bin/bash

# Escribir un script que muestre por consola la fecha del sistema cada 2 segundos, 10 veces.


for ((i=0; i<10;i++))
do
    date
    sleep 2
done