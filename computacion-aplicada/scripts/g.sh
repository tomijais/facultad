#!/bin/bash

# Escribir un script que reciba 2 números enteros como parámetro y determinar si son iguales,
#  o cuál es mayor que el otro (hacerlo con al menos una función).

compare_numbers() {
   if [[ $1 == $2 ]]; then
      echo "Los números son iguales."
   elif [[ $1 > $2 ]]; then
      echo "El primer número es mayor."
   else
      echo "El segundo número es mayor."
   fi
}

compare_numbers $1 $2