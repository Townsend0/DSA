#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define len 25

int arr[len];

void print(){
    for (int a = 0; a < len; a++)
    printf("%d ", arr[a]);
}

void insertionSort(){
    for (int a = 1; a < len; a++){
        int key = arr[a];
        int b = a - 1;
        while(b >= 0 && arr[b] > key)
        arr[b + 1] = arr[b--];
        arr[++b] = key;
    }
}

void main(){
    srand(time(0));
    for (int a = 0; a < len; a++)
    arr[a] = rand() % 100;
    printf("Unsorted array: ");
    print();
    insertionSort();
    printf("\n\nsorted array:   ");
    print();
}