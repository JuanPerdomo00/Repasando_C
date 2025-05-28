/*
 * Escribir un programa que permita la introduccion por teclado (mediante getchar)
 * de dos valores enteros de una cifra y que calcule e imprima por pantalla el producto
 * de ellos.
 * */

#include <stdio.h>

int main() {
    
    char a,b;
    int producto;

    printf("Ingresa un valor: ");
    a = getchar();
    //int a_real = a-48;
    int a_real = a - '0';
    // '0' --> 48
    /*
     * Se hace de esta forma debido a que los caracteres se representan en valor
     * posicional en la tabla de ASCII, lo cual getchar devuelve la posicion, 
     * la solucion es restar desde el cero, que su posicion es 48 segun la tabla ASCII.
     * */

    getchar();

    printf("Ingresa otro valor: ");
    b = getchar();
    //int b_real = b-48;
    // Otra forma seria usando el caracter '0', ya que en C lo toma como valor numerico
    // de la tabla ASCII
    int b_real = b-'0';

    producto = a_real * b_real;

    printf("El producto de %d x %d = %d\n", a_real, b_real, producto);


    return 0;
}
