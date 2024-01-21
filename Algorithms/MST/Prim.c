#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define size 6
int arr[size][size], chosenColumnIndex[size];

void printArray(){
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++)
        printf("%d ", arr[i][j]);
        printf("\n");
    }
}

bool notInChosenMatrix(int j, int markedRows){
    for (int k = 0; k < markedRows; k++)
    if (j == chosenColumnIndex[k])
    return false;
    return true;
}

void prim(){
    int markedRows = 0, minimumIndex[2];
    chosenColumnIndex[markedRows++] = 0;

    for (int i = 0; i < size - 1; i ++){
        minimumIndex[0] = 0;
        minimumIndex[1] = 0;
        for (int j = 0; j < size; j++){
            if (notInChosenMatrix(j, markedRows)){

                for (int k = 0; k < markedRows; k++)
                if (arr[j][chosenColumnIndex[k]] < arr[minimumIndex[0]][minimumIndex[1]]){
                    minimumIndex[0] = j;
                    minimumIndex[1] = chosenColumnIndex[k];
                }
            }
        }
        chosenColumnIndex[markedRows++] = minimumIndex[0];
        printf("Value: %d Index: [%d, %d]\n", arr[minimumIndex[0]][minimumIndex[1]], minimumIndex[0], minimumIndex[1]);
    }
}

void main(){
    srand(time(0));
    int i, j;
    for (i = 0; i < size; i++){
        for (j = size; j > i; j--)
        arr[i][j] = rand() % 88 + 10;

        for (j = 0; j <= i; j++){
            if (i == j)
            arr[i][j] = 99;
            else
            arr[i][j] = arr[j][i];
        }
    }
    printArray();
    prim();
}
