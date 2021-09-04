# En base a los conceptos vistos en el módulo, debés realizar el siguiente ejercicio: 

# Diseñar un programa en Python que permita:

# Una cadena de hoteles cuenta con 10 filiales y necesita obtener algunas estadísticas para mejorar sus servicios. Para ello se ingresan:

# Nombre de la ciudad de la filial
# Capacidad total del hotel (en cuanto a huéspedes)
# Cantidad de habitaciones
# Cantidad de huéspedes en un mes.
# Calcular y mostrar:

# Cantidad de huéspedes que puede alojar toda la cadena de hoteles
# Porcentaje de ocupación de cada hotel.
# El nombre de la ciudad con la mayor cantidad de habitaciones. 


contador = 0
cantidad_huespedes_total = 0
nombre_mas_habitaciones = ""
cantidad_mas_habitaciones = 0

while contador < 10:
    nombre_actual = input("Ingrese el nombre de la ciudad de la filial: ")
    total_actual = int(input("Ingrese la capacidad total del hotel (en cuanto a huéspedes: "))
    habitaciones_actual = int(input("Ingrese la cantidad de habitaciones: "))
    huespedes_mes_actual = int(input("Ingrese la cantidad de huéspedes en un mes"))

    cantidad_huespedes_total =+ total_actual
    
    if habitaciones_actual > cantidad_mas_habitaciones:
        nombre_mas_habitaciones = nombre_actual
        cantidad_mas_habitaciones = habitaciones_actual

    contador = contador + 1

print(f"Cantidad de huéspedes que puede alojar toda la cadena de hoteles: {cantidad_huespedes_total}")
print(f"El nombre de la ciudad con la mayor cantidad de habitaciones: {nombre_mas_habitaciones} con {cantidad_mas_habitaciones}")