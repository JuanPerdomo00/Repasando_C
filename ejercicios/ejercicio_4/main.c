/*
 * Leer un numero de 5 cifras e imprimir el digito de las centenas
 * */


#include <stdio.h>

// abcde/100 ---> abc 
// abc % 10 ---> c

int main() {
     
    int n;

    printf("Ingrese un numero de 5 cifras: ");
    scanf("%d", &n);


    int n1 = n/100; // abc
    int n2 = n1%10; //c 
    
    printf("La digito de la centena es: %d\n", n2);

    return 0;
}
