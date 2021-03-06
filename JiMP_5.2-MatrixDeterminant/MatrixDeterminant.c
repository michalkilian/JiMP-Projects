//Zastosowano flagi:  -Wall -pedantic -Wextra -Werror -std=c99
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

void matrixFiller(int matrix[SIZE][SIZE]);
void matrixPrinter(int matrix[SIZE][SIZE]);
int matrixDeterminant(int matrix[SIZE][SIZE]);

int main(void)
{
    int matrix[SIZE][SIZE];

    srand(time(NULL));

    matrixFiller(matrix);
    printf("Wylosowana macierz to: \n");
    matrixPrinter(matrix);
    printf("Wyznacznik tej macierzy to: %d", matrixDeterminant(matrix));

    return 0;
}

void matrixFiller(int matrix[SIZE][SIZE]){

    for(int i = 0; i < SIZE; ++i){
        for (int j = 0; j < SIZE; ++j){
                matrix[i][j] = rand()%11;
        }
    }
}

void matrixPrinter(int matrix[SIZE][SIZE]){

    for(int i = 0; i < SIZE; ++i){
        for (int j = 0; j < SIZE; ++j){
                printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
}

int matrixDeterminant(int matrix[SIZE][SIZE]){
    int determinant = 0;
    for(int i = 0; i < SIZE; ++i)
        determinant += (matrix[0][i]*(matrix[1][(i+1)%SIZE]*matrix[2][(i+2)%SIZE]) - (matrix[0][i]*matrix[1][(i+2)%SIZE]*matrix[2][(i+1)%SIZE]));
    return determinant;
}
