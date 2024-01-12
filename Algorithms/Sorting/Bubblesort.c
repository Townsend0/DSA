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

void bubbleSort(){
    for (int a = 0; a < len - 1; a++)
    for (int b = 0; b < len - 1 - a; b++)
    if (arr[b] > arr[b + 1])
    swap(arr + b + 1, arr + b);
}

void main(){
    srand(time(0));
    int a;
    for (a = 0; a < len; a++)
    arr[a] = rand() % 100;
    printf("Unsorted array: ");
    print();
    bubbleSort();
    printf("\n\nsorted array:   ");
    print();
}
