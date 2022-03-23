#include <stdio.h>

int main()
{
    int c, contador = 0, cont_palabra = 0;
    printf("Ingese una frase terminada en punto: ");
    c = getchar();
    while (c != '.')
    {
        while (c != ' ' && c != '.')
        {
            cont_palabra++;
            c = getchar();
        }

        if (cont_palabra >= 3)
        {
            contador++;
        }
        cont_palabra = 0;
        if (c != '.')
        {
            c = getchar();
        }
    }
    printf("La cantidad de palabras con 3 letras es de: %d", contador);
}