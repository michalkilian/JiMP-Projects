//Zastosowano flagi:  -Wall -pedantic -Wextra -Werror -std=c99

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void generateRandomNumbers(const int, int[]);
void saveNumbersToFile(char*, int*, const int);
void errorsCheck(int, const int);


int main(int argc, char*argv[])
{
    srand(time(NULL));
    const int numberOfNumbers = atoi(argv[1]);
    errorsCheck(argc, numberOfNumbers);
    int randomNumbers[numberOfNumbers];

    generateRandomNumbers(numberOfNumbers, randomNumbers);
    saveNumbersToFile(argv[2], randomNumbers, numberOfNumbers);

    return 0;
}

void generateRandomNumbers(const int numberOfNumbers, int randomNumbers[])
{
    for(int i = 0; i < numberOfNumbers; ++i){
        randomNumbers[i] = rand() % 1001;
    }
}

void saveNumbersToFile(char* filename, int* randomNumbers, const int numberOfNumbers)
{
    FILE *f = fopen(filename,"w");
    if(f == NULL){
        printf("Blad podczas otwierania pliku!");
    }
    else{
        for (int i = 0; i < numberOfNumbers; ++i){
            fprintf(f, "%d\n", randomNumbers[i]);
        }
    }
    fclose(f);
}

void errorsCheck(int argc, const int numberOfNumbers)
{
    if(argc != 3){
        printf("Podano bledno ilosc argumentow!");
        exit(1);
    }
    else if(numberOfNumbers <= 0){
        printf("Blednie podano ilosc liczb do wygenerowania!");
        exit(2);
    }
}
