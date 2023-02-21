#include <stdio.h>

typedef struct{
    int c;
    int exp;
}p;

p e1[50], e2[50], res[100];

void create(p e[], int d){
    for (int i=0; i<d; i++){
        printf("Enter degree: ");
        scanf("%d",&e[i].exp);
        printf("Enter coefft: ");
        scanf("%d",&e[i].c);
    }
}

void display(p e[], int d){
    for (int i = 0; i < d; i++){
        if (i!=d-1){
            printf("%d x^%d + ",e[i].c, e[i].exp);
        }
        else{
            printf("%d",e[i].c);
        }
    }
    
}

int padd(p a[], p b[], int m, int n){
    int i = 0, j = 0, k = 0;
    while(i<m && j<n){
        if (a[i].exp == b[j].exp){
            res[k].exp = a[i].exp;
            res[k].c = a[i].c + b[j].c;
            k++;
            i++;
            j++;
        }

        else if(a[i].exp > b[j].exp){
            res[k].exp = a[i].exp;
            res[k].c = a[i].c;
            i++;
            k++;
        }

        else{
            res[k].exp = b[j].exp;
            res[k].c = b[j].c;
            j++;
            k++;
        }
    }

    while (i<m){
        res[k].exp = a[i].exp;
        res[k].c = a[i].c;
        i++;
        k++;
    }

    while (j<n){
        res[k].exp = b[j].exp;
        res[k].c = b[j].c;
        j++;
        k++;
    }

    return k;
}
void main(){
    int d1, d2;
    printf("Enter number of terms in expression 1 and 2: ");
    scanf("%d %d", &d1,&d2);
    printf("Enter values of expression 1\n");
    create(e1,d1);
    printf("Enter values of expression 2\n");
    create(e2,d2);
    int d = padd(e1, e2, d1, d2);
    display(res, d);
    // display(e1,d1);
    // display(e2,d2);

    
}