#include <stdio.h>
#include <stdlib.h>

void TypeArray(int **a, int row, int col){
    int i,j;
    for(i = 0; i < row; i++){
        for(j = 0; j < col; j++){
            printf("a[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
}

void exportArray(int **a, int row, int col){
    int i, j;
    for(i = 0; i < row; i++){
        for(j = 0; j < col; j++){
            printf("%5d", a[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int **a = NULL;
    int row, col;
    printf("Enter row: ");
    scanf("%d", &row);

    printf("Enter col: ");
    scanf("%d", &col);

    a = (int **)malloc(row * sizeof(int *));

    for(int i = 0; i < col; i++){
        a[i] = (int *)malloc(col * sizeof(int *));
    }

    TypeArray(a, row, col);

    exportArray(a, row, col);

    for(int i = 0; i < col; i++){
        free(a[i]);
    }

    free(a);

    return 0;
}