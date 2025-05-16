#include <stdio.h>
#include<stdlib.h>
#include<string.h>
/*
Giống với struct chỉ khác ở điểm:
    Cách quản lý bộ nhớ.
1. 
*/

typedef union{
    char name[10];
    int cost;
} car;

int main(){
    car c1;
    strcpy(c1.name, "Ford V1");
    printf("Infromation Vehicle!\n");
    printf("Name: %s\n", c1.name);
    c1.cost = 5000;

    printf("Cost: %d\n", c1.cost);

    return 0;
}