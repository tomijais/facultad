// #include <stdio.h>

// int main()
// {

//     int num, cantidad_numeros_cargados = 0, arr[100];
//     printf("Ingresar un numero entero: ");
//     scanf("%d", &num);

//     while (num != 0)
//     {
//         if (num % 2 != 0 && num % 3 == 0)
//         {
//             if (num < 0)
//             {
//                 arr[cantidad_numeros_cargados] = num;
//                 arr[cantidad_numeros_cargados + 1] = num + 1;
//                 cantidad_numeros_cargados += 2;
//             }
//             else
//             {
//                 arr[cantidad_numeros_cargados] = num;
//                 cantidad_numeros_cargados++;
//             }
//         }

//         printf("Ingresar un numero entero: ");
//         scanf("%d", &num);
//     }
//     if (cantidad_numeros_cargados > 0)
//     {
//         for (int i = 0; i < cantidad_numeros_cargados; i++)
//         {
//             printf("%d\n", arr[i]);
//         }
//     }
//     else
//     {
//         printf("No se cargaron numeros que cumplan con las conficiones");
//     }
// }

#include <stdio.h>

int cargar(int num, int cantidad_numeros_cargados, int arr[])
{
    if (num % 2 != 0 && num % 3 == 0)
    {
        if (num < 0)
        {
            arr[cantidad_numeros_cargados] = num;
            arr[cantidad_numeros_cargados + 1] = num + 1;
            cantidad_numeros_cargados += 2;
        }
        else
        {
            arr[cantidad_numeros_cargados] = num;
            cantidad_numeros_cargados++;
        }
    }

    return cantidad_numeros_cargados;
}

void mostrar(int cantidad_numeros_cargados, int arr[])
{
    for (int i = 0; i < cantidad_numeros_cargados; i++)
    {
        printf("%d\n", arr[i]);
    }
}

int main()
{

    int num, cantidad_numeros_cargados = 0, arr[100];
    printf("Ingresar un numero entero: ");
    scanf("%d", &num);

    while (num != 0)
    {
        cantidad_numeros_cargados = cargar(num, cantidad_numeros_cargados, arr);
        printf("Ingresar un numero entero: ");
        scanf("%d", &num);
    }
    if (cantidad_numeros_cargados > 0)
    {
        mostrar(cantidad_numeros_cargados, arr);
    }
    else
    {
        printf("No se cargaron numeros que cumplan con las conficiones");
    }
}
