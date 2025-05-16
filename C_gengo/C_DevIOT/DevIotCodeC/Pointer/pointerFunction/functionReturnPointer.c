#include<stdio.h>
#include <stdlib.h>
// //function compare use pointer 
// int * max(int *a, int *b){
//     if(*a > *b) 
//         return a;
//     else if (*a < *b)
//         return b;
//     else return a;
// }

//function compare use static 
int * max(int a, int b){
    static int max = 0;
    if(a < b) 
        max = b;
    else if (a > b)
        max = a;
    else max = a;
    return &max;
}

//Or we can declare global variable "max" to use in main function 
int main(){
    int a = 10;
    int b = 9;
    int *result = max(a, b);

    printf("Max = %d\n", *result);

    return 0;
}