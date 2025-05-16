#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//Union same as struct 
//but at a moment, it only incudes a value. 
//This is kiểu khai báo tường minh
union Car{
    char company[20];
    int cost;
    int typeNumber;
};
/*
//Anh this is kiểu khai báo không tường minh
typedef union{
    char company[10];
    int cost;
}motobike;
*/

int main(){
    union Car vinfast;
    //char s1[10];
    strcpy(vinfast.company, "VinGroup");
    vinfast.cost = 1000;
    vinfast.typeNumber = 7;

    printf("Chiec xe nay cua cong ty %s", vinfast.company);
    printf("co gia %d ", vinfast.cost);
    printf("va co %d ", vinfast.typeNumber);
    printf("cho ngoi!");
    
    return 0;
}