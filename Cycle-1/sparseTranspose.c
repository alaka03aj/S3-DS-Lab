#include <stdio.h>

typedef struct{
    int row;
    int col;
    int val;
}tuple;

tuple sparseMatrix[100], transposeSparse[100];

void display(int arr[100][100], int m, int n){
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            printf("%5d",arr[i][j]);
        }
        printf("\n");
    }
}

void convToSparse(int arr[100][100], int m, int n){
    int k = 1;
    sparseMatrix[0].row = m;
    sparseMatrix[0].col = n;
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            if (arr[i][j]!=0){
                sparseMatrix[k].row = i+1;
                sparseMatrix[k].col = j+1;
                sparseMatrix[k].val = arr[i][j];
                k++;
            }
        }
    }
    sparseMatrix[0].val = k-1;
}

void printSparseMatrix(tuple sparseMat[100]){
    int k = 0;
    while (k!=sparseMat[0].val+1){
        printf("%5d%5d%5d\n",sparseMat[k].row, sparseMat[k].col, sparseMat[k].val);
        k++;
    }
}

void transposeofSparse(){
    transposeSparse[0].row = sparseMatrix[0].col;
    transposeSparse[0].col = sparseMatrix[0].row;
    transposeSparse[0].val = sparseMatrix[0].val;
    int k = 1;
    for (int i=1; i<=sparseMatrix[0].col; i++){
        for (int j=1; j<=sparseMatrix[0].val; j++){
            if (sparseMatrix[j].col == i){
                transposeSparse[k].row = sparseMatrix[j].col;
                transposeSparse[k].col = sparseMatrix[j].row;
                transposeSparse[k].val = sparseMatrix[j].val;
                k++;
            }
        }
    }

}

void main(){
    int m, n;
    printf("Enter size of arary: ");
    scanf("%d %d", &m, &n);
    int matrix[100][100];

    printf("\nEnter elements of mtarix: \n");
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            scanf("%d",&matrix[i][j]);
        }
    }
    display(matrix, m, n);
    convToSparse(matrix, m, n);
    printSparseMatrix(sparseMatrix);
    transposeofSparse();
    printSparseMatrix(transposeSparse);


}