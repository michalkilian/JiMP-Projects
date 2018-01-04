//Zastosowano flagi:  -Wall -pedantic -Wextra -Werror -std=c99
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void arrayGenerator(int*, int*);
float weightedAverage(int*, int*);

int main(void){

    srand(time(NULL));

    int sizeOfArray = 1;

    printf("Podaj rozmiar tablicy\n");
    scanf("%d", &sizeOfArray);
    if(sizeOfArray>1000000 || sizeOfArray < 1){
        printf("Podano zly rozmiar tablicy!");
        exit(1);
    }

    int numbers[sizeOfArray];
    int* pNumbers = numbers;
    int* pNumbersEnd = pNumbers+sizeOfArray;
    arrayGenerator(pNumbers, pNumbersEnd);
    printf("\nSrednia wazona stworzonej tablicy to %0.2f", weightedAverage(pNumbers,pNumbersEnd));
    return 0;
}

void arrayGenerator(int* numbers, int* numbersEnd){
    while(numbers<numbersEnd){
        *numbers = rand()%20;
        printf("%d ", *numbers);
        numbers++;
    }
}

float weightedAverage(int* numbers, int* numbersEnd){
    float average =0;
    int weight = 0;
    for(int i = 1;;i++){
        if(numbers==numbersEnd){
            break;
        }
        average+=((*numbers)*i);
        weight +=i;
        numbers++;
    }
    return average/weight;
}
