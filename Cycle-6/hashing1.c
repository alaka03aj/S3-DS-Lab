#include <stdio.h>
#define size 13

int hashTable[size] = {0};

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

void hashFunction(int arr[], int n){
    int key;
    for (int i=0; i<n; i++){
        key = arr[i]%size;
        if (hashTable[key] == 0){
            hashTable[key] = arr[i];
        }
        else{
            int j;
            j = (key+1)%size;
            while(1){
                if (hashTable[j] == 0){
                    hashTable[j] = arr[i];
                    break;
                }
                else{
                    j = (j+1)%size;
                }
            }
        }
    }
}

void main(){
    int n, arr[100];
    printf("Enter size: ");
    scanf("%d",&n);
    insert(arr,n);
    hashFunction(arr,n);
    display(hashTable,size);
}
