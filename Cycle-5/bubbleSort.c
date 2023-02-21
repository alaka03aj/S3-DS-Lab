#include <stdio.h>

void insert(int arr[], int n){
    printf("\nEnter element: ");
    for (int i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }
}

void display(int arr[], int n){
    printf("\nSorted array: ");
    for (int i=0; i<n; i++){
        printf("%d ",arr[i]);
    }
}

void swap(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void bubbleSort(int arr[], int n){
    int swapp;
    for (int i=0; i<n-1; i++){
        swapp = 0;
        for (int j=0; j<n-i-1; j++){
            if (arr[j]>arr[j+1]){
                swapp =1;
                swap(&arr[j],&arr[j+1]);
            }
        }
        if (swapp == 0)
            break;
    }
}

void main(){
    int n, arr[100];
    printf("Enter size: ");
    scanf("%d",&n);
    insert(arr,n);
    bubbleSort(arr,n);
    display(arr,n);
}