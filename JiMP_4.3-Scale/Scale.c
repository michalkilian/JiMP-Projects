//Zastosowano flagi:  -Wall -pedantic -Wextra -Werror -std=c99
#include <stdio.h>

int wazenie(int*);

int main(void){

    int wagiKulek[9] = {0,0,0,0,0,0,0,0,0}; // kulki tej samej masy maja wartosc 0 kulka ciezsza bedzie miala 1
    int n;

    printf("Podaj numer kulki ciezszej: (od 1 do 9) \n");
    scanf ("%d", &n);
    if(n>9 || n<1){
        printf("Blad!");
        return -1;
    }
    wagiKulek[n-1] = 1;
    printf("Numer ciezszej kulki to %d", wazenie(wagiKulek));


    return 0;
}

int wazenie(int wagiKulek[9]){

    int ciezszaKulka = -1;
    int wagaPierwszychTrzechKulek = wagiKulek[0]+wagiKulek[1]+wagiKulek[2];
    int wagaDrugichTrzechKulek = wagiKulek[3]+wagiKulek[4]+wagiKulek[5];

    if(wagaPierwszychTrzechKulek>wagaDrugichTrzechKulek){
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
    else if(wagaPierwszychTrzechKulek==wagaDrugichTrzechKulek){
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
