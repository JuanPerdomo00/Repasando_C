#include <stdio.h>


int main() {
    int x = 2147483647; // Valor maximo para un entero (con signo)
    int y = x+10;
    printf("x: %d\n",x);
    printf("y: %d\n",y);
    return 0;
    /*
     * Lo que pasa es que hay desvordamiento, cada tipo de dato tiene una cantidad 
     * limitada de bits, en el caso del int que 32bits sobrepaso la cantidad, pero C 
     * no indica error, lo que hace es cortar esos 33bits y usar si o si 32bits.
     * */
}
