#include <stdio.h>
#include <stdlib.h>

typedef struct arbol
{
    int dato;
    struct arbol *izq;
    struct arbol *der;
} treenode;

void crear(treenode **hoja);
void insertar(treenode **hoja, int elem);
void mostrar(treenode *hoja, int *, int *);

int main()
{

    int *min = NULL;
    int *max = NULL;

    min = (int *)malloc(sizeof(int));
    max = (int *)malloc(sizeof(int));

    *min = 32000;
    *max = -32000;

    printf("arboles\n");
    treenode *arbol = NULL;

    crear(&arbol);
    printf("**************\n");
    printf("mostrar arbol\n");
    printf("***************\n");

    mostrar(arbol, min, max);

    printf("\n El menor valor es: %d", *min);
    printf("\n El mayor valor es: %d", *max);

    return 0;
}
void crear(treenode **hoja)
{
    int numero;

    printf("ingrese numero\n");
    scanf("%d", &numero);
    while (numero != -1)
    {

        insertar(&(*hoja), numero);
        printf("ingrese numero\n");
        scanf("%d", &numero);
    }
}

void insertar(treenode **hoja, int elem)
{
    int numero = elem;
    if (elem == -1)
        return;
    if (*hoja == NULL)
    {
        // creo la hoja vacia
        (*hoja) = (treenode *)malloc(sizeof(treenode));
        (*hoja)->dato = elem;
        (*hoja)->der = NULL;
        (*hoja)->izq = NULL;
    }
    else
    {

        if (numero > (*hoja)->dato)
        {

            insertar(&(*hoja)->der, elem);
        }
        else
        {

            insertar(&(*hoja)->izq, elem);
        }
    }
    return;
}

void mostrar(treenode *hoja, int *min, int *max)
{
    if (hoja != NULL)
    {
        if (hoja->dato > *max)
        {
            *max = hoja->dato;
        }

        if (hoja->dato < *min)
        {
            *min = hoja->dato;
        }

        mostrar(hoja->izq, min, max);
        printf("%d ", hoja->dato);
        mostrar(hoja->der, min, max);
    }
    return;
}
