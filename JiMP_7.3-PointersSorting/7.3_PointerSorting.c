//Zastosowano flagi:  -Wall -pedantic -Wextra -Werror -std=c99
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void arrayGenerator(int*);
void pointerSort(int**);

int main(void){

    srand(time(NULL));

    int numbers[]={0,0,0,0,0,0,0,0,0,0};
    arrayGenerator(numbers);
    int *pNumbers[10];
    for(int i = 0; i <10; ++i){
        pNumbers[i]=&numbers[i];
    }
    pointerSort(pNumbers);

    return 0;
}

void arrayGenerator(int* numbers){
    for(int i = 0; i < 10; ++i){
        *(numbers+i) = rand()%200;
        printf("%d ", *(numbers+i));
    }
    printf("\n");
}

void pointerSort(int* pointers[]){
    for(int i = 0; i < 10; ++i){
        int changed = 0;
        for(int j =0; j < 10-i-1;++j){
            if(*pointers[j]>*pointers[j+1]){
                int* tmp = pointers[j+1];
                pointers[j+1]=pointers[j];
                pointers[j]=tmp;
                changed = 1;
            }
        }
        if (changed == 0){
            break;
        }
    }
    for(int i = 0; i < 10; ++i){
        printf("%d ", *pointers[i]);
    }
}

