#include<stdio.h>
#include <stdlib.h>

int main(){
    char x[8] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x0A};

    unsigned char *pt;
    short *ptt;

    pt = x;
    //ptt = x;

    printf("pt point %d\n", pt);
    for(int i = 0; i < 7; i++){
        printf("%x\n", *(pt+i));
    }
}