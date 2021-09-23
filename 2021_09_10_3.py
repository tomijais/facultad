numero_mas_chico = 0
suma_multiplos_3 = 0
cantidad_multiplos_3 = 0

numero = int(input("Ingrese un numero entero positivo: "))


while numero <= 0:
    numero = int(input("Ingrese un numero entero positivo, tiene que ser mayor a cero: "))


for i in range(numero):

    numero_numero = int(input(f"#{i}: Ingrese un numero:"))
    if numero_numero > 0:
        print("El numero es positivo")
    elif numero_numero < 0:
        print("El numero es negativo")
    else:
        print("El numero es cero")


    if numero < numero_mas_chico or i == 0:
        numero_mas_chico = numero

    if numero % 3 == 0:
        cantidad_multiplos_3 = cantidad_multiplos_3 + 1
        suma_multiplos_3 = suma_multiplos_3 + numero

print(f"El numero mas chico es: {numero_mas_chico}")
print(f"El promedio de los numeros multiplos de 3 es de: {suma_multiplos_3/cantidad_multiplos_3}")