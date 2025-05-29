/*
 * Dado un numero n, imprimir en pantalla sus factores primos de la siguiente manera:
 *
 *  150 = 2^1 * 3^1 * 5^1
 *
 *  Nota: es un ejemplo, considerando una entrada n = 150
 *
 *  300 | 2
 *  150 | 2
 *   75 | 3
 *   25 | 5
 *    5 | 5
 *    1 |
 * */


#include <stdio.h>


int main() {
    int n;
    printf("Ingresa un numero: ");
    scanf("%d", &n);

    int exp = 0;
    int i = 2;

    printf("%d = ", n);

    while (n>1) {
        while (n%i == 0) { // mientras i sea divisor de n
            exp++;
            n /= i;
        }
        if (exp > 0) {
            if(n!=1) printf("%d^%d *", i, exp);
            else printf("%d^%d\n", i, exp);
        }
        exp = 0;
        i++;
    }


    return 0;
    
}
