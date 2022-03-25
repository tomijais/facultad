// Ingresar los n numeros enteros de un arreglo y calcular la suma de sus elementos en forma recursiva

#include <stdio.h>

void cargar(int arr[], int dim)
{
    for (int i = 0; i < dim; i++)
    {
        printf("Ingrese elemento a cargar: ");
        scanf("%d", &arr[i]);
    }
}

void mostrar(int arr[], int dim)
{
    for (int i = 0; i < dim; i++)
    {
        printf("\t%d", arr[i]);
    }
}

int suma(int arr[], int dim)
{
    if(dim == 0)
        return arr[dim];
    return suma(arr, dim - 1) + arr[dim];
}

int main()
{
    int num, dim;
    printf("Ingrese la dimension del array: ");
    scanf("%d", &dim);
    int arr[dim];
    cargar(arr, dim);
    mostrar(arr, dim);
    printf("\n La suma de las pociones de la dimension del array es de: %d", suma(arr, dim - 1));
    return 0;
}