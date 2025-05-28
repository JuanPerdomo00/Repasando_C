/*
 * Calcular la suma y el promedio de 5 valores introducidos por teclado.
 * */

#include <stdio.h>


int main() {
    
    int a,b,c,d,e;

    printf("Ingresa un numero: "); scanf("%d", &a);
    printf("Ingresa un numero: "); scanf("%d", &b);
    printf("Ingresa un numero: "); scanf("%d", &c);
    printf("Ingresa un numero: "); scanf("%d", &d);
    printf("Ingresa un numero: "); scanf("%d", &e);

    int suma = a+b+c+d+e;
    float promedio = (float) suma/5;

    printf("La suma es: %d\n", suma);
    printf("El promedio es: %.2f\n",promedio);

    return 0;
}
