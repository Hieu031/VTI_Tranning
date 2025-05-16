#include<stdio.h>

#define Size 4

int main(){
    char *FullName[] = {"Nguyen Hieu", "Luong Phuong", 
                    "Tran Huong", "Tran Long"};

    for(int i = 0; i < Size; i++){
        printf("Full Name %d is %s\n", i + 1, FullName[i]);
    }

    return 0;
}