# En base a los conceptos vistos en el módulo, debés realizar el siguiente ejercicio: 

# Cargar un arreglo con 12 números enteros. Mostrarlo y calcular:

# El elemento máximo y mínimo.
# Calcular el promedio de los elementos ubicados en posiciones pares.
# Calcular la sumatoria de los elementos pares en posiciones impares.
# Calcular la cantidad de numeros primos.

def es_primo(num):
    for i in range(2, num):
        if num % i == 0:
            return False
    return True

arr = [1,2,3,4,5,6,7,8,9,10,11,12]

sum = 0

cantidad_primos = 0

for i in range(len(arr)):
    if(i%2 != 0 and arr[i] == 0):
        sum = sum + arr[i]


    if(es_primo(arr[i])):
        cantidad_primos = cantidad_primos + 1





print(arr)

print(f"El elemento minimo es: {min(arr)}")
print(f"El elemento maximo es: {max(arr)}")
print(f"La cantidad de numeros primos que hay es: {cantidad_primos}")

