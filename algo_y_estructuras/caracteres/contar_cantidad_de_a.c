#include <stdio.h>

int main()
{
    int c, contador = 0;
    printf("Ingese una frase terminada en punto: ");
    c = getchar();
    while (c != '.')
    {
        
        if (c == 'a')
        {
            contador++;
        }
        c = getchar();
    }

    printf("La cantidad de a es de %d", contador);
}