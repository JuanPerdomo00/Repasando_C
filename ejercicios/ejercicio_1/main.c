/*
 * Luego de ingresar el radio por teclado, hallar la circunferencia
 * y el area de un circulo.
 * */

#include <stdio.h>

#define PI 3.141592 // constante

int main() {
    float radio, area, circunferencia;
    printf("ingresa el radio: ");
    scanf("%f", &radio);
    
    area = PI * radio * radio;
    circunferencia = 2 * PI * radio;

    printf("El area del circulo es: %.3f\n", area);
    printf("La circunferencia del circulo es: %.3f\n", circunferencia);

    return 0;
}
