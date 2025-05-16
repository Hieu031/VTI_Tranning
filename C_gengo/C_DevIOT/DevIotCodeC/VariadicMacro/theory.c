#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
/*
Marco in C is a way to replace text before complie code
use directive such as #define so as to do.
Macro predefined (macro có sẵn trong C): 
__FILE__: Tên file hiện tại
__LINE__: số dòng hiện tại trong file
__DATE__: Ngày biên dịch
__TIME__: Giờ biên dịch
__func__: Tên hàm hiện tại
Các loại macro chính:
    1. Macro định nghĩa hằng số thay vì dùng "const"
        Example: #define PI 3.14159
        Benefit: 
                - Không chiếm bộ nhớ như biến "const" 
                - Dễ thay đổi giá trị ở nhiều nới bằng Macro
    2. Macro định nghĩa hàm 
        Example: #define SQUARE(x) ((x) * (x)) 
        -   Sử dụng () để phân biệt các toán tử.
    3. Macro có tham số: Có thể có nhiều tham số như hàm
        Example: #define Max(a, b) ((a) > (b) ? (a) : (b))
    4. Macro điều kiện: Dùng để biên dịch có điều kiện
        Example: #ifdef, #infdef
Variadic Macro sames as 1 macro can include input parameters varietily.
    Keywork: __VA_ARGS__
*/

//apply for code LOG
#define dpgprintf(...) printf("%s(%d): %s", __FILE__, __LINE__, __VA_ARGS__);

int main(){
    dpgprintf("Hello Embedded World!\n");
    return 0;
}