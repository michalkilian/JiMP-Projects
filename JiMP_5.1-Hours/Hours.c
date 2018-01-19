//Zastosowano flagi:  -Wall -pedantic -Wextra -Werror -std=c99
#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

void errorHandler(int hour[]);
int hoursCompare(int hour1[], int hour2[],int);
void scanfHour(int,int*);

int main (void)
{
    int hour1[SIZE];
    int hour2[SIZE];

    scanfHour(1,hour1);
    scanfHour(2,hour2);

    int compareResult = hoursCompare(hour1,hour2,SIZE);

    printf("Wynik porownania: %d ",compareResult);
    if(compareResult == 1){
        printf("- 2 godzina jest godzina pozniejsza\n");
    }
    else if(compareResult == 0){
        printf(" - godziny sa rowne\n");
    }
    else{
        printf("- 1 godzina jest godzina pozniejsza\n");
    }

    return 0;
}

void errorHandler(int hour[]){

    if (hour[0]>23 || hour[0]<0 || hour[1]<0 || hour[1]>59 || hour[2]<0 || hour[2]>59 ){
        printf("Blad w wprowadzonej godzinie!\n");
        exit(-1);
    }
}

int hoursCompare(int hour1[SIZE], int hour2[SIZE],int size){
    int result = 0;

    for(int i = 0; i < size; ++i){
        if(hour1[i] == hour2[i]){
            continue;
        }
        else if(hour1[i] > hour2[i]){
            result = -1;
            break;
        }
        else {
            result = 1;
            break;
        }
    }

    return result;
}

void scanfHour(int number,int hour[SIZE]){
    printf("Podaj godzine %d w formacie GG:MM:SS \n",number);
    scanf("%d:%d:%d",&hour[0],&hour[1], &hour[2]);
    errorHandler(hour);
}
