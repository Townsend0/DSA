#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define len 25

int arr[len];

void swap(int *a, int *b){
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

void print(){
    for (int a = 0; a < len; a++)
    printf("%d ", arr[a]);
}

void selectionSort(){
    for (int a = 0; a < len - 1; a++){
        int min = a;
        for (int b = a + 1; b < len; b++)
        if (arr[b] < arr[min])
        min = b;
        if (min != a)
        swap(arr + a, arr + min);
    }
}

void main(){
    srand(time(0));
    for (int a = 0; a < len; a++)
    arr[a] = rand() % 100;
    printf("Unsorted array: ");
    print();
    selectionSort();
    printf("\n\nsorted array:   ");
    print();
}