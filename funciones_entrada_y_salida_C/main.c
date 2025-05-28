#include <stdio.h>


int main() {
    
    /*
     * Funciones de entrada/salida en C
     * printf ----> impresion de datos en pantalla
     * scanf  ----> captura de datos por teclado
     * getchar ----> lee un caracter 
     *
     * Estas funciones estan en conio.h
     * getch --> no muestra el caracter 
     * getche ---> si lo muestra
     *
     * - 
     * */

    int a,b,s;
    
    char c1,c2;
    printf("Ingrese un caracter: ");
    c1 = getchar();
    getchar(); // Este se lleva en enter, ya que es otro caracter.
    printf("Ingrese otro caracter: ");
    c2 = getchar();



    printf("Los caracteres que ingreso fueron: '%c', '%c'\n", c1, c2);

    // a = 5; b = 4; s = a+b;
    
    printf("Ingrese el primer valor: ");
    scanf("%d", &a);

    printf("Ingrese el segundo valor: ");
    scanf("%d", &b);
        
    s = a + b;

    printf("El valor de a es: %d\n", a);
    printf("El valor de b es: %d\n", b);
    //printf("El valor de s es: %d\n", s);


    printf("El valor de a: %d + b: %d es: %d\n", a,b, s);

    /*
     * Formatos para impresion de datos
     * int --> %d
     * char --> %c
     * float --> %f
     * double --? %lf
     *
     * Para mostrar la cantidad de decimales vasta con poter %.nf siendo n 
     * la cantidad de decimales.
     * */

    //char x = 'm';
    //printf("El caracter es: %c\n", x);
    
    //float h = 1.12345678;
    //printf("El valor de h es: %.2f\n", h);
    

    return 0;
}
