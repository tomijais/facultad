# Ingresar un número de tres cifras y mostrar el segundo dígito.


numeroDeTresCifras = int(input("Ingrese un numero de tres cifras: "))

sinPrimerDigito = numeroDeTresCifras - numeroDeTresCifras // 100 * 100

segundoDigito = sinPrimerDigito // 10


print(segundoDigito)