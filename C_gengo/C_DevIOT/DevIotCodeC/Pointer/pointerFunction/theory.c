#include<stdio.h>

/*
Truyền tham trị (truyền giá trị của biến) và truyền tham chiếu (truyền địa chỉ của biến)
là hai khai niệm khác nhau.
    Khi tuyền tham trị vào hàm thì giá trị biến chỉ thay đổi trong phạm vị hàm đó.
    Còn khi truyền tham chiếu thì khi ta tác động vào biến đó trong hàm thì nó cũng sẽ thay đổi
    kể cả khi thoát ra khỏi hàm.
*/

void Change_ThamTri(int a, int b){
    int temp = a;
    a = b;
    b = temp;
}

void Change_ThamChieu(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int a = 100;
    int b = 200;
    printf("Before call function Tham Tri: a = %d, b = %d\n", a, b);

    Change_ThamTri(a, b);
    printf("After call function Tham Tri: a = %d, b = %d\n", a, b);

    Change_ThamChieu(&a, &b);
    printf("After call function Tham Chieu: a = %d, b = %d\n", a, b);

    return 0;
}