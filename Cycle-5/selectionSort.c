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

void selectionSort(int arr[], int n){
    for (int i=0; i<n-1; i++){
        int temp = i;
        for (int j=i+1; j<n; j++){
            if (arr[j]<arr[temp]){
                temp = j;
            }
        }
        swap(&arr[temp], &arr[i]);
    }
}

void main(){
    int n, arr[100];
    printf("Enter size: ");
    scanf("%d",&n);
    insert(arr,n);
    selectionSort(arr,n);
    display(arr,n);
}