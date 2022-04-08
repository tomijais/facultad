// Ingresar un texto caracter a caracter terminado en punto o enter y mostrar el texto invertido en forma recursiva.
#include <stdio.h>

void invertir(int c)
{
    if (c == '.' || c == '\n')
    {
        return;
    }
    c = getchar();
    invertir(c);
    putchar(c);
}

int main()
{
    int c;
    printf("Ingese una frase terminada en punto o enter: ");
    c = getchar();
    invertir(c);
    putchar(c);
}