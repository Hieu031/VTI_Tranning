#include<stdio.h>
#include<stdlib.h>
/*
1. Con trỏ hàm là một biến lưu trữ địa chỉ của một hàm, thông qua biến đó
ta có thể gọi hàm mà nó trỏ tới mà không cần gọi tên của hàm.
2. Con trỏ hàm cho phép viết nhưng đoạn code mang tính tổng quát
3. Con trỏ hàm thường được dùng để viết hàm callback trong chương trình.
*/

/*
Syntax: <Return type> (*<pointer_name>) (<list tham so>);
Name is the same as function but add '*'
*/
// //Định nghĩa một kiểu mới có tên FunctionPointer
// typedef int (*FunctionPointer) (int , int);

// //Khai báo không tường minh
// typedef int (*funct) (int , int);

int add2nu(int a, int b){
    return a + b;
}

int main(){
    //Khai báo tường mình
    int (* func) (int , int);
    func = add2nu;
    // funct = add2nu;

    int resul1 = func(1, 2);
    // int result2 = funct(2, 3);

    printf("%d \n", resul1);

    return 0;
}