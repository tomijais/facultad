#include <stdio.h>
#include <stdlib.h>

typedef struct numeros {
    int num;
    struct numeros *sig;
} nodoN;

void cargar(nodoN *k){
    printf("Ingrese un numero: ");
    scanf("%d", &k->num);
    if(k->num == 0){
        k->sig = NULL;
    }else {
        k->sig= (nodoN *) malloc(sizeof(nodoN));
        cargar(k->sig);
    }
}

void mostrar(nodoN *k){
    if(k->sig != NULL){
        printf("\nEl numero es: %d", k->num);
        mostrar(k->sig);
    }
}

void recorrer(nodoN *k, int contador){
    
}

int main(){
    int contador = 0;
    nodoN *p=NULL;
    p = (nodoN *) malloc(sizeof(nodoN));
    cargar(p);
    mostrar(p);
    recorrer(p, &contador);
    return 0;
}