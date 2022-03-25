#include <stdio.h>
void cargar(int mat[10][10], int a)
{
    int i, j;
    for (i = 0; i < a; i++)
    {
        for (j = 0; j < a; j++)
        {
            printf("Ingrese valor");
            scanf("%d", &mat[i][j]);
        }
    }
}
void mostrar(int mat[][10], int a)
{
    int i, j;
    for (i = 0; i < a; i++)
    {
        printf("\n");
        for (j = 0; j < a; j++)
        {
            printf("%d\t", mat[i][j]);
        }
    }
}
void multiplicar(int mat[10][10], int dim, int mat1[][10])
{
    int i, j, k;
    for (i = 0; i < dim; i++)
    {
        for (j = 0; j < dim; j++)
        {
            mat1[i][j] = 0;
            for (k = 0; k < dim; k++)
            {
                mat1[i][j] = mat1[i][j] + mat[i][k] * mat[k][j];
            }
        }
    }
}

int main()
{
    int mat[10][10], mat1[10][10], dim;
    printf("Ingrese cantidad de filas");
    scanf("%d", &dim);
    cargar(mat, dim);
    mostrar(mat, dim);
    multiplicar(mat, dim, mat1);
    mostrar(mat1, dim);
}