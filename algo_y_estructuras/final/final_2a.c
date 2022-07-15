#include <stdio.h>
#include <stdlib.h>

typedef struct tiponodo

{
    int dato;

    struct tiponodo *siguiente;

} nodo;

void mostrar(nodo aux, int *max, int *min)

{
    if(aux.dato < *min){
        *min = aux.dato;

    }
    if (aux.dato > *max )
    {
        *max = aux.dato;
    }
    

    printf("%d \n", aux.dato);
}

nodo *crear_nodo(int dato)

{

    nodo *u;

    u = (nodo *)malloc(sizeof(nodo));

    u->dato = dato;

    u->siguiente = NULL;

    return u;
}

void apilar(nodo **p, nodo *u)

{

    printf("apilar_nodo\n");

    u->siguiente = *p;

    *p = u;
}

nodo desapilar(nodo **p)

{

    nodo *aux;

    nodo datos;

    datos = **p;

    aux = *p;

    *p = (*p)->siguiente;

    free(aux);

    return datos;
}

int main()

{

    int i, num, max = -32000, min = 32000;

    nodo *p = NULL;

    for (i = 0; i < 10; i++)

    {

        printf("Ingrese un numero \n");

        scanf("%d", &num);

        apilar(&p, crear_nodo(num));
    }

    printf("\nVamos a desapilar todo\n");

    while (p != NULL)

    {

        mostrar(desapilar(&p), &max, &min);
    }


    printf("El maximo numero es: %d", max);
    printf("El minimo numero es: %d", min);

    return 0;
}