#include <stdio.h>

int main()
{
    int c, anterior;
    printf("Ingese una frase terminada en punto: ");
    c = getchar();
    while (c != '.')
    {

        while( anterior != ' ' && c == ' ' && getchar() != ' ' && c != '.'){
            putchar(c);
        }

        anterior = c;
        c = getchar();
    }
}


