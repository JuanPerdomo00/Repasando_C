#include <stdio.h>
#include <stdlib.h>

void make_string_cal(char* str, int mes, int anho) {
    sprintf(str, "cal %d %d", mes, anho);
    system(str);
}

int main() {
    char cad[100];
    int mes, anho;
    printf("Calendario by: Jakepys\n");
    printf("Ingresa el mes: ");
    scanf("%d", &mes);
    printf("\nIngrea el anho: ");
    scanf("%d", &anho);
    printf("\n");

    make_string_cal(cad, mes, anho);
    printf("\n%s Se guardo en el puntero?\n", cad);
    return 0;
}
