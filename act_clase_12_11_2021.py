# Una distribuidora de gaseosas lleva el registro de ventas
# - Nº factura
# - Código cliente ( 1 – 100) 
# - Código bebida ( Cola 1, Naranja 2, Lima 3, Pomelo 4 )
# - Cantidad vendida en litros
# La carga finaliza con factura = 0, y el número de la factura no puede ser menor a la anterior

# Se sabe que las bebidas cuestan
# Cola $225
# Naranja $215
# Lima $212
# Pomelo $217
# Se solicita:

# - Cargar y mostrar los datos, incluyendo el total de cada factura
# - Cliente con mas ventas – cantidad de facturas
# - Monto promedio facturado
# - Porcentaje de ventas de cada bebida en litros
# - Sabor mas vendido – pesos
# - Sabor menos vendido – litros
# - Cual fue el sabor de menor venta - pesos






def carga(ultima_factura,arr_factura, arr_clientes, arr_bebidas, arr_precios, arr_litros_pedidos, arr_bebida_pedida):
    numero_factura = int(input("Ingrese un numero de factura: "))
    while numero_factura != 0:
        if(numero_factura <= ultima_factura):
            numero_factura = int(input("Ingrese un numero de factura valida: "))
        ultima_factura = numero_factura
        arr_factura.append(numero_factura)

        numero_cliente = int(input("Ingrese un codigo de cliente: "))
        while(not(numero_cliente >= 1 and numero_cliente <= 100)):
            numero_factura = int(input("Ingrese un codigo de cliente valido: "))
        arr_clientes.append(numero_cliente)


        for i in range(len(arr_bebidas)):
            print(f"#{i + 1} - {arr_bebidas[i]}")
        numero_bebida = int(input("Ingrese un codigo de bebida: "))

        while(not(numero_bebida >= 1 and numero_bebida <= len(arr_bebidas))):
            numero_bebida = int(input("Ingrese un codigo de bebida valido: "))
        arr_bebida_pedida.append(numero_bebida)
        

        numero_litros = int(input("Ingrese la cantidad de litros vendida: "))
        while(not(numero_bebida >= 0)):
            numero_bebida = int(input("Ingrese una cantidad valida: "))
        arr_litros_pedidos.append(numero_litros)



        numero_factura = int(input("Ingrese un numero de factura: "))


def imprimir(arr_clientes, arr_bebidas, arr_precios, arr_litros_pedidos, arr_bebida_pedida):
    print("Factura\tCliente\tBebida\tLitros\Valor")
    for i in range(len(arr_factura)):
        print(f"{arr_factura[i]}\t{arr_clientes[i]}\t{arr_bebidas[arr_bebida_pedida[i] - 1]}\t{arr_litros_pedidos[i]}\t${arr_litros_pedidos[i] * arr_precios[i]}")

    mas_ventas = cliente_mas_ventas(arr_clientes)
    promedio = calcular_promedio(arr_litros_pedidos, arr_precios, arr_bebida_pedida)

    print(f"El cliente que tuvo mas ventas fue: {mas_ventas}")
    print(f"El promedio de facturado fue: ${promedio}")
    imprimir_porcentaje_cada_bebida(arr_bebidas, arr_litros_pedidos, arr_bebida_pedida)
    sabor_mas_vendido(arr_bebidas, arr_bebida_pedida, arr_precios)


def cliente_mas_ventas(arr_clientes):

    clientes = [0]*100
    
    for i in range(len(arr_clientes)):
        clientes[arr_clientes[i] - 1] += 1

    max_cliente = 0
    for i in clientes:
        if i > max_cliente:
            max_cliente = i
    return max_cliente

def calcular_promedio(arr_litros_pedidos, arr_precios, arr_bebida_pedida):
    total = 0
    for i in range(len(arr_litros_pedidos)):
        bebida = arr_bebida_pedida[i]
        print(bebida)
        total += arr_litros_pedidos[i] * arr_precios[bebida - 1]
    return total / len(arr_litros_pedidos)

def imprimir_porcentaje_cada_bebida(arr_bebidas, arr_litros_pedidos, arr_bebida_pedida):

    cantidad_litros = 0
    cantidad_litros_por_bebida = []

    for i in range(len(arr_bebidas)):
        cantidad_litros_por_bebida.append(0)

    for i in arr_litros_pedidos:
        cantidad_litros += i

    for i in range(len(arr_bebida_pedida)):
        cantidad_litros_por_bebida[arr_bebida_pedida[i] - 1] += arr_litros_pedidos[i]

    for i in range(len(cantidad_litros_por_bebida)):
        print(f"El porcentaje de {arr_bebidas[i]} vendidas en litros fue de {cantidad_litros_por_bebida[i] * 100 / cantidad_litros }%")


def sabor_mas_vendido(arr_bebidas, arr_bebida_pedida, arr_precios):
    bebidas_pedidas = [0]*len(arr_bebidas)

    for i in range(len(arr_bebida_pedida)):
        bebidas_pedidas[arr_bebida_pedida[i] - 1] += 1 * arr_precios[i]

    print(bebidas_pedidas)


ultima_factura = 0
arr_factura = []
arr_clientes = []
arr_litros_pedidos = []
arr_bebida_pedida = []

arr_bebidas = ["Cola", "Naranja", "Lima", "Pomelo"]
arr_precios = [225, 215, 212, 217]



carga(ultima_factura,arr_factura,  arr_clientes, arr_bebidas, arr_precios, arr_litros_pedidos, arr_bebida_pedida)
imprimir(arr_clientes, arr_bebidas, arr_precios, arr_litros_pedidos, arr_bebida_pedida)

