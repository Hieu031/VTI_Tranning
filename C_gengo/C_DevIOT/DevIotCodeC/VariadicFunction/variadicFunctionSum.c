#include<stdio.h>
#include<stdarg.h>

// int AddNumbers(int n, ...){
//     int sum = 0;

//     //Define a pointer points to argument list
//     va_list ptr;

//     //Start process take paras from list
//     va_start(ptr, n);

//     for(int i = 0; i < n; i++){
//         //get parameter out by method va_arg
//         //Need to pass in list and variable type of parameters need get out.
//         sum = sum + va_arg(ptr, int);
//         }
//     //End process get parameters
//     va_end(ptr);

//     return sum;
// }

int AddNumbers(char *numberEles, ...){
    int sum = 0;

    //Define a pointer points to argument list
    va_list ptr;

    int n = atoi(numberEles);
    //Start process take paras from list
    va_start(ptr, n);

    for(int i = 0; i < n; i++){
        //get parameter out by method va_arg
        //Need to pass in list and variable type of parameters need get out.
        sum = sum + va_arg(ptr, int);
        }
    //End process get parameters
    va_end(ptr);

    return sum;
}

int main(){
    printf("Show results of Variadic Funtions:\n");

    int r1 = AddNumbers("2", 1, 3);
    int r2 = AddNumbers("3", 1, 3, 5);
    int r3 = AddNumbers("4", 5, 6, 7, 9);

    printf("When pass in 2 parameters: 1 + 3 = %d\n", r1);
    printf("When pass in 3 parameters: 1 + 3 + 5 = %d\n", r2);
    printf("When pass in 4 parameters: 5 + 6 + 7 + 9 = %d\n", r3);

    return 0;
}