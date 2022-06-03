#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct numeros
{
    int num;
    struct numeros *sig;
} nodoN;

void cargar(nodoN *p)
{
    printf("\nIngrese numero: ");
    scanf("%d", &p->num);
    if (p->num != 1000)
    {
        p->sig = (nodoN *)malloc(sizeof(nodoN));
        cargar(p->sig);
    }
}

void mostrar(nodoN *p)
{
    if (p->sig != NULL)
    {
        printf("\nNumero: %d", p->num);
        mostrar(p->sig);
    }
}

void obtener_multiplos(nodoN *p, nodoN *lista_multiplos, int multiplo){
    if(p->sig != NULL){
        if(p->num % multiplo == 0){
            lista_multiplos->num = p->num;
            lista_multiplos->sig = (nodoN *)malloc(sizeof(nodoN));
            lista_multiplos = lista_multiplos->sig;
        }
    obtener_multiplos(p->sig, lista_multiplos, multiplo);
    }
}

    int main()
{
    nodoN *p = NULL, *lista_multiplos = NULL;
    p = (nodoN *)malloc(sizeof(nodoN));
    lista_multiplos = (nodoN *)malloc(sizeof(nodoN));
    cargar(p);
    mostrar(p);
    obtener_multiplos(p, lista_multiplos, 3);
    printf("Multiplos de %d", 3);
    mostrar(lista_multiplos);

}