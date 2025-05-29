/*
 * Escribir un programa que lea una letra en minuscula y que la muestre en 
 * mayuscula en pantala.
 * */

#include <stdio.h>


int main() {
    char letra;

    printf("Ingresa una letra minuscula: ");
    scanf("%c", &letra);

    /*
     * A --> 65 B --> 66 ...
     * a --> 97 (a-z) b --> 98 ...
     * 
     * Ejemplo input: b
     * 
     * b tiene en la tabla ACSII el valor de 98
     * Si le restamos 'a' cuyo valor en la tabla es de 97
     * seria 98 - 97 dando como resultado 1, y a este resultado
     * se le sumara la posicion de la 'A' en la tabla que seria el numero
     * 65, entonce 1 + 65 = 66. 
     *
     * Dando como resultado la posicion de la letra ingresada a mayuscula.
     * osea 'B' --> 66
     * */

    char mayuscula = letra - 'a' + 'A';

    printf("La letra que ingreso %c se convirtio mayus: %c\n", letra, mayuscula);

}
