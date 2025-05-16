#include <stdio.h>
#include <stdlib.h>
// Hàm so sánh để sắp xếp tăng dần
int ascending(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Hàm so sánh để sắp xếp giảm dần
int descending(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

// Hàm thực hiện sắp xếp sử dụng con trỏ hàm
void sortArray(int *arr, int size, int (*compare)(const void *, const void *)) {
    qsort(arr, size, sizeof(int), compare);
}

// Hàm in mảng
void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int size, choice;
    
    // Nhập kích thước mảng
    printf("Enter array size: ");
    scanf("%d", &size);
    
    int arr[size];
    
    // Nhập các phần tử của mảng
    printf("Enter array's eles: \n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Chọn cách sắp xếp
    printf("How to sort:\n1 -ascending\n2 - descending\nChoice: ");
    scanf("%d", &choice);
    
    if (choice == 1) {
        sortArray(arr, size, ascending);
    } else if (choice == 2) {
        sortArray(arr, size, descending);
    } else {
        printf("Not valid\n");
        return 1;
    }
    
    // In mảng sau khi sắp xếp
    printf("Array after sort: ");
    printArray(arr, size);
    
    return 0;
}
