#include <stdio.h>
#include <math.h>
float a;
int main() {
    printf("Introduzca una cantidad en radianes.");
    scanf("%f",&a);
    float b = a * 180.0 / acos(-1.0);
    printf("%.2f radianes es igual a %.2f grados.",a,b);
    return 0;
}