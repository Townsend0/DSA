#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define len 25

int arr[len];

void print(){
    for (int a = 0; a < len; a++)
    printf("%d ", arr[a]);
}

void merge(int l, int m, int r){
    int i = l, j = m + 1, k = 0, c[r - l + 1];
    while(i <= m && j <= r){
        if (arr[i] < arr[j])
        c[k++] = arr[i++];
        else
        c[k++] = arr[j++];
    }

    while(i <= m)
    c[k++] = arr[i++];

    while(j <= r)
    c[k++] = arr[j++];

    for (int a = 0; a < k; a++)
    arr[a + l] = c[a];
}

void mergeSort(int l, int r){
    if (l < r){
        int m = (l + r) / 2;
        mergeSort(l, m);
        mergeSort(m + 1, r);
        merge(l, m, r);
    }
}

void main(){
    srand(time(0));
    for (int a = 0; a < len; a++)
    arr[a] = rand() % 100;
    printf("Unsorted array: ");
    print();
    mergeSort(0, len - 1);
    printf("\n\nsorted array:   ");
    print();
}