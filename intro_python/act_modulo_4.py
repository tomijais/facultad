def introducir_numero(numero):
    entero = int(input(f"Ingrese el {numero} número entero:"))
    while entero <= 0:
        entero = int(input(f"Ingrese el {numero} número entero:"))
    return entero

primer = introducir_numero("primer")
segundo = introducir_numero("segundo")
 
def suma_divisores(number):
    suma = 0
    for i in range(1, number):
        if (number % i) == 0:
            suma += i
    return suma
 
if (suma_divisores(primer) == segundo) & (suma_divisores(segundo) == primer):
    print("Los numeros ingresados son numeros amigos!!!")
else:
    print("Los numeros ingresados no son numeros amigos :((")
