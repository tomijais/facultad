// Ingresar los nxn elementos de una matriz. Calcular el producto de los elementos de la diagonal principañ recursivamente.

#include <stdio.h>

void cargar(int matrix[][10], int dim, int j, int i)
{
    if (i > dim && j > dim)
        return;

    printf("Ingrese el valor: ");
    scanf("%d", &matrix[i][j]);
    if(j < dim)
        cargar(matrix, dim, j + 1, i);
    if(i < dim)
    cargar(matrix, dim, j=0, i + 1);
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

int main()
{
    int matrix[10][10], dim, j, i;

    printf("Ingrese cantidad de filas: ");
    scanf("%d", &dim);
    cargar(matrix, dim - 1, j, i);
    mostrar(matrix, dim);
    return 0;
}


// To do