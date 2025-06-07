#include <stdio.h>

void intercambiar_v1(int* x, int* y) {

    int aux = *x;
    *x=*y;
    *y = aux;
}



int main() {
    int a=3, b=7;
    printf("Inicialmente a=%d y b=%d\n", a,b);
    intercambiar_v1(&a, &b);
    printf("\nAl intercambiar: a=%d y b=%d\n", a,b);
}
