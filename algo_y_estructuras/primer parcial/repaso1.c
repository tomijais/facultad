/*
Se ingresan los siguientes datos de los empleados de una empresa:
Nro de legajo, nombre y apellido, años de antiguedad en la empresa y sueldo. Generar una lista simplemente enlazada 
con estos datos. La carga termina con el nro de legajo igual a cero. Mostrar la lista.
a) Generar una nueva lista con aquellos empleados que tienen mas de 10 años en la empresa e incrementar el sueldo en un 15%.
Mostrar la lista.
b) Generar una nueva lista con los sueldos de cada empleado y al final insertar el monto total que la empresa debe pagar en sueldos.
c) Eliminar de la lista original a aquellos empleados que tienen menos de 4 años de antigüedad generando con ellos una lista nueva
d) Insertar antes de cada nodo de aquellos empleados que tienen más de 30 años de antiguedad en la lista  original un nodo incrementando el 30%de sueldo.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct empleado
{
    int legajo;
    char nomYape[30];
    int antiguedad;
    float sueldo;
    struct empleado *sig;
} nodoE;

void cargar(nodoE *h)
{
    printf("\nIngresar numero de legajo: ");
    scanf("%d", &h->legajo);
    if (h->legajo == 0)
    {
        h->sig = NULL;
    }
    else
    {
        printf("\nIngresar el nombre y apellido: ");
        scanf("%s", h->nomYape);

        printf("\nIngresar la antiguedad: ");
        scanf("%d", &h->antiguedad);

        printf("\nIngresar el sueldo: ");
        scanf("%f", &h->sueldo);

        h->sig = (nodoE *)malloc(sizeof(nodoE));
        cargar(h->sig);
    }
}

void mostrar(nodoE *h)
{
    if (h->sig != NULL)
    {
        printf("\n Numero de legajo: %d", h->legajo);
        printf("\n Nombre y Apellido: %s", h->nomYape);
        printf("\n Antiguedad: %d", h->antiguedad);
        printf("\n Sueldo: %f\n", h->sueldo);
        mostrar(h->sig);
    }
}

void nuevaLista(nodoE *h, nodoE *n)
{
    if (h->sig != NULL)
    {

        if (h->antiguedad >= 10)
        {
            n->legajo = h->legajo;
            strcpy(n->nomYape, h->nomYape);
            n->antiguedad = h->antiguedad;
            n->sueldo = (float)h->sueldo * 1.15;
            n->sig = (nodoE *)malloc(sizeof(nodoE));
            n = n->sig;
        }
        nuevaLista(h->sig, n);
    }
}

void listaSueldos(nodoE *h, nodoE *n, int monto_total)
{
    if (h->sig == NULL)
    {
        n->sueldo = monto_total;
        n->sig = (nodoE *)malloc(sizeof(nodoE));
    }

    if (h->sig != NULL)
    {
        n->sueldo = h->sueldo;
        n->sig = (nodoE *)malloc(sizeof(nodoE));
        listaSueldos(h->sig, n->sig, monto_total + h->sueldo);
    }
}

void eliminarPocaAntiguedad(nodoE *h, nodoE *poca_antiguedad)
{
    nodoE *aux = NULL;
    if (h->sig != NULL)
    {
        if (h->antiguedad < 4)
        {
            poca_antiguedad->legajo = h->legajo;
            strcpy(poca_antiguedad->nomYape, h->nomYape);
            poca_antiguedad->antiguedad = h->antiguedad;
            poca_antiguedad->sueldo = h->sueldo;
            poca_antiguedad->sig = (nodoE *)malloc(sizeof(nodoE));
            aux = h->sig;
            free(h);
            h = aux;
            eliminarPocaAntiguedad(h, poca_antiguedad->sig);
        }
    }
}

int main()
{
    nodoE *p = NULL, *nueva = NULL, *lista_sueldos = NULL, *poca_antiguedad = NULL;
    p = (nodoE *)malloc(sizeof(nodoE));
    nueva = (nodoE *)malloc(sizeof(nodoE));
    lista_sueldos = (nodoE *)malloc(sizeof(nodoE));
    poca_antiguedad = (nodoE *)malloc(sizeof(nodoE));
    cargar(p);
    printf("\nDatos ingresados\n");
    mostrar(p);
    nuevaLista(p, nueva);
    printf("\nLista con sueldos mejorados\n");
    mostrar(nueva);
    listaSueldos(p, lista_sueldos, 0);
    printf("\nSueldos globales y totales\n");
    mostrar(lista_sueldos);
    eliminarPocaAntiguedad(p, poca_antiguedad);
    printf("\nNueva lista con los que tienen mas antiguedad\n");
    mostrar(p);
    printf("\nNueva lista con los que tienen menos antiguedad\n");
    mostrar(poca_antiguedad);

    return 0;
}