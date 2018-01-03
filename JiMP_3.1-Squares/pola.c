//Zastosowano flagi:  -Wall -pedantic -Wextra -Werror -std=c99

#include <stdio.h>
#include <math.h>
#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

void wyborFigury(void);
void wielkosciProstokata();
void wielkosciKola();
void wielkosciTrojkata();

int main(void){

    wyborFigury();

    return 0;
}

void wyborFigury(void){
    int n = 0;
	printf("Wybierz figure (1-prostokat, 2 - trojkat, 3 - kolo): ");
	scanf("%d", &n);

	switch (n)
	{
    case 1:
		wielkosciProstokata();
		break;
	case 2:
		wielkosciTrojkata();
		break;
	case 3:
		wielkosciKola();
		break;
    default:
        printf("Bledna wartosc!\n");
		wyborFigury();
		break;
	}
}

void wielkosciProstokata(void){
    double bok1 = 0, bok2 = 0;
	printf("Podaj boki prostokata: ");
	scanf("%lf %lf", &bok1, &bok2);
	if(bok1 || bok2 <= 0){
        printf("Boki nie moga przyjmowac takich wartosci");
	}
	else{
        double pole = bok1 * bok2;
        double obwod = 2*bok1+2*bok2;
        printf("Pole prostokata wynosi %.2f, a obwod %.2f \n", pole,obwod);
	}
}

void wielkosciTrojkata(void){
    double bok1 = 0,bok2 = 0,bok3 =0;
	printf("Podaj boki trojkata: ");
	scanf("%lf %lf %lf", &bok1, &bok2, &bok3);
	if(bok1 || bok2 || bok3 <= 0){
        printf("Boki nie moga przyjmowac takich wartosci");
	}
	else{
        double polowaObwodu = (bok1+bok2+bok3)/2;
        double obwod = bok1 + bok2 +bok3;
        double poleDoKwadratu = (polowaObwodu*(polowaObwodu-bok1)*(polowaObwodu-bok2)*(polowaObwodu-bok3));
        double pole = sqrt(poleDoKwadratu);
        printf("Pole trojkata wynosi %.2f, a obwod %.2f \n",pole, obwod);
	}
}

void wielkosciKola(void){
    double promien;
	printf("Podaj promien: ");
	scanf("%lf", &promien);
	if(promien <= 0){
        printf("promien nie moze przyjmowac takich wartosci");
	}
	else{
    	double pole = promien*promien*M_PI;
        double obwod = 2*promien*M_PI;
        printf("Pole kola wynosi %.2f, a obwod %.2f \n", pole,obwod);
    }
}
