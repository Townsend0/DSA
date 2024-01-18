#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define len 25

int arr[len];

void print(){
    for (int a = 0; a < len; a++)
    printf("%d ", arr[a]);
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int l, int r){
    int pivot = arr[r], i = l - 1, j = l;
    while(j <= r){
        if (arr[j] <= pivot)
        swap(arr + ++i, arr + j);
        j++;
    }
    return i;
}

void quickSort(int l, int r){
    if (l < r){
        int p = partition(l, r);
        quickSort(l, p - 1);
        quickSort(p + 1, r);
    }
}

void main(){
    srand(time(0));
    for (int a = 0; a < len; a++)
    arr[a] = rand() % 100;
    printf("Unsorted array: ");
    print();
    quickSort(0, len - 1);
    printf("\n\nsorted array:   ");
    print();
}