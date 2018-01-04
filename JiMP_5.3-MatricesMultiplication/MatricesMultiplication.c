//Zastosowano flagi:  -Wall -pedantic -Wextra -Werror -std=c99
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void matrixMultiplication(int matrix[2][2][2]);
void matrixMerge(int matrix1[2][2], int matrix2[2][2], int mergedMatrix[2][2][2]);
void matrixFiller(int matrix[2][2]);
void matrixPrinter(int matrix[2][2]);
//void matrixDeMerge(int mergedMatrix[2][2][2], int matrix1[2][2], int matrix2[2][2]);

int main(void){

    srand(time(NULL));

    int matrix1[2][2];
    int matrix2[2][2];
    int mergedMatrix[2][2][2];

    matrixFiller(matrix1);
    matrixFiller(matrix2);

    printf("Wylosowane macierze to: \n\n");
    matrixPrinter(matrix1);
    matrixPrinter(matrix2);

    matrixMerge(matrix1,matrix2,mergedMatrix);
    printf("Iloczyn macierzy wynosi: \n\n");
    matrixMultiplication(mergedMatrix);

    return 0;
}

void matrixFiller(int matrix[2][2]){

    for(int i = 0; i <2;++i){
        for (int j = 0; j<2; ++j){
                matrix[i][j] = (rand()%201)-100;
        }
    }
}
void matrixPrinter(int matrix[2][2]){
    for(int i = 0; i <2;++i){
        for (int j = 0; j<2; ++j){
                printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
void matrixMerge(int matrix1[2][2], int matrix2[2][2], int mergedMatrix[2][2][2]){
    for (int i = 0; i < 2; ++i){
        for(int j = 0; j < 2; ++j){
            for(int k = 0; k<2;++k){
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
void matrixMultiplication(int mergedMatrix[2][2][2]){
    for (int i = 0; i<2;++i){
        for(int j = 0; j < 2; ++j){
            int suma = 0;
            for(int k = 0; k < 2;++k){
                suma += mergedMatrix[0][i][k]*mergedMatrix[1][k][j];
            }
            printf("%d ",suma);
        }
        printf("\n");
    }
}
/*void matrixDeMerge(int mergedMatrix[2][2][2], int matrix1[2][2], int matrix2[2][2]){
    for (int i = 0; i < 2; ++i){
        for(int j = 0; j < 2; ++j){
            for(int k = 0; k<2;++k){
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
