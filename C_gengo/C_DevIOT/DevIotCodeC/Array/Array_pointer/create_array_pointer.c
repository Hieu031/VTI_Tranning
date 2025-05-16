#include<stdio.h>
#include<stdlib.h>
#define sizeA  3
// int main(){
//     int x = {1, 2, 3, 4, 5};
//     int y = {5, 4, 3, 2, 1};

//     int *ptr[2] = {&x, &y};

//     printf("%d\n", ptr[0][0]);
//     printf("%d\n", ptr[1][0]);

//     return 0;
// }

void exportArray(int *pt, int size){
    for(int i = 0; i < size; i++){
        printf("%d\n", pt[i]);
    }
}

int main(){
    int pt1[5] = {1, 2, 3, 4, 5};
    int pt2[5] = {11, 22, 33, 44, 55};
    int pt3[5] = {12, 23, 34, 45, 56};

//    int *ptr[sizeA];//declare pointer ptr is a array
    //allocate memory for a array pointer
    int **ptr = (int **)calloc(5, sizeof(int *));//allocate memory by calloc function

    
    ptr[0] = pt1; // assgin pointer ptr to a array without '&'
    ptr[1] = pt2;
    ptr[2] = pt3;

    exportArray(ptr[0], 5);

    return 0; 
}