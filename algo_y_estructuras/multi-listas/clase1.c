#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct alumnos
{
    char nomyape[30];
    struct materias *materias;
    struct alumnos *sig;
} nodoA;

typedef struct materias
{
    char nombre[20];
    char profesor[30];
    struct materias *sig;
} nodoM;

void crearListaMaterias(nodoM *h)
{
    printf("\n Ingrese el nombre de la materia: ");
    scanf("%s", h->nombre);
    if (strcmp(h->nombre, "X") == 0)
    {
        h->sig = NULL;
    }
    else
    {
        printf("\n Ingrese el nombre del profesor: ");
        scanf("%s", h->profesor);
        h->sig = (nodoM *)malloc(sizeof(nodoM));
        crearListaMaterias(h->sig);
    }
}

void mostrarListaMaterias(nodoM *h)
{
    if (h->sig != NULL)
    {
        printf("\n\t Nombre de la materia: %s", h->nombre);
        printf("\n\t Nombre del profesor: %s", h->profesor);
        mostrarListaMaterias(h->sig);
    }
}
void crearListaAlumnos(nodoA *h)
{
    printf("\n Ingrese el nombre y el apellido del alumno: ");
    scanf("%s", h->nomyape);
    if (strcmp(h->nomyape, "X") == 0)
    {
        h->sig = NULL;
    }
    else
    {
        h->materias = (nodoM *)malloc(sizeof(nodoM));
        crearListaMaterias(h->materias);
        h->sig = (nodoA *)malloc(sizeof(nodoA));
        crearListaAlumnos(h->sig);
    }
}
void mostrarListaAlumnos(nodoA *h)
{
    if (h->sig != NULL)
    {
        printf("\n Nombre del alumno: %s", h->nomyape);
        mostrarListaMaterias(h->materias);
        mostrarListaAlumnos(h->sig);
    }
}

int main()
{
    nodoA *p = NULL;
    p = (nodoA *)malloc(sizeof(nodoA));

    crearListaAlumnos(p);
    mostrarListaAlumnos(p);
}