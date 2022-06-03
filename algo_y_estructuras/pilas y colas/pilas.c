#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define CANT 4



typedef struct tiponodo
{
	int dato;

    struct tiponodo *siguiente;
}nodo;

void mostrar (nodo aux, int *cant_multiplos, int ultimo)

{
     	printf("%d \n", aux.dato);

         if(aux.dato % ultimo == 0 && aux.dato != ultimo){
             *cant_multiplos = *cant_multiplos + 1;
         }
}

nodo* crear_nodo(int dato )
{
   nodo* u;
   u = (nodo *)malloc(sizeof(nodo));
   u->dato = dato;

   u->siguiente = NULL;

   return u;
}

void apilar(nodo** p, nodo* u)
{
    printf("apilar_nodo\n");


  	u->siguiente = *p;
  	printf("%02d p=%p u=%p\n", u->dato, *p, u);
	*p = u;
}

nodo desapilar(nodo** p)
{
	nodo* aux;
    nodo datos;

	datos=**p;

	aux=*p;

	*p=(*p)->siguiente;
	free(aux);

    return datos;
}

int main()
{


   int i,num, *cant_multiplos = 0, ultimo;
   nodo* p=NULL;


   for(i=0; i<CANT; i++)
   {
   	printf("Ingrese un numero \n");
   	scanf("%d",&num);
   	apilar(&p, crear_nodo(num));
    if(i == 3){
        ultimo = num;
    }
   }
   


   printf("\nVamos a desapilar todo\n");
	while(p!=NULL)
   {
    	mostrar(desapilar(&p), &cant_multiplos, ultimo);
   }

   printf("El ultimo valor de la pila: %d", ultimo);
   printf("La cantidad de multiplos del ultimo valor de la pila: %d", cant_multiplos);


  // getch();
   return 0;
}
