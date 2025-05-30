#include <stdint.h>
#include <stdio.h>
#include <string.h>



void procesar(char cadena[]) {

    char desp_cad[8], texto[201];
    int i = 0;

    while (cadena[i] != ':') {
        desp_cad[i] = cadena[i];
        i++;
    }

    desp_cad[i] = '\0';

    i++; // POrque aqui esta el ':'
    int j = 0;
    while (cadena[i] != '\0') {
        texto[j] = cadena[i];
        i++;j++;
    }

    printf("%s\t%s\n", desp_cad, texto);

}

int main() {   
    char linea[209];
    fgets(linea, sizeof(linea), stdin);
    int pos = strcspn(linea, "\n");
    linea[pos] = '\0';

    while (strcmp(linea, "#") != 0) {
        procesar(linea);
        fgets(linea, sizeof(linea), stdin);
        pos = strcspn(linea, "\n");
        linea[pos] = '\0';
    }

    return 0;
}
