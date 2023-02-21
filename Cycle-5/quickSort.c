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

int partition(int arr[], int left, int right){
    int pivot = arr[left];
    int pivIndex = left;

    while(left<right){

        while (arr[left] <= pivot)
            left++;

        while (arr[right]>pivot)
            right--;

        if (left<right){
            swap(&arr[left],&arr[right]);
        }
    }
    arr[pivIndex] = arr[right];
    arr[right] = pivot;

    return right;
}

void quickSort(int arr[], int left, int right){
    if (left>=right){
        return;
    }
    int p = partition(arr,left,right);
    quickSort(arr,left,p-1);
    quickSort(arr,p+1,right);
}
void main(){
    int n, arr[100];
    printf("Enter size: ");
    scanf("%d",&n);
    insert(arr,n);
    quickSort(arr,0,n-1);
    display(arr,n);
}