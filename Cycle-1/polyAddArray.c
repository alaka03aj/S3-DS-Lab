#include <stdio.h>

void create(int arr[], int s){
    printf("Enter the terms in the expression starting from smallest degree...\n");
    for (int i=0; i<s; i++){
        printf("Enter coefficient of degree %d\n",i);
        scanf("%d",&arr[i]);
    }
    printf("\n");
}

void display(int arr[], int s){
    printf("Sum: ");
    for (int i=s-1; i>-1; i--){
        if (i==0)
            printf("%d",arr[i]);
        else
            printf("%d x^%d + ",arr[i],i);
    }
    printf("\n");
}

void copy(int a[], int s, int res[]){
    for (int i=0; i<s; i++){
        res[i] = a[i];
    }
}

void padd(int a[], int s, int res[]){
    for (int i=0; i<s; i++){
        res[i]+=a[i];
    }
}

void main(){
    int m, n;
    printf("Enter the order of both polynomials: ");
    scanf("%d %d",&m,&n);

    int a[50], b[50], c[100];
    create(a, m);
    create(b, n);

    if (m>n){
        copy(a,m,c);
        padd(b,n,c);
        display(c,m);
    }
    else{
        copy(b,n,c);
        padd(a,m,c);
        display(c,n);
    }
}