/*
La cadena de hoteles Hilton tiene establecimientos en todo el mundo. Para conocer las ganancias, se ingresa código de país, numero de establecimiento y su recaudación mensual (en millones de dólares) en una lista simplemente enlazada.

El ingreso de datos termina con el código de país igual a cero.
Se deben ingresar los datos ordenados por país y establecimiento.

-Mostrar la lista.
-Insertar un nodo al final de la lista con 100 en código de pais, 0 en numero de establecimiento y la recaudación de todos los hoteles ingresados.
-Eliminar de la lista original aquellos establecimientos con recaudación inferior al promedio de todos los establecimientos ingresados.
-Ingresar un nuevo hotel con el código de país y la recaudación mensual e Insertarlas en orden en la lista.
*/
// Online C compiler to run C program online


#include <stdio.h>
#include <stdlib.h>

typedef struct hoteles
{
    int codigo_pais;
    int numero_establecimiento;
    int recaudacion_mensual;
    struct hoteles *sig;
} nodoH;

void cargar(nodoH *h)
{
    printf("\nIngrese el codigo de pais: ");
    scanf("%d", &h->codigo_pais);
    if (h->codigo_pais == 0)
    {
        h->sig = NULL;
    }
    else
    {
        printf("Ingrese el numero del establecimiento: ");
        scanf("%d", &h->numero_establecimiento);

        printf("Ingrese la recaudacion mensual: ");
        scanf("%d", &h->recaudacion_mensual);

        h->sig = (nodoH *)malloc(sizeof(nodoH));
        cargar(h->sig);
    }
}

void mostrar(nodoH *h)
{
    if (h->sig != NULL)
    {
        printf("\n \nCodigo de pais del estableciento: %d", h->codigo_pais);
        printf("\nNumero del estableciento: %d", h->numero_establecimiento);
        printf("\nRecaudacion mensual del estableciento: %d\n", h->recaudacion_mensual);
        mostrar(h->sig);
    }
}

void insertarFinalLista(nodoH *h, int recaudacion_total)
{
    if (h->codigo_pais == 0)
    {
        h->codigo_pais = 100;
        h->numero_establecimiento = 0;
        h->recaudacion_mensual = recaudacion_total;
        h->sig = (nodoH *)malloc(sizeof(nodoH));
    }
    else
    {
        insertarFinalLista(h->sig, recaudacion_total + h->recaudacion_mensual);
    }
}

float promedio(nodoH *h, int indice, int recaudacion)
{
    if (h->sig->sig != NULL)
    {
        return promedio(h->sig, indice + 1, recaudacion + h->recaudacion_mensual);
    }
    else
    {
        return recaudacion / indice;
    }
}

int main()
{
    nodoH *p = NULL;
    float promedio_recaudacion;
    p = (nodoH *)malloc(sizeof(nodoH));
    cargar(p);
    mostrar(p);
    insertarFinalLista(p, 0);
    promedio_recaudacion = promedio(p, 0, 0);

    return 0;
}