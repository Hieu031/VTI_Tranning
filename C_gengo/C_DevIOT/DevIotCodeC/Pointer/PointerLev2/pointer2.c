#include<stdio.h>
#include<stdlib.h>

/*
    Pointer 2 (con tror cấp 2) là một loại con trỏ dùng để 
    lưu trữ địa chỉ của 1 biến con tror khác.
    Feature 1: Change address of pointer 1.
    
*/

int main(){
    int value = 100;
    int *ptr = &value; //con trỏ cấp 1
    int **p_to_p = &ptr; //Con trỏ cấp 2

    printf("value = %d\r\n", value); //return value
    printf("&value = %p\r\n", &value);//return address

    printf("*ptr = %d\r\n", *ptr);//return value
    printf("ptr = %p\r\n", ptr);//return address
    printf("&ptr = %p\r\n", &ptr);//return address

    printf("p_to_p = %p\r\n", p_to_p);//return addr
    printf("*p_to_p = %p\r\n", *p_to_p);// = &ptr
    printf("**p_to_p = %d\r\n", **p_to_p);//return value

    return 0;
}