#include <stdio.h>

int main() {
    int N = getchar() - '0'; // Lee el número de líneas
    getchar(); // Lee el salto de línea después del número

    int i, j, k, num, x;
    for (i = 0; i < N; i++) {
        for (j = 0; j < 4; j++) {
            num = 0;
            for (k = 0; k < 8; k++) {
                x = getchar() - '0';
                num = num * 2 + x; // Correcta conversión binaria
            }
            printf("%d", num);
            if (j == 3) {
                printf("\n"); // Final de IP
            } else {
                printf("."); // Separador entre octetos
            }
        }
        getchar(); // Lee y descarta el salto de línea
    }

    return 0;
}

