#include <stdio.h>

#define PI 3.141592; // Constante simbolica o macro
#define suminv(a, b) 1/(a+b) // Funcion simbolica


int main() {
    int x; // variable entera
    char* loop = "Enfylop";
    printf("Hello, World. By: %s", "Jakepys");
    printf("Hello, World. By: %s", loop);
    float y;
    x = 5 + PI + 7;
    y = 10 - PI + suminv(x, y);
    return 0;
}

