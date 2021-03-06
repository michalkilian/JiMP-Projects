//Zastosowano flagi:  -Wall -pedantic -Wextra -Werror -std=c99
#include <stdio.h>
#include <math.h>


void wczytywanieWspolczynnikow(double*);
double delta(double*);
void policzPierwiastki(double,double*);

int main(void){

    double wspolczynniki[3] = {0,0,0};
    wczytywanieWspolczynnikow(wspolczynniki);
    policzPierwiastki(delta(wspolczynniki),wspolczynniki);

    return 0;
}

void wczytywanieWspolczynnikow(double wspolczynniki[3]){

    printf("Podaj wspolczynniki a2, a1 i a0 rownania kwadratowego: \n");
    scanf("%lf %lf %lf", &wspolczynniki[0], &wspolczynniki[1], &wspolczynniki[2]);
}

double delta(double wspolczynniki[3]){
    double wartoscDelty = wspolczynniki[1]*wspolczynniki[1]-(4*wspolczynniki[0]*wspolczynniki[2]);
    return wartoscDelty;
}

void policzPierwiastki(double delta,double wspolczynniki[3]){
    if(wspolczynniki[0]==0){
        printf("Rownanie jest liniowe i ma 1 rozwiazanie: %f",(wspolczynniki[2]/wspolczynniki[1]*(-1)));
    }
    else if (delta < 0){
        printf("Rownanie nie ma rozwiazan");
    }
    else if (delta == 0){
        double x1 = (-1*wspolczynniki[1])/(2*wspolczynniki[0]);
        printf("Rownanie ma 1 rozwiazanie rowne: %0.2f",x1);
    }
    else{
        double x1 = ((-1*wspolczynniki[1])-sqrt(delta))/(2*wspolczynniki[0]);
        double x2 = ((-1*wspolczynniki[1])+sqrt(delta))/(2*wspolczynniki[0]);
        printf("Rownanie ma 2 rozwiazania rowne: %0.2f %0.2f",x1,x2);
    }
}

