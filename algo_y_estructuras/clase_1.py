def isPrime(n):
    if n == 1:
        return False
    for i in range(2, n):
        if n % i == 0:
            return False
    return True


numero = int(input("Ingrese un numero entero: "))
total_primos = 0
cantidad_primos = 0

while(numero > 0):
    if(isPrime(numero)):
        total_primos += numero
        cantidad_primos += 1
    numero = int(input("Ingrese un numero entero: "))


if(cantidad_primos > 0):
    print(f"El promedio de los numeros primos ingresados es de: {total_primos / cantidad_primos}")

