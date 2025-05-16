#include<stdio.h>
#include<stdlib.h>

/*
Con trỏ hằng là một con trỏ trỏ đến 1 vùng nhớ hằng
chỉ đọc được giá trị vùng nhớ mà không ghi được dữ liệu vào đó.
*/

int main(){
    int x = 100;
    const int *pt = &x; //declare a pointer const

    //*pt = 50;

    printf("x = %d\n", *pt);

    return 0;
}