#include<stdio.h>

int main() {
    char a; printf("char: %d\n", sizeof(char));
    int b; printf("int: %d\n", sizeof(int));
    long c; printf("long: %d\n", sizeof(long));
    float d; printf("float: %d\n", sizeof(float));
    double e; printf("double: %d\n", sizeof(double));
    long long f; printf("long long: %d\n", sizeof(long long));
    int g[5]; printf("int g[5]: %d\n", sizeof(g));
    return 0;

}
