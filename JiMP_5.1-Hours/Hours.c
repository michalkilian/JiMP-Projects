//Zastosowano flagi:  -Wall -pedantic -Wextra -Werror -std=c99
#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

void errorHandler(int hour[]);
int hoursCompare(int hour1[], int hour2[]);


int main (void)
{
    int hour1[SIZE];
    int hour2[SIZE];

    printf("Podaj godzine 1 w formacie GG:MM:SS \n");
    scanf("%d:%d:%d",&hour1[0],&hour1[1], &hour1[2]);
    errorHandler(hour1);

    printf("Podaj godzine 2 w formacie GG:MM:SS \n");
    scanf("%d:%d:%d",&hour2[0],&hour2[1], &hour2[2]);
    errorHandler(hour2);

    printf("Wynik porownania: %d",hoursCompare(hour1,hour2));

    return 0;
}

void errorHandler(int hour[]){

    if (hour[0]>23 || hour[0]<0 || hour[1]<0 || hour[1]>59 || hour[2]<0 || hour[2]>59 ){
        printf("Blad w wprowadzonej godzinie!\n");
        exit(-1);
    }
}

int hoursCompare(int hour1[], int hour2[]){
    int result = 0;

    for(int i = 0; i <3; ++i){
        if(hour1[i]==hour2[i]){
            continue;
        }
        else if(hour1[i]>hour2[i]){
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
