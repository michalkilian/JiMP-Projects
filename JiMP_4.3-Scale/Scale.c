//Zastosowano flagi:  -Wall -pedantic -Wextra -Werror -std=c99
#include <stdio.h>

int wagiKulek[9] = {0,0,0,0,0,0,0,0,0}; // kulki tej samej masy maja wartosc 0 kulka ciezsza bedzie miala 1

int wazenie(void);

int main(void){


    int n;
    printf("Podaj numer kulki ciezszej: (od 1 do 9) \n");
    scanf ("%d", &n);
    if(n>9 || n<1){
        printf("Blad!");
        return -1;
    }
    wagiKulek[n-1] = 1;
    printf("Numer ciezszej kulki to %d", wazenie());


    return 0;
}

int wazenie(void){

    int ciezszaKulka = -1;

    if(wagiKulek[0]+wagiKulek[1]+wagiKulek[2]>wagiKulek[3]+wagiKulek[4]+wagiKulek[5]){
        if(wagiKulek[0]>wagiKulek[1]){
            ciezszaKulka = 1;
        }
        else if (wagiKulek[0]==wagiKulek[1]){
            ciezszaKulka = 3;
        }
        else{
            ciezszaKulka = 2;
        }
    }
    else if(wagiKulek[0]+wagiKulek[1]+wagiKulek[2]==wagiKulek[3]+wagiKulek[4]+wagiKulek[5]){
        if(wagiKulek[6]>wagiKulek[7]){
            ciezszaKulka = 7;
        }
        else if (wagiKulek[6]==wagiKulek[7]){
            ciezszaKulka = 9;
        }
        else{
            ciezszaKulka = 8;
        }
    }
    else{
        if(wagiKulek[3]>wagiKulek[4]){
            ciezszaKulka = 4;
        }
        else if (wagiKulek[3]==wagiKulek[4]){
            ciezszaKulka = 6;
        }
        else{
            ciezszaKulka = 5;
        }
    }

    return ciezszaKulka;
}
