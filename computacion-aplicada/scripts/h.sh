#!/bin/bash

# Escribir un script que muestre un menú y haga lo siguiente:

# i) Mostrar el directorio actual.

# ii) Pedir un nombre de directorio y, si es correcto, establecerlo como actual.

# iii) Listar los elementos del directorio actual que sólo sean archivos (sin usar el comando ls).

# iv) Pedir un nombre de directorio y crearlo. Si no se puede crear, personalizar el error.

# v) Salir (saludando al usuario que ejecutó el programa).

# Si se presiona otra tecla, mostrar "Opción incorrecta".


#!/bin/bash

show_menu() {
   echo "----- Menú -----"
   echo "1. Mostrar el directorio actual."
   echo "2. Establecer un directorio como actual."
   echo "3. Listar los archivos del directorio actual."
   echo "4. Crear un nuevo directorio."
   echo "5. Salir."
}

list_files() {
   echo "Archivos en el directorio actual:"
   for file in *; do
      if [[ -f $file ]]; then
         echo "$file"
      fi
   done
}

echo "¡Bienvenido!"
while true; do
   show_menu
   read -p "Seleccione una opción: " option
   case $option in
      1)
         echo "Directorio actual: $(pwd)"
         ;;
      2)
         read -p "Ingrese el nombre del directorio: " directory
         if [[ -d $directory ]]; then
            cd $directory
            echo "Directorio actual cambiado a $(pwd)"
         else
            echo "Directorio no encontrado."
         fi
         ;;
      3)
         list_files
         ;;
      4)
         read -p "Ingrese el nombre del nuevo directorio: " new_directory
         if mkdir $new_directory; then
            echo "Directorio $new_directory creado correctamente."
         else
            echo "Error al crear el directorio $new_directory."
         fi
         ;;
      5)
         echo "¡Hasta luego!"
         break
         ;;
      *)
         echo "Opción incorrecta."
         ;;
   esac
done
ˆ