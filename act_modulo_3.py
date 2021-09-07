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


contador = 1
cantidad_huespedes_total = 0
nombre_mas_habitaciones = ""
cantidad_mas_habitaciones = 0

porcentajeHotel1 = 0
porcentajeHotel2 = 0
porcentajeHotel3 = 0
porcentajeHotel4 = 0
porcentajeHotel5 = 0
porcentajeHotel6 = 0
porcentajeHotel7 = 0
porcentajeHotel8 = 0
porcentajeHotel9 = 0
porcentajeHotel10 = 0

while contador <= 10:
    nombre_actual = input("Ingrese el nombre de la ciudad de la filial: ")
    total_actual = int(input("Ingrese la capacidad total del hotel (en cuanto a huéspedes: "))
    habitaciones_actual = int(input("Ingrese la cantidad de habitaciones: "))
    huespedes_mes_actual = int(input("Ingrese la cantidad de huéspedes en un mes: "))

    cantidad_huespedes_total =+ total_actual
    
    huespedes_mes_actual*100/total_actual

    if contador == 1:
        porcentajeHotel1 = huespedes_mes_actual*100/total_actual
    elif contador == 2:
        porcentajeHotel2 = huespedes_mes_actual*100/total_actual
    elif contador == 3:
        porcentajeHotel4 = huespedes_mes_actual*100/total_actual
    elif contador == 4:
        porcentajeHotel4 = huespedes_mes_actual*100/total_actual
    elif contador == 5:
        porcentajeHotel5 = huespedes_mes_actual*100/total_actual
    elif contador == 6:
        porcentajeHotel6 = huespedes_mes_actual*100/total_actual
    elif contador == 7:
        porcentajeHotel7 = huespedes_mes_actual*100/total_actual
    elif contador == 8:
        porcentajeHotel8 = huespedes_mes_actual*100/total_actual
    elif contador == 9:
        porcentajeHotel9 = huespedes_mes_actual*100/total_actual
    elif contador == 10:
        porcentajeHotel10 = huespedes_mes_actual*100/total_actual

    if habitaciones_actual > cantidad_mas_habitaciones:
        nombre_mas_habitaciones = nombre_actual
        cantidad_mas_habitaciones = habitaciones_actual

    contador = contador + 1

print(f"Cantidad de huéspedes que puede alojar toda la cadena de hoteles: {cantidad_huespedes_total}")
print(f"El nombre de la ciudad con la mayor cantidad de habitaciones es: {nombre_mas_habitaciones} con {cantidad_mas_habitaciones}")

print(f"El porcentaje de ocupacion del hotel 1 es de: {porcentajeHotel1}")
print(f"El porcentaje de ocupacion del hotel 2 es de: {porcentajeHotel2}")
print(f"El porcentaje de ocupacion del hotel 3 es de: {porcentajeHotel3}")
print(f"El porcentaje de ocupacion del hotel 4 es de: {porcentajeHotel4}")
print(f"El porcentaje de ocupacion del hotel 5 es de: {porcentajeHotel5}")
print(f"El porcentaje de ocupacion del hotel 6 es de: {porcentajeHotel6}")
print(f"El porcentaje de ocupacion del hotel 7 es de: {porcentajeHotel7}")
print(f"El porcentaje de ocupacion del hotel 8 es de: {porcentajeHotel8}")
print(f"El porcentaje de ocupacion del hotel 9 es de: {porcentajeHotel9}")
print(f"El porcentaje de ocupacion del hotel 10 es de: {porcentajeHotel10}")