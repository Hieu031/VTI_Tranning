#include<stdio.h>
#include<stdlib.h>

void InputArr(int *arr, int n){
    printf("Enter elements:\n");
    for(int i = 0; i < n; i++){
        printf("arr[%d]: ", i);
        scanf("%d", (arr + i));
    }
}

void SortArr(int *arr, int n){
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(*(arr+i) > *(arr + j)){
                int temp = *(arr + i);
                *(arr + i) = *(arr + j);
                *(arr + j) = temp;
            }
        }
    }
}

void printArr(int *arr, int n){
    printf("Elements of Array: ");
    for(int i = 0; i < n; i++){
        printf("%d ", *(arr+i));
    }
}

int main(){
    int n;
    printf("Enter number of elements:");
    scanf("%d", &n);

    //Allocate memory for array n elements
    int *arr = (int*)malloc(n * sizeof(int));

    InputArr(arr, n);

    SortArr(arr, n);

    printArr(arr, n);

    //Clear memory
    free(arr);
    return 0;
}