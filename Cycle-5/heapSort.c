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

void heapify(int arr[], int n, int i){
    int largest = i;
    int left = 2*i +1;
    int right = 2*i +2;

    if (left<n && arr[left]> arr[largest])
        largest = left;
    if (right<n && arr[right]>arr[largest])
        largest = right;
    if (largest != i){
        swap(&arr[i],&arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n){
    for (int i = n/2 - 1; i>=0; i--)
        heapify(arr, n, i);
    for (int i = n-1; i>0; i--){
        swap(&arr[0],&arr[i]);
        heapify(arr, i, 0);
    }
}

void main(){
    int n, arr[100];
    printf("Enter size: ");
    scanf("%d",&n);
    insert(arr,n);
    heapSort(arr,n);
    display(arr,n);
}