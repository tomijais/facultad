#include <stdio.h>

void cambiar(int *a, int *b)
{
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

void ejemplo()
{
    int *p = NULL, a = 300, b = 700;

    p = &a;
    *p = 500; // valor de a = 500
    p = &b;
    *p = 6000; // valor de b = 6000
}

void ejemplo_vector()
{
    int vec[30];
    int *p = NULL;
    p = &vec[0];
    *p = 4;
    *(p + 1) = 8;
    *(p + 2) = 3;

    for (int i = 0; i < 3; i++) // es lo mismo que arriba, pero con el for
    {
        scanf("%d", *(p + i));
    }

    p++; // posicion 0 a 1
    p++; // posicion 1 a 2
    p--; // posicion 2 a 1
    p--; // posicion 1 a 0
}

int main()
{
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);
    cambiar(&a, &b);
    printf("%d\n %d", a, b);
}
