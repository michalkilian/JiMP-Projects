//Zastosowano flagi:  -Wall -pedantic -Wextra -Werror -std=c99
#include <stdio.h>
#include <stdlib.h>

void numberCheck(int);
void arrayOperations(int*,int);
int compare(const void *, const void* );

int main(void){
    int numberOfNumbers;
    printf("Podaj rozmiar tablicy: ");
    scanf("%d",&numberOfNumbers);
    numberCheck(numberOfNumbers);

    int arrayOfNumbers[numberOfNumbers];
    printf("Podaj elementy tablicy: ");
    for(int i = 0;i<numberOfNumbers;++i){
        if(scanf("%d", &arrayOfNumbers[i])==EOF){
            if(i==0){
                exit(0);
            }
        numberOfNumbers = i;
        break;
        }
    }

    arrayOperations(arrayOfNumbers,numberOfNumbers);

    return 0;
}

void numberCheck(int numberOfNumbers){
    if (numberOfNumbers>1000000 || numberOfNumbers < 1){
        printf("Bledny rozmiar tablicy!\n");
        exit(0);
    }
}

void arrayOperations(int* array,int size){
    int sum = 0, mode = 0;
    float mean = 0, median = 0;
    int count = 0, num = 0, maxCount = 0;

    qsort(array,size,sizeof(int),compare);

    for(int i = 0;i < size;++i){
        sum+=array[i];
        if(num != array[i]){
            num = array[i];
            count = 1;
        }
        else{
            count++;
        }
        if (count>maxCount){
            maxCount = count;
            mode = array[i];
        }
    }

    mean = (float)sum/(float)size;

    if(size%2==0){
        median = ((float)array[size/2]+(float)array[size/2-1])/2;
    }
    else{
        median = (float)
        array[(size-1)/2];
    }

    printf("Suma %d %o %X\n", sum,sum,sum);
    printf("Dominanta %d %o %X\n",mode,mode,mode);
    printf("Srednia %0.2f %A\n",mean,mean);
    printf("Mediana %0.2f %A\n",median,median);

}

int compare(const void * a, const void * b){
    if ( *(int*)a <  *(int*)b ) return -1;
    else if ( *(int*)a == *(int*)b ) return 0;
    else return 1;
}
