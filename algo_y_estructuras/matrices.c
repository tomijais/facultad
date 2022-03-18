#include <stdio.h>

void cargar(int matrix[10][10], int dim)
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

void mostrar(int matrix[10][10], int dim)
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

int main()
{
    int matrix[10][10], dim;

    printf("Ingrese cantidad de filas: ");
    scanf("%d", &dim);
    cargar(matrix, dim);
    mostrar(matrix, dim);

    return 0;
}