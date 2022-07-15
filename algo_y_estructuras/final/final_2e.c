#include <stdio.h>

#include <stdlib.h>

    typedef struct arbol

{

    int dato;

    struct arbol *izq;

    struct arbol *der;

} treenode;

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



void crear(treenode **hoja, int *raiz)

{

    int numero;

    printf("ingrese numero\n");

    scanf("%d", &numero);
    *raiz = numero;

    while (numero != -1)

    {

        insertar(&(*hoja), numero);

        printf("ingrese numero\n");

        scanf("%d", &numero);
    }
}

void mostrar(treenode *hoja, int *acc_mayores, int *cant_mayores, int raiz)

{

    if (hoja != NULL)

    {

        if(hoja->izq == NULL && hoja->der == NULL){ // Es hoja
            if(raiz < hoja->dato){
                *acc_mayores += hoja->dato;
                *cant_mayores += 1;
            }
        }

        mostrar(hoja->izq, acc_mayores, cant_mayores, raiz);

        printf("%d ", hoja->dato);

        mostrar(hoja->der,  acc_mayores, cant_mayores, raiz);
    }

    return;
}


int main()

{

    int acc_mayores = 0, cant_mayores = 0, raiz;

    printf("arboles\n");

    treenode *arbol = NULL;

    crear(&arbol, &raiz);

    printf("**************\n");

    printf("mostrar arbol\n");

    printf("***************\n");

    mostrar(arbol, &acc_mayores, &cant_mayores, raiz);


    if(cant_mayores > 0){
        printf("El promedio de numeros mayores a la raiz es: %d", acc_mayores/cant_mayores);
    }

    return 0;
}

