#include <stdio.h>

int main()
{
    int a = 5, b = 10;

    printf("El valor de a es: %d\n", a);
    printf("La direccion de memoria de la variable a es: %p\n", &a);

    int *p;
    p = &a; // p apunta a la direccion de a

    printf("El valor de p: %p\n", p);

    // Si en una una exprecion aparece *p, este lo tomara como el valor al que apunta.
    *p = 10; 
    printf("El valor de a es: %d\n", a);
    
    printf("La direccion de la variable b es %p\n", &b);
    p = &b; 
    *p = *p + a;

    int *q = &a;
    printf("El valor de b es %d\n", b);
    printf("La suma de a + b es: %d\n", *p+*q);

    return 0;
}
