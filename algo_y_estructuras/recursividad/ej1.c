// Ingresar un numero entero y mostrarlo recursivamente invertido

#include <stdio.h>

void invertir(int num)
{
    if (num < 10)
        printf("%d", num);
    else
        printf("%d", num % 10);
    if (num >= 10)
        invertir(num / 10);
}

int main()
{
    int num;
    printf("Ingrese el numero que desea imprimir: ");
    scanf("%d", &num);
    invertir(num);
    return 0;
}

// Ingresar un texto caracter a caracter terminado en punto o enter y mostrar el texto invertido en forma recursiva.