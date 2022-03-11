#include <stdio.h>

int main(){
    int primo = 0, acum = 0, cont = 0, num;
    float promedio;

    printf("Ingrese un numero: ");
    scanf("%d", &num);

    while(num > 0){
        for(int i = 2; i < num; i++){
            if(num % i == 0){
                cont++;
            }
        }

        if(cont == 0){
            acum += num;
            primo++;
        }

        cont = 0;
        printf("Ingrese un numero: ");
        scanf("%d", &num);
    }

    if(primo != 0){
        printf("El promedio es %d", acum/primo);
    }else{
        return printf("No se puede calcular el promedio");
    }
}