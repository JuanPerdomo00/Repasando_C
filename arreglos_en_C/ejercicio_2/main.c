#include <stdint.h>
#include <stdio.h>
#include <string.h>


int morseANumero(char cad[]) {
    if (strcmp(cad, ".----") == 0) return 1;
    if (strcmp(cad, "..---") == 0) return 2;
    if (strcmp(cad, "...--") == 0) return 3;
    if (strcmp(cad, "....-") == 0) return 4;
    if (strcmp(cad, ".....") == 0) return 5;
    if (strcmp(cad, "-....") == 0) return 6;
    if (strcmp(cad, "--...") == 0) return 7;
    if (strcmp(cad, "---..") == 0) return 8;
    if (strcmp(cad, "----.") == 0) return 9;
    if (strcmp(cad, "-----") == 0) return 0;

    printf("Error!");
}



int main() {
    const int tam=5;
    char linea[1001], codM[tam+1];
    int N, i, j, k, digito; // Nos dira la cantidad de pasos.
    
    scanf("%d", &N);
    getchar();   
    for (i = 0; i<N; i++) {
        fgets(linea,  sizeof(linea), stdin);
        //printf("%s\n", linea);
        
        j = 0;
        while(linea[j] != '\0') {
            for (k = 0; k < tam; k++) {
                codM[k] = linea[j];
                j++;
            }
            codM[tam] = '\0';
            digito = morseANumero(codM);
            printf("%d", digito);
            if (linea[j] == '\0') break;
            if(linea[j] == ' ' && linea[j + 1] == ' ' && linea[j + 2] == ' ') {
                printf(" ");
                j += 3;
            }
            else j++;

        }
        printf("\n");
    
    }

    return 0;
}
