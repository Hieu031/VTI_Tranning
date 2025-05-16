#include<stdio.h>
#include<stdlib.h>

void allocationMemory(int **ptr, size_t size){
    *ptr = (int *)malloc(size * sizeof(int));
    if(*ptr == NULL){
        printf("Allocation failed!\r\n");
        exit(1);
    }

    for(size_t i = 0; i < size; i++){
        (*ptr)[i] = i;
    }
}

int main(){
    int *array = NULL;
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    size_t size = n;

    allocationMemory(&array, size);

    for(size_t i = 0; i < size; i++){
        printf("array[%zu] = %d\n", i, array[i]);
    }

    free(array);

    return 0;
}