#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct empleados
{
    char nombre[30];
    int edad;
    float sueldo;
    struct empleados *sig;
} nodoE;

void cargar(nodoE *h)
{
    printf("Ingrese nombre:");
    scanf("%s", h->nombre);
    if (strcmp(h->nombre, "x") == 0)
    {
        h->sig = NULL;
    }
    else
    {
        printf("Ingrese edad:");
        scanf("%d", &h->edad);

        printf("Ingrese sueldo:");
        scanf("%f", &h->sueldo);
        h->sig = (nodoE *)malloc(sizeof(nodoE));
        cargar(h->sig);
    }
}

void mostrar(nodoE *h)
{
    if (h->sig != NULL)
    {
        printf("\n%s", h->nombre);
        printf("\n%d", h->edad);
        printf("\n%.2f", h->sueldo);
        mostrar(h->sig);
    }
}

int main()
{
    nodoE *p = NULL;
    p = (nodoE *)malloc(sizeof(nodoE));
    cargar(p);
    mostrar(p);
}