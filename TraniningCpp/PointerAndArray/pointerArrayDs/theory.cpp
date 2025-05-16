#include <iostream>

using namespace std;

/*
Relative of pointer and multidimensional array:
    Example: Have array A
    1. The address of A is address of the first row of A and 
    also is addres of first element of the first row of A.

    2. A 2D array can replace by a 1D array and pointers same type. 
        int A[3][3] = int (*A)[3]: this is about way to declare 
    And if we use pointer point to pointer meaning pointer level 2:
        have a way to declare same as above: 
            int **A = int A[3][3] = int (*A)[3]
*/

int main(){
    int A[3][3] = {{1, 2, 3}, {4, 5, 6}};

    // int (*A)[3] = {{1, 2, 3}, {4, 5, 6}};
}