#include <stdio.h>
#include<stdlib.h>
//define function callback
typedef int (*compare) (int, int);

//function input array
void inputArray(int *arr, int length);
//function output Array
void outputArray(int *arr, int length);
void Sort(int *arr, int left, int right, compare cmp);
int Ascending(int x, int y);
int Descending(int x, int y);

int main(){
    printf("Enter length of arr: ");
    int n; scanf("%d", &n);
    int *arr = (int*)malloc(n*sizeof(int));

    inputArray(arr, n);
    printf("\n");

    outputArray(arr, n);
    printf("\n");

    Sort(arr, 0, n - 1, Ascending);
    outputArray(arr, n);
    printf("\n");

    Sort(arr, 0, n - 1, Descending);
    outputArray(arr, n);
    printf("\n");

    return 0;
}

void inputArray(int *arr, int length){
    printf("Enter array has %d eles: \n", length);
    for(int i = 0; i < length; i++){
        printf("Enter element %d: ", i + 1);
        scanf("%d", (arr+i));
    }
}

void outputArray(int *arr, int length){
    printf("Array: ");
    for(int i = 0; i < length; i++){
        printf("%d ", *(arr+i));
    }
    printf("\n");
}

void Sort(int *arr, int left, int right, compare cmp){
    //In quick sort, check first index and rear index
    if(left >= right){
        return; 
    }

    int mid = left + (right - left)/2; //find middle element
    int i = left, j = right; //declare i, j to traveres

    while (i <= j)
    {
        while(cmp(arr[i], arr[mid]) < 0) i++;
        while(cmp(arr[j], arr[mid]) > 0) j--;

        if(i <= j){
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    }

    //recursive to the end
    if(left < j){
        Sort(arr, left, j, cmp);
    }
    if(i < right){
        Sort(arr, i , right, cmp);
    }
    
}

int Ascending(int x, int y){
    return x > y ? 1 : (x < y ? -1 : 0);
}

int Descending(int x,int y){
    return x < y ? 1 : (x > y ? -1 : 0);
}