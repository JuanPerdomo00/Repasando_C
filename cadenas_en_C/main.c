/*
 * Escribir una funcion que reciba una cadena y la convierta en mayuscula.
 * */

#include <stdio.h>


/*
 * "Jakepys hackers" ---> '\0' --> al final
 *  
 *  a ---> 97     A ---> 65
 *  b ---> 98     B ---> 66
 *  c ---> 99     C ---> 67
 * ...
 * z
 * */



void convertirMayus(char cadena[]) {
    int i=0;

    while (cadena[i] != '\0') { // Aun no llegamos al final de la cadena.
        if (cadena[i] >= 'a' && cadena[i] <= 'z') {
            cadena[i] -= ('a' - 'A');
        }
        i++;
    }

}


int main() {
    char cadena[100];
    printf("Ingresa la cadena: ");
    //scanf("%s", cadena); en las cadenas no se pasa la direccion.
    // El scanf solo tomas cadenas hasta que encuentre un espacio, tab, o enter.
    
    fgets(cadena, sizeof(cadena), stdin);
        
    convertirMayus(cadena);
    printf("\nLa cadena es: %s\n", cadena);
    


    return 0;
}
