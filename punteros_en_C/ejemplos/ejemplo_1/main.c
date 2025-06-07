#include <stdio.h>

/*Escribir una funcion que reciba un numero entero y lo triplique*/


int triplicarV1(int x) {
    return 3*x;
} 


void triplicarV2(int *x){
    x--;
    *x += 1;
    *x *= 3;
}



int main() {
    int a;
    printf("Ingresa un numero: ");
    scanf("%d", &a);
    //a = triplicarV1(a);
    triplicarV2(&a);
    printf("\nEl resultado es: %d\n",a);
    return 0;



}
