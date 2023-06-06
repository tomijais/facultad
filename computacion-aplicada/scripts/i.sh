#!/bin/bash

# Escribir un script que, al ejecutarlo como root, reinicie el equipo después de 1 minuto. Si el usuario ejecutor no es root, informar y finalizar el programa.

is_palindrome() {
   input=$1
   reversed=$(echo $input | rev)
   if [[ $input == $reversed ]]; then
      echo "$input es un palíndromo."
   else
      echo "$input no es un palíndromo."
   fi
}

read -p "Ingrese una cadena de caracteres: " string

is_palindrome $string
