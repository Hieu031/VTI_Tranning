#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
void meAll(int *pt){
    pt = malloc(sizeof(int));
}

void main(){
    int *pt;
    meAll(pt);
    pt[0] = 1;
    printf("%d", pt[0]);
}