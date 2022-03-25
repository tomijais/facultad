#include <stdio.h>

int producto(int a, int b)
{
    if(a == 0 | b == 0)
        return 0;
    
    return producto(a, b - 1) + a;
}

int potencia(int a, int b)
{
    if(b == 0)
        return 1;
    
    return producto(a, b - 1) * a;
}

int factorial(long num){
    if(num == 0){
        return 1;
    }
    return factorial(num - 1) * num;
}


int division(int a, int b){
    if(a == 0 || b == 0 || a < b)
        return 0;
    
    return division(a - b, b) + 1;
}

int main()
{
    int a, b;
    printf("Ingrese un valor: ");
    scanf("%d", &a);
    printf("Ingrese otro valor: ");
    scanf("%d", &b);
    printf("\nEl producto de los valores es: %d", producto(a, b));
    printf("\nLa potencia de los valores es: %d", potencia(a, b));
    printf("\nEl factorial de a es: %d", factorial(a));
    printf("\n La division de los valores es de: %d", division(a, b));
}