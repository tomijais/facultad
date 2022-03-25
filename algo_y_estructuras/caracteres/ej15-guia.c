#include <stdio.h>

int main()
{
    int c, contador = 0, cont_palabra = 0, letra_anterior;
    printf("Ingese una frase terminada en punto: ");
    c = getchar();
    letra_anterior = c;
    while (c != '.')
    {
        while (c != ' ' && c != '.')
        {
            c = getchar();

            if (letra_anterior == c)
            {
                cont_palabra++;
            }

            if (cont_palabra >= 2)
            {
                putchar(cont_palabra);
                printf("=");
                putchar(c);
            }
            letra_anterior = c;
            cont_palabra = 0;
        }
        if (c != '.')
        {
            c = getchar();
        }
    }
    printf("contador: %d", contador);
    printf("cantidad palabra: %d", contador);
}



// No funciona :)