#include<stdio.h>

//Declare function cal
int sum(int a, int b) { return a + b; }
int disturb(int a, int b) { return a - b; }
int multiple(int a, int b) { return a * b; }

//Define pointer function
typedef int (*calculation) (int, int);

//Declare function callback with pointer "calculation"
int calcu (int a, int b, calculation calculator){
    return calculator(a, b);
}

int main(){
    int add = calcu(1, 5, sum);
    int dis = calcu(6, 2, disturb);
    int mul = calcu(6, 3, multiple);

    printf("%d, %d and %d\n", add, dis, mul);

    return 0;
}