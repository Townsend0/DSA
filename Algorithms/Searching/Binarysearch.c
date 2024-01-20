#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int binarySearch(int *arr, int val, int size){
    int i = 0, j = size - 1;
    while(i <= j){
        int mid = (i + j) / 2;
        if (arr[mid] == val)
        return mid;
        if (val < arr[mid])
        j = mid - 1;
        else
        i = mid + 1;
    }
    return -1;
}

void printArray(int *arr, int size){
    printf("\n");
    for (int a = 0; a < size; a++)
    printf("(%d, %d) - ", a, arr[a]);
}

void main(){
    int size, val;
    printf("Enter the size of the array: ") && scanf("%d", &size);
    system("cls");
    int *arr = (int*)malloc(sizeof(int) * size);
    for (int a = 0; a < size; a++)
    printf("Enter the value at index %d: ", a) && scanf("%d", arr + a);
    system("cls");
    printf("Enter the value you want to search for: ") && scanf("%d", &val);
    system("cls");
    printArray(arr, size);
    printf("\n\nThe index of the value you entered is: %d", binarySearch(arr, val, size));
}
