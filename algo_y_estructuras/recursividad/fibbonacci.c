#include <stdio.h>

int fibb(int pos)
{
    if (pos == 1 || pos == 2)
        return 1;

    return fibb(pos - 1) + fibb(pos - 2);
}

int main()
{
    int pos;
    printf("Ingrese la posicion que desea saber: ");
    scanf("%d", &pos);
    printf("\nLa posicion corresponde al numero: %d", fibb(pos));
}