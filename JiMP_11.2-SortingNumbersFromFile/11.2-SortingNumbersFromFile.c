//Zastosowano flagi:  -Wall -pedantic -Wextra -Werror -std=c99

#include <stdio.h>
#include <stdlib.h>

int openFile(char*,int*, int,char* argv[]);
void saveNumbersToFile(char*,int*,int);
void printSortedNumbers(int*,int);
void errorsCheck(int);
int compare(const void *, const void* );

int main(int argc, char* argv[]){
    errorsCheck(argc);

    int* numbers = NULL;
    openFile(argv[1],numbers,argc,argv);

    return 0;
}

int openFile(char* filename,int* numbers,int argc,char* argv[]){
    FILE *f = fopen(filename,"r");
    int number = 0;
    int counter = 0;
    if(f == NULL){
        printf("Blad podczas otwierania pliku!");
        exit(1);
    }
    else{
        while(fscanf(f,"%d",&number)!=EOF){
            numbers = (int*)realloc(numbers,sizeof(int)*(counter+1));
            *(numbers+counter)=number;
            counter++;
        }
    }
    fclose(f);

    qsort(numbers,counter,sizeof(int),compare);

    if(argc == 2){
        printSortedNumbers(numbers,counter);
    }
    else{
        saveNumbersToFile(argv[2],numbers,counter);
    }
    free(numbers);
    return counter;
}

void saveNumbersToFile(char* filename,int* sortedNumbers,int numberOfNumbers){
    FILE *f = fopen(filename,"w");
    if(f == NULL){
        printf("Blad podczas otwierania pliku!");
    }
    else{
        for (int i = 0; i < numberOfNumbers; ++i){
            fprintf(f,"%d\n",sortedNumbers[i]);
        }
    }
    fclose(f);

}

void printSortedNumbers(int* sortedNubmers,int numberOfNumbers){
    for(int i = 0; i < numberOfNumbers; ++i){
        printf("%d\n",*(sortedNubmers+i));
    }
}

void errorsCheck(int argc){
    if(argc < 2 || argc > 3){
        printf("Podano bledno ilosc argumentow!");
        exit(1);
    }
}

int compare(const void * a, const void * b){
    if ( *(int*)a <  *(int*)b ) return -1;
    else if ( *(int*)a == *(int*)b ) return 0;
    else return 1;
}
