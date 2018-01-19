//Zastosowano flagi:  -Wall -pedantic -Wextra -Werror -std=c99

#include <stdio.h>
#include <stdlib.h>

void openFile(char*,int*);
void saveNumbersToFile(char*,int*);
void printSortedNumbers(int*);
void errorsCheck(int);

int main(int argc, char* argv[]){
    int numberCounters[1001] = {0};
    errorsCheck(argc);
    openFile(argv[1],numberCounters);
    if(argc == 2){
        printSortedNumbers(numberCounters);
    }
    else{
        saveNumbersToFile(argv[2],numberCounters);
    }
    return 0;
}

void openFile(char* filename,int numberCounters[1001]){
    int number;
    FILE *f = fopen(filename,"r");
    if(f == NULL){
        printf("Blad podczas otwierania pliku!");
        exit(1);
    }
    else{
        while(fscanf(f,"%d",&number)!=EOF){
            numberCounters[number]++;
        }
    }
    fclose(f);
}

void saveNumbersToFile(char* filename,int numbersCounters[1001]){
    FILE *f = fopen(filename,"w");
    if(f == NULL){
        printf("Blad podczas otwierania pliku!");
    }
    else{
        for (int i = 0; i < 1001; ++i){
            for(int j = 0; j < numbersCounters[i];++j){
                fprintf(f,"%d\n",i);
            }
        }
    }
    fclose(f);
}

void printSortedNumbers(int numbersCounters[1001]){
    for(int i = 0; i < 1001; ++i){
        for(int j = 0; j < numbersCounters[i]; ++j){
            printf("%d\n",i);
        }
    }
}

void errorsCheck(int argc){
    if(argc < 2 || argc > 3){
        printf("Podano bledno ilosc argumentow!");
        exit(1);
    }
}
