#include <stdio.h>
#include <stdarg.h>

#define LOG(...)    printf(__VA_ARGS__)

int main(){
    LOG("Hello!\n");
    LOG("%d + %d = %d%c", 1, 2, 3, 's');

    return 0;
}