numeros_multiplos_5 = []


def numeros_mas_grandes(array, cantidad):
    newArr = array[:]
    returnArray = []

    for i in range(cantidad):

        if(len(newArr) != 0):
            numero_mas_grande=max(newArr)
            returnArray.append(numero_mas_grande)
            newArr.remove(max(newArr))
        
    print(array)
    return returnArray

def multiplos_de_10(array):
    newArr = array[:]
    returnArray = []

    for i in array:

        if(i % 10 != 0):
            print(i)
            returnArray.append(i)

        if(len(returnArray) == 0):
            return "No hay valores multiplos de 10"

    return returnArray



numero = int(input("Ingrese un numero: "))
while numero != 0:
    if(numero % 5 == 0):
        numeros_multiplos_5.append((numero))
    numero = int(input("Ingrese un numero: "))


maximos = numeros_mas_grandes(numeros_multiplos_5, 3)



multiplos = multiplos_de_10(numeros_multiplos_5)


print(f"Los 3 primeros números más grandes: {maximos}")
print(f"Los multiplos de 10 son: {multiplos}")