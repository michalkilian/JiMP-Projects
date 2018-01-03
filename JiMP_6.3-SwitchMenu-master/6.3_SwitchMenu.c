//Zastosowano flagi:  -Wall -pedantic -Wextra -Werror -std=c99
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void wybor(int*, int*);
void arrayGenerator(int*, int*);
void arrayPrinting(int*, int*);
void numbersAverage(int*, int*);
void numbersMedian(int*, int*);
void numbersInfAndSup(int*, int*);
void notGeneratedError(void);
void waitingForKey(void);

int main(void){

    int numbers[]={0,0,0,0,0,0,0,0,0,0};
    int ifNumbersGenerated = 0;
    int* pIfNumberGenerated = &ifNumbersGenerated;
    int* pNumbers = numbers;

    while(1){
        wybor(pIfNumberGenerated, pNumbers);
     }

    return 0;
}

void wybor(int* ifNumbersGenerated, int *numbers){
    int n = 0;
    printf("\t-----MENU-----\n\n1. Losowanie tablicy 10 liczb.\n\n2. Wyswietlanie tablicy\n\n3. Liczenie sredniej liczb"
    "\n\n4. Liczenie mediany liczb\n\n5. Liczenie min/max elementu\n\n6. Wyjscie\n\nPodaj liczbe: ");
	scanf("%d", &n);
	switch (n)
	{
        case 1:
            arrayGenerator(ifNumbersGenerated, numbers);
            break;
        case 2:
            arrayPrinting(ifNumbersGenerated, numbers);
            break;
        case 3:
            numbersAverage(ifNumbersGenerated, numbers);
            break;
        case 4:
            numbersMedian(ifNumbersGenerated, numbers);
            break;
        case 5:
            numbersInfAndSup(ifNumbersGenerated, numbers);
            break;
        case 6:
            exit(0);
        default:
            printf("Bledna wartosc!");
            waitingForKey();
            wybor(ifNumbersGenerated, numbers);
            break;
    }
}
void arrayGenerator(int* ifNumbersGenerated, int* numbers){
    srand(time(NULL));
    for(int i = 0; i < 10; ++i){
        *(numbers+i) = rand()%200;
    }
    *ifNumbersGenerated = 1;
    printf("Wygenerowano tablice!");
    waitingForKey();
}
void arrayPrinting(int* ifNumbersGenerated, int* numbers){
    if (*ifNumbersGenerated == 1){
        printf("Tablica liczb:\n");
        for(int i = 0; i < 10; ++i){
            printf("%d ", *(numbers+i));
        }
        waitingForKey();
    }
    else{
        notGeneratedError();
    }
}
void numbersAverage(int* ifNumbersGenerated, int* numbers){

    if(*ifNumbersGenerated == 1){
        float suma = 0;
        for(int i = 0; i < 10; ++i){
            suma+=*(numbers+i);
        }
        printf("Srednia wygenerowanych liczb to %0.2f", suma/10);
        waitingForKey();
    }
    else{
        notGeneratedError();
    }
}
void numbersMedian(int* ifNumbersGenerated, int* numbers){
    if(*ifNumbersGenerated == 1){
        float median = 0;
        median=(*(numbers+4)+(*(numbers+5)))/2;
        printf("Mediana wygenerowanych liczb to %0.1f", median);
        waitingForKey();
    }
    else{
        notGeneratedError();
    }
}
void numbersInfAndSup(int* ifNumbersGenerated, int* numbers){
    if(*ifNumbersGenerated == 1){
        int infimum = *numbers;
        int supremum = *numbers;
        for(int i = 1; i < 10; ++i){
            if(*(numbers+i)>supremum){
                supremum = *(numbers+i);
            }
            else if(*(numbers+i)<infimum){
                infimum = *(numbers+i);
            }
        }
        printf("Minimalna liczba w tablicy to %d, maksymalna to %d", infimum, supremum);
        waitingForKey();
    }
    else{
        notGeneratedError();
    }
}
void notGeneratedError(void){
    printf("Nie wygenerowano jeszcze tablicy!\n");
    getchar();
    printf("Nacisnij klawisz");
    getchar();
    system("cls");
}
void waitingForKey(void){
    getchar();
    printf("\n\nNacisnij klawisz");
    getchar();
    system("cls");
}
