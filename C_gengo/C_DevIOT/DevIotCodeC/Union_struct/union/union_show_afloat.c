#include<stdio.h>

union Floattypes{
    float floatData;
    unsigned char bytes[4];
};

int main(){
    union Floattypes fvl;

    fvl.floatData = 3.14159;
    printf("Value float: %f\n", fvl.floatData);

    printf("Btyes: ");
    for(int i = 0; i < 4; i++){
        printf("0x%02X ", fvl.bytes[i]);
    }

    return 0;
}