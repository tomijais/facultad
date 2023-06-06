#!/bin/bash

# Escribir un script que lea 2 números enteros desde el teclado y determine si son iguales, 
# o cuál es mayor que el otro (hacerlo con al menos una función).

compare_numbers() {
   if [[ $1 == $2 ]]; then
      echo "Los números son iguales."
   elif [[ $1 -gt $2 ]]; then
      echo "El primer número es mayor."
   else
      echo "El segundo número es mayor."
   fi
}

read -p "Ingrese el primer número: " num1
read -p "Ingrese el segundo número: " num2

compare_numbers $num1 $num2
