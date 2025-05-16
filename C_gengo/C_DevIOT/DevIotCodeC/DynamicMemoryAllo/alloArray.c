#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int Enter(int *arr, int count);
int* Add(int *arr, int *count);
void Print(int *arr, int count);
int* Delete(int *arr, int *count, int pos);

int main(){
    int n; 
    printf("Enter count: ");
    scanf("%d", &n);
    
    int *arr = (int*)calloc(n, sizeof(int));

    Enter(arr, n);
    Print(arr, n);
    printf("\n");

    arr = Add(arr, &n);
    printf("Array after add: \n");
    Print(arr, n);
    printf("\n");

    printf("Array after delete: \n");
    arr = Delete(arr, &n, 3);
    Print(arr, n);
    printf("\n");

    free(arr);
    return 0;
}

int Enter(int *arr, int count){
    printf("Enter elements of Array\n");
    for(int  i = 0; i < count; i++){
        scanf("%d", arr + i);
    }
}

int* Add(int *arr, int *count){
    printf("Enter element need add: ");
    int n;
    scanf("%d", &n);

    int *arr2 = (int*)calloc(*count + 1, sizeof(int));
    memcpy(arr2, arr, (*count) * sizeof(int));
    arr2[*count] = n;

    free(arr);
    (*count)++;

    return arr2;
}

void Print(int *arr, int count){
    for(int i = 0; i < count; i++){
        printf("%d ", *(arr + i));
    }
}

int* Delete(int *arr, int *count, int pos){
    //
    for(int i = pos; i < *count - 1; i++){
        *(arr + i) = *(arr + i + 1);
    }

    (*count)--;
    int *arr2 = (int*)calloc(*count, sizeof(int));

    memcpy(arr2, arr, (*count) * sizeof(int));

    free(arr);

    return arr2;
}