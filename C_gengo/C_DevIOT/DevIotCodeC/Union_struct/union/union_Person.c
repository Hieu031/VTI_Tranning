#include<stdio.h>
#include<string.h>

union Person {
    int age;
    int weight;
    int height;
    char career[20];
};

int main(){
    union Person Hieu;
    Hieu.age = 22;
    Hieu.weight = 75;
    Hieu.height = 175;
    strcpy(Hieu.career, "MidStudent");

    printf("Hieu\'s feature\n");
    printf("Tuoi: %d\n", Hieu.age);
    printf("Can nang: %d\n", Hieu.weight);
    printf("Chieu cao: %d\n", Hieu.height);
    printf("Hien dang la %s\n", Hieu.career);

    return 0;
}