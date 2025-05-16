#include<stdio.h>
#include<stdlib.h>

/*
How to declare a pointer:
    <type data> * <name pointer>;
*/

int main(){
    int x = 1000;

    int *pt;
    //&pt is address of pointer
    //pt is address pointer point in RAM
    //*pt is value at area address of pointer

    pt = &x;
    printf("&x = %d\n", &x);
    printf("&pt = %d\n", &pt);
    printf("pt = %d\n", pt);
    printf("*pt = %d\n", *pt);

    return 0;

}