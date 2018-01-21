//Zastosowano flagi:  -Wall -pedantic -Wextra -Werror -std=c99
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void arrayGenerator(int*, int);
void pointerSort(int**, int);
void swap(int*, int*);

int main(void)
{
    srand(time(NULL));

    int numbers[]={0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int sizeOfNumbersArray = sizeof(numbers) / sizeof(numbers[0]);
    arrayGenerator(numbers, sizeOfNumbersArray);
    int *pNumbers[sizeOfNumbersArray];
    for(int i = 0; i < sizeOfNumbersArray; ++i){
        pNumbers[i] = &numbers[i];
    }
    pointerSort(pNumbers,sizeOfNumbersArray);

    return 0;
}

void arrayGenerator(int* numbers, int sizeOfNumbersArray)
{
    for(int i = 0; i < sizeOfNumbersArray; ++i){
        *(numbers+i) = rand()%200;
        printf("%d ", *(numbers+i));
    }
    printf("\n");
}

void swap(int* pointer1, int* pointer2)
{
    int tmp = *pointer2;
    *pointer2 = *pointer1;
    *pointer1 = tmp;
}

void pointerSort(int* pointers[], int sizeOfNumbersArray)
{
    for(int i = 0; i < sizeOfNumbersArray; ++i){
        int changed = 0;
        for(int j =0; j < sizeOfNumbersArray-i-1; ++j){
            if(*pointers[j] > *pointers[j+1]){
                swap(pointers[j], pointers[j+1]);
                changed = 1;
            }
        }
        if (changed == 0){
            break;
        }
    }
    for(int i = 0; i < sizeOfNumbersArray; ++i){
        printf("%d ", *pointers[i]);
    }
}
