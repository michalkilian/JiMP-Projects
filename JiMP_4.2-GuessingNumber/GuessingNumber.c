//Zastosowano flagi:  -Wall -pedantic -Wextra -Werror -std=c99
#include <stdio.h>

int wyborLiczby(void);
void zgadywanie(int);

int main(void){

    zgadywanie(wyborLiczby());

    return 0;
}

int wyborLiczby(void){

    int liczba;
    printf("Podaj liczbe calkowita od 1 do 10: ");
    scanf("%d", &liczba);
    if(liczba>10){
        printf("Wprowadzono numer wiêkszy od 10, automatycznie zredukowano do zadanego zakresu.\n");
        liczba=(liczba%10);
    }
    else if(liczba<1){
        printf("Wprowadzono numer mniejszy od 1, automatycznie podniesiono do zadanego zakresu.\n");
        liczba=((liczba*(-1))%10);
        if (liczba == 0){
            liczba++;
        }
    }
    return liczba;

}

void zgadywanie(int liczba){

    int guess = 6;
    int leftEdge = 1;
    int rightEdge = 10;
    int i = 1;
    while (guess != liczba){
        if(guess < liczba){

            leftEdge = guess+1;
            guess = (leftEdge+rightEdge)/2;
        }
        else{
            rightEdge = guess-1;
            guess = (leftEdge+rightEdge)/2;
        }
        printf("krok: %d\n przypuszczenie: %d\n",i,guess);
        ++i;
    }
    if(i == 1){
        printf("krok: %d\n przypuszczenie: %d\n",i,guess);
    }

}
