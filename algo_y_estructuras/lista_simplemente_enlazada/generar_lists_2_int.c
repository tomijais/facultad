#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct numeros
{
    int a;
    int b;
    struct numeros *sig;
} nodoN;

typedef struct promedio
{
    float prom;
    struct promedio *sig;
} nodoP;

void cargar(nodoN *h)
{
    printf("Ingrese a: ");
    scanf("%d", &h->a);
    if (h->a == 0)
    {
        h->sig = NULL;
    }
    else
    {
        printf("Ingrese b:");
        scanf("%d", &h->b);

        h->sig = (nodoN *)malloc(sizeof(nodoN));
        cargar(h->sig);
    }
}

void mostrar(nodoN *h)
{
    if (h->sig != NULL)
    {
        printf("\n%d", h->a);
        printf("\t%d", h->b);
        mostrar(h->sig);
    }
}

void cargar2(nodoN *h, nodoP *m)
{
    if (h->sig != NULL)
    {
        m->prom = (h->a + h->b) / 2;

        m->sig = (nodoP *)malloc(sizeof(nodoP));
        cargar2(h->sig, m->sig);
    }
}

void mostrar2(nodoP *h)
{
    if (h->sig != NULL)
    {
        printf("\n%f", h->prom);
        mostrar2(h->sig);
    }
}

int cantidad_nodos_multiplos(nodoN *h)
{

    if (h->sig == NULL)
        return 0;

    if (h->a % h->b == 0)
    {
        return cantidad_nodos_multiplos(h->sig) + 1;
    }

    return cantidad_nodos_multiplos(h->sig);
}

int obtener_largo_nodos_mayor_20(nodoN *h)
{
    if (h->sig == NULL)
        return 0;

    if (h->b + h->a > 20)
        return cantidad_nodos_multiplos(h->sig) + 1;
    return cantidad_nodos_multiplos(h->sig);
}

void generar_arr_mayor_20(nodoN *h)
{
    int arr[obtener_largo_nodos_mayor_20(h) * 2], i = 0;

    while (h->sig != NULL)
    {
        if (h->b + h->a > 20)
        {
            arr[i] = h->a;
            arr[i + 1] = h->b;
            i = i + 2;

            printf("\n%s", "Array de numeros cuya suma es mayor a 20: ");
            printf("\n%d", h->a);
            printf("\t%d", h->b);
        }
        h = h->sig;
    }
}

void generar_lista_mayor_20(nodoN *h, nodoN *m)
{
    if (h->sig == NULL)
    {
        m->sig = NULL;
        return;
    }

    if (h->a + h->b > 20)
    {
        m->a = h->a;
        m->b = h->b;
        m->sig = (nodoN *)malloc(sizeof(nodoN));
        generar_lista_mayor_20(h->sig, m->sig);
    }
    else
    {
        generar_lista_mayor_20(h->sig, m);
    }
}

int main()
{

    nodoN *p = NULL, *q = NULL;
    nodoP *r = NULL;
    p = (nodoN *)malloc(sizeof(nodoN));
    q = (nodoN *)malloc(sizeof(nodoN));
    r = (nodoP *)malloc(sizeof(nodoP));
    cargar(p);
    mostrar(p);
    printf("\nLa cantidad de nodos donde el primero numero es multiplo del segundo es: %d", cantidad_nodos_multiplos(p));
    // generar_arr_mayor_20(p);
    generar_lista_mayor_20(p, q);
    if (obtener_largo_nodos_mayor_20(q))
    {

        printf("\nLa lista donde los 2 numeros suman 20 es: %d", cantidad_nodos_multiplos(p));
        mostrar(q);
    }

    cargar2(p, r);
    printf("\nLa lista de los promedios es: ");
    mostrar2(r);
}