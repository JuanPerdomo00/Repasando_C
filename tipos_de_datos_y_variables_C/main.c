
#include <stdio.h>


int main() {
    int x; // No se asigno ningun valor
    /*
     * Por defecto C no limpia la region de memoria, por ende habra bytes en ella,
     * en el caso de x tendra data o bytes que estan ahi ya sea por otro programa
     * o proceso.
     *
     * Para arreglar eso, se debe declarar y inicializar la variable x.
     * */

    x = 26;
    printf("%d", x);
    return 0;
}
