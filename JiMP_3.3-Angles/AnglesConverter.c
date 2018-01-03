//Zastosowano flagi:  -Wall -pedantic -Wextra -Werror -std=c99

#include <stdio.h>
#include <math.h>

#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

void wybor(void);
void convertFromPitchToRadian(double);
void convertFromRadianToPitch(double);

int main(void){

    wybor();

    return 0;
}

void wybor(){
    double angle = 0;
    int n = 0;
    printf("Wybierz jednostke: (1-stopnie, 2-radiany): ");
    scanf("%d", &n);
    switch (n)
    {
        case 1:
            printf("Podaj wielkosc kata w wybranej jednostce: ");
            scanf("%lf", &angle);
            convertFromPitchToRadian(angle);
            break;
        case 2:
            printf("Podaj wielkosc kata w wybranej jednostce: ");
            scanf("%lf", &angle);
            convertFromRadianToPitch(angle);
            break;
        default:
            printf("Bledna wartosc!\n");
            wybor();
            break;
    }
}

void convertFromPitchToRadian(double angle){
    double converted_angle = angle /180*M_PI;
    printf("Kat o miarze %.2f stopni ma miare %.2f radianow = %.2f Pi", angle, converted_angle, converted_angle/M_PI);
}

void convertFromRadianToPitch(double angle){
    double converted_angle = angle *180/M_PI;
    printf("Kat o miarze %.2f radianow ma miare %.2f stopni", angle, converted_angle);
}
