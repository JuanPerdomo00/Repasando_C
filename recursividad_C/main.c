/*
 * Escribir un programa que muestre el maximo
 * comun divisor (MCD) de dos numeros A y B
 * (Usando el algoritmo de Euclides)
 *
 * */

#include <stdio.h>


int MCD_Rec(int a, int b) {
    int r = a % b;
    if (r == 0) return b;
    else MCD_Rec(b, r);

}


int main() {

    int a,b;

    printf("Ingrese el primer numero entero: ");
    scanf("%d", &a);

    printf("Ingrese el segundo numero entero: ");
    scanf("%d", &b);
    

    printf("\nEl MCD es: %d\n", MCD_Rec(a,b));


    return 0;
}
