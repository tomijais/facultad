# Hallar la longitud de la hipotenusa de un triángulo dada la medida de sus
# catetos

cateto1 = int(input("Ingrese el valor del cateto 1: " ))
cateto2 = int(input("Ingrese el valor del cateto 2: " ))

hipotenusa = (cateto1**2 + cateto2**2)**0.5

print("El valor de la hipotenusa es de: ", hipotenusa)