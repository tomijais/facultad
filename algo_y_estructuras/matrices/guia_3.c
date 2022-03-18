// 1)

#include <stdio.h>

void cargar(int matrix[3][3], int dim)
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

void mostrar(int matrix[3][3], int dim)
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

void sumatoria_elementos_fila_n(int matrix[3][3], int dim, int fila)
{
    int contador = 0;
    for (int j = 0; j < dim; j++)
    {
        contador += matrix[fila][j];
    }

    printf("\n\nLa sumatoria de los elementos de la fila %d es de %d", fila + 1, contador);
}

void mayor_elemento_columna_n(int matrix[3][3], int dim, int columna)
{
    int mayor = matrix[0][columna];

    for (int i = 0; i < dim; i++)
    {
        if (matrix[i][columna] > mayor)
        {
            mayor = matrix[i][columna];
        }
    }

    printf("\n\El mayor valor de la columna %d es de %d", columna + 1, mayor);
}

void promedio_multiplos_n(int matrix[3][3], int dim, int multiplo)
{
    int contador = 0, cantidad = 0;
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            if (matrix[i][j] % multiplo == 0)
            {
                contador = contador + matrix[i][j];
                cantidad = cantidad + i;
            }
        }
    }
    if (contador != 0)
    {
        printf("\n\El promedio de los numeros multiplos de %d es de %d", multiplo, contador / cantidad);
    }
}

void simetrica(int matrix[3][3], int dim)
{
    int contador = 0;
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            if (matrix[i][j] == matrix[j][i])
            {
                contador++;
            }
        }
    }
    if (contador == dim * dim)
    {
        printf("\nLa matriz es simetrica");
    }
    else
    {
        printf("\nLa matriz es simetrica");
    }
}

int main()
{
    int matrix[3][3], dim;

    printf("Ingrese cantidad de filas: ");
    scanf("%d", &dim);
    cargar(matrix, dim);
    mostrar(matrix, dim);
    int fila = 1;
    sumatoria_elementos_fila_n(matrix, dim, fila);
    int columna = 1;
    mayor_elemento_columna_n(matrix, dim, columna);
    int multiplo = 5;
    promedio_multiplos_n(matrix, dim, multiplo);
    simetrica(matrix, dim);
}