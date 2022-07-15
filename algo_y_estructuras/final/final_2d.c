// verify indentity matrix recursive

#include <stdio.h>
#include <stdlib.h>

int mostrar(int matrix[10][10], int dim)
{
    for (int i = 0; i < dim; i++)
    {
        printf("\n");
        for (int j = 0; j < dim; j++)
        {
            printf("%d  \t", matrix[i][j]);
        }
    }
}

int crear(int matrix[10][10], int dim)
{
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            printf("Ingrese el numero a insertar:  \n");
            scanf("%d", &matrix[i][j]);
        }
    }
}

int identidad(int matrix[10][10], int i, int j, int dim)
{
    int a = matrix[0][0];
    int b = matrix[0][1];
    int c = matrix[1][0];
    int d = matrix[1][1];


    if (i == dim)
    {
        return 1;
    }
    if (matrix[i][j] != 1 && i == j)
    {
        return 0;
    }
    if (matrix[i][j] != 0 && i != j)
    {
        return 0;
    }
    return identidad(matrix, i + 1, j + 1, dim);
}

int main()
{
    int dim, matrix[10][10];
    printf("Ingrese el numero de nodos: ");
    scanf("%d", &dim);
    crear(matrix, dim);
    mostrar(matrix, dim);



    if(identidad(matrix, 0, 0, dim) == 1){
        printf("\nLa matriz es identidad");
    }else{
        printf("\nLa matriz no es identidad");
    }

    return 0;
}