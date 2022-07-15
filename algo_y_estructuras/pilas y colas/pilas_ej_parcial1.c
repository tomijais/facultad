/*Para los siguientes ejercicios crear una pila con la siguiente información:
 A: entero.
 SIG: puntero al próximo elemento de la pila.
y calcular:
1) La cantidad de números múltiplos de 3.
2) El promedio de aquellos números divisores de 4.
3) La sumatoria de aquellos números múltiplos del primer elemento ingresado a la pila.
4) El número máximo y su posición en la pila.
5) El número mínimo y su posición en la pila.
6) Ingresar un numero por teclado y calcular la cantidad de veces que está en la pila.
Si no está, mostrar una leyenda.*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define CANT 4



typedef struct tiponodo
{
	int dato;

    struct tiponodo *siguiente;
}nodo;

void mostrar (nodo aux, int *mult_3, int *mult_4, int *cant_div4, int primer_num, int *sumatoria_multiplos_primero, int numero_a_verificar, int *cant_verificar)

{
    
    
    if(aux.dato % 3 == 0){
        *mult_3 += 1;
    }
    
    if(4 % aux.dato == 0){
        *mult_4 += aux.dato;
        *cant_div4 += 1;
    }
    
    if(aux.dato % primer_num == 0 && aux.dato != primer_num){
        *sumatoria_multiplos_primero += aux.dato;
    }
    
    if(numero_a_verificar == aux.dato){
        *cant_verificar += 1;
    }
    
     	printf("%d \n", aux.dato);
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
  	printf("%02d p=%X u=%X\n", u->dato, *p, u);
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


   int i,num, mult_3 = 0, mult_4 = 0, cant_div4 = 0, primer_num, sumatoria_multiplos_primero = 0;
   nodo* p=NULL;
   
    int max, posmax = 0, min, posmin = 0;

   for(i=0; i<CANT; i++)
   {
   	printf("Ingrese un numero \n");
   	scanf("%d",&num);
   	if(i == 0){
   	    primer_num = num;
   	    max = min = num;
   	}
   	
   	if(num > max){
   	    max = num;
   	    posmax = i;
   	}
   	
   	if(num < min){
   	    min = num;
   	    posmin = i;
   	}
   	
   	
   	apilar(&p, crear_nodo(num));
   }
   
   int numero_a_verificar, cant_verificar = 0;
   
    printf("Ingrese el numero que desea verificar si esta en la pila \n");
   	scanf("%d",&numero_a_verificar);


   printf("\nVamos a desapilar todo\n");
	while(p!=NULL)
   {
    	mostrar(desapilar(&p), &mult_3, &mult_4, &cant_div4, primer_num, &sumatoria_multiplos_primero, numero_a_verificar, &cant_verificar);
   }
   
   if(mult_3 > 0){
        printf("\nMultiplos de 3: %d \n", mult_3);
   }else{
       printf("No se ingresaron multiplos de 3\n");
   }
   
    if(mult_4 > 0){
        printf("\nPromedio de los divisores de 4: %.2f \n", (float)mult_4 / (float)cant_div4);
   }else{
       printf("No se ingresaron multiplos de 4\n");
   }
   
   if(sumatoria_multiplos_primero > 0){
        printf("\nSumatoria de los multiplos de %d: %d \n", primer_num, sumatoria_multiplos_primero);
   }else{
        printf("No se ingresaron multiplos de %d: \n", primer_num);
   }
   
   printf("El numero mas grande es: %d y la posicion respectiva al ingreso es: %d\n", max, posmax);
   printf("El numero mas chico es: %d y la posicion  respectiva al ingreso es: %d\n", min, posmin);
   
   if(cant_verificar > 0){
       printf("El numero solicitado a verificar(%d) está %d veces", numero_a_verificar, cant_verificar);
   }

   return 0;
}
