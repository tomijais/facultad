#include <stdio.h>

#include <stdlib.h>

typedef struct lista
{

    int num;

    struct lista *sig;

} nodo;

void crear(nodo *registro, int cont)

{
    printf("Ingrese un numero: (0 corta la ejecucion) \n");
    scanf("%d", &registro->num);

    if (registro->num == 0)
    {

        registro->sig = NULL;
    }
    else
    {

        registro->sig = (nodo *)malloc(sizeof(nodo));

        crear(registro->sig, cont + 1);
    }

    return;
}

void mostrar(nodo *registro, int cont)

{

    if (registro->sig != NULL)

    {

        printf("#%d %d\n",cont, registro->num);

        mostrar(registro->sig, cont+1);
    }

    return;
}

nodo *insertar1(nodo *p, int add)

{

    nodo *aux;

    if (p->sig != NULL && p->num>add)

    {

        aux = (nodo *)malloc(sizeof(nodo));

        aux->num = add; // valor a insertar

        aux->sig = p;

        p = aux;
    }

    return p;
}

void insertar2(nodo *p, int add)

{
    nodo *aux;

    while (p->sig != NULL)

    {

        if (p->num < add && p->sig->num > add)

        {

            aux = (nodo *)malloc(sizeof(nodo));

            aux->num = add; // valor a insertar

            aux->sig = p->sig;

            p->sig = aux;
        }

        p = p->sig;
    }
}


int main()

{

    nodo *prin = NULL;
    int i = 0;

    prin = (nodo *)malloc(sizeof(nodo));

    crear(prin, i);

    mostrar(prin, 0);


    int add;
    printf("Que valor desea ingresar? \n");
    scanf("%d", &add);

     prin = insertar1(prin, add);

    insertar2(prin, add);

    mostrar(prin, 0);

    return 0;
}
