#include<stdio.h>

/*
Hằng con trỏ có thể đọc ghi dữ liệu bình thường nhưng
không thể thay đổi địa chỉ dữ liệu đã trỏ tới.
Nói cách khác là nó chỉ trỏ tới 1 thằng khi được khai báo.
*/

int main(){
    int x = 100;
    int y = 101;

    int * const pt = &x;

    pt = &y;

    printf("x = %d\n", *pt);

    return 0;
}