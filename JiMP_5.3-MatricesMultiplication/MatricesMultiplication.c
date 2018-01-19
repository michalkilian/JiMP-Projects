//Zastosowano flagi:  -Wall -pedantic -Wextra -Werror -std=c99
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SIZE 2

void matrixMultiplication(int matrix[SIZE][SIZE][SIZE], int);
void matrixMerge(int matrix1[SIZE][SIZE], int matrix2[SIZE][SIZE], int mergedMatrix[SIZE][SIZE][SIZE], int);
void matrixRandomFiller(int matrix[SIZE][SIZE], int);
void matrixPrinter(int matrix[SIZE][SIZE], int);
//void matrixDeMerge(int mergedMatrix[SIZE][SIZE][SIZE], int matrix1[SIZE][SIZE], int matrix2[SIZE][SIZE]);

int main(void)
{
    srand(time(NULL));

    int matrix1[SIZE][SIZE];
    int matrix2[SIZE][SIZE];
    int mergedMatrix[SIZE][SIZE][SIZE];

    matrixRandomFiller(matrix1, SIZE);
    matrixRandomFiller(matrix2, SIZE);

    printf("Wylosowane macierze to: \n\n");
    matrixPrinter(matrix1, SIZE);
    matrixPrinter(matrix2, SIZE);

    matrixMerge(matrix1, matrix2, mergedMatrix, SIZE);
    printf("Iloczyn macierzy wynosi: \n\n");
    matrixMultiplication(mergedMatrix, SIZE);

    return 0;
}

void matrixRandomFiller(int matrix[SIZE][SIZE], int size)
{
    for(int i = 0; i < size; ++i){
        for (int j = 0; j < size; ++j){
                matrix[i][j] = (rand()%201)-100;
        }
    }
}

void matrixPrinter(int matrix[SIZE][SIZE], int size)
{
    for(int i = 0; i < size; ++i){
        for (int j = 0; j < size; ++j){
                printf("%3d ",matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void matrixMerge(int matrix1[SIZE][SIZE], int matrix2[SIZE][SIZE], int mergedMatrix[SIZE][SIZE][SIZE], int size){
    for (int i = 0; i < size; ++i){
        for(int j = 0; j < size; ++j){
            for(int k = 0; k < size; ++k){
                if(i==0){
                mergedMatrix[i][j][k]=matrix1[j][k];
                }
                else{
                    mergedMatrix[i][j][k]=matrix2[j][k];
                }
            }
        }
    }
}
void matrixMultiplication(int mergedMatrix[SIZE][SIZE][SIZE], int size)
{
    for (int i = 0; i < size; ++i){
        for(int j = 0; j < size; ++j){
            int suma = 0;
            for(int k = 0; k < size; ++k){
                suma += mergedMatrix[0][i][k] * mergedMatrix[1][k][j];
            }
            printf("%5d ",suma);
        }
        printf("\n");
    }
}

/*void matrixDeMerge(int mergedMatrix[SIZE][SIZE][SIZE, int matrix1[SIZE][SIZE], int matrix2[SIZE][SIZE], int size)
{
    for (int i = 0; i < size; ++i){
        for(int j = 0; j < size; ++j){
            for(int k = 0; k < size; ++k){
                if(i==0){
                matrix1[j][k]=mergedMatrix[i][j][k];
                }
                else{
                    matrix2[j][k]=mergedMatrix[i][j][k];
                }
            }
        }
    }
}
*/
