#include <stdio.h>

int esBisiesto(int a) {
    return ((a%4==0 && a%100!=0)||a%400==0);
}


int cantidadMaxDiaMes(int m, int a) {
    if (m == 1 || m == 3 || m == 5 || m == 7 || m== 8 || m == 10 || m == 12) {
        return 31;
    }
    if (m==4 || m==6||m==9||m==11) {
        return 30;
    }

    if (m==2) {
        if (esBisiesto(a)) {
            return 29;
        } else {
            return 28;
        }
    }

    return -1;
}


int main() {
    
    int d,m,a;
    printf("Ingrese el dia: "); scanf("%d", &d);
    printf("Ingrese el mes: "); scanf("%d", &m);
    printf("Ingrese el anio: "); scanf("%d", &a);
    
    // verificar fecha
    if (a<0 || m<1 || m>12 || cantidadMaxDiaMes(m, a) < d || d<=0) {
        printf("La fecha es invalida :(\n");
        return -1;
    }

    // obtenemos fecha del siguiente dia.
    int cantidadDiasMes = cantidadMaxDiaMes(m, a);
    if (d == cantidadDiasMes) {
        if (m==12) { // estoy en el ultimo dia de un anio
            d=1; m=1;
            a++;
        }
        else {
            d=1;
            m++;
        }

    } else {
      d++;  
    }

    printf("La fecha del siguiente dia es: %d/%d/%d\n",d,m,a);

    return 0;

}
