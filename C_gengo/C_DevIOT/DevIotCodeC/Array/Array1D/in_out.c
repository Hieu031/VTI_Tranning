#include <stdio.h>
#include <stdlib.h>

void EnterArray(int arr[], int n){
    printf("Enter value of array:\n");
    for(int i = 0; i < n; i++){
        printf("arr[%d] = ", i+1);
        scanf("%d", &arr[i]);
    }
}

void printArray(int arr[], int n){
    printf("Elements of array:");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
}

void SortArray(int arr[], int n){
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(arr[i] < arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
        }
        }
    }
}

int main(){
    
    int n;
    printf("Enter number eles of array:");
    scanf("%d", &n);
    
    int arr[n];

    EnterArray(arr, n);
    printf("Array before Sort: ");
    printArray(arr, n);

    printf("\n");

    SortArray(arr, n);
    printf("Array after Sort: ");
    printArray(arr, n);

    return 0;
}