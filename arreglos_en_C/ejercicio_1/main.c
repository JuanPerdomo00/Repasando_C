#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void procesar(char cadena[]) {

    char desp_cad[8], texto[201];
    int i = 0;

    // obtener el desplazamiento como cadena
    while (cadena[i] != ':' && cadena[i] != '\0') {
        desp_cad[i] = cadena[i];
        i++;
    }

    desp_cad[i] = '\0';

    if (cadena[i] != ':') {
        printf("Formato inválido. Usa <desp>:<texto>\n");
        return;
    }

    i++; // Saltar ':'
    int j = 0;

    // obtener el texto a cifrar
    while (cadena[i] != '\0') {
        texto[j] = cadena[i];
        i++;
        j++;
    }

    texto[j] = '\0';

    int desp = atoi(desp_cad); // conversión a número

    // proceso de cifrado
    j = 0;
    while (texto[j] != '\0') {
        // Mayúsculas
        if (texto[j] >= 'A' && texto[j] <= 'Z') {
            texto[j] = ((texto[j] - 'A' + desp) % 26) + 'A';
        }
        // Minúsculas
        else if (texto[j] >= 'a' && texto[j] <= 'z') {
            texto[j] = ((texto[j] - 'a' + desp) % 26) + 'a';
        }
        // Números
        else if (texto[j] >= '0' && texto[j] <= '9') {
            texto[j] = ((texto[j] - '0' + desp) % 10) + '0';
        }
        j++;
    }

    printf("%s\n", texto);
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

