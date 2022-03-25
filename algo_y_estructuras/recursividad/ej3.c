// Ingresar los nxn elementos de una matriz. Calcular el producto de los elementos de la diagonal principañ recursivamente.

#include <stdio.h>

void cargar(int matrix[][10], int dim)
{
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            printf("Ingrese el valor: ");
            scanf("%d", &matrix[i][j]);
        }
    }
}

void mostrar(int matrix[][10], int dim)
{
    for (int i = 0; i < dim; i++)
    {
        printf("\n");
        for (int j = 0; j < dim; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
    }
}

int producto_diagonal(int matrix[][10], int dim)
{

    if (dim == 0)
        return matrix[dim][dim];

    return producto_diagonal(matrix, dim - 1) * matrix[dim][dim];
}

int main()
{
    int matrix[10][10], dim;

    printf("Ingrese cantidad de filas: ");
    scanf("%d", &dim);
    cargar(matrix, dim);
    mostrar(matrix, dim);
    printf("\nLa posicion corresponde al numero: %d", producto_diagonal(matrix, dim - 1));

    return 0;
}