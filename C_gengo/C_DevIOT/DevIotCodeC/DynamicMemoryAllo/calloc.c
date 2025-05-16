#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
void meAll(int *pt){
    pt = calloc(10, sizeof(int));
}

void main(){
    int *pt;
    meAll(pt);
    pt[0] = 1111111111;
    printf("%d", pt[0]);
}