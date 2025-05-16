#include "stdio.h"
#include "string.h"
int main(){
    //char *str = "Deviot"; this is a string.
    char str[] = "Deviot";//this is a array.
    // ABC
    strcpy(str, "ABC");
    //str = "ABC"; // ABC and Deviot is different.
    // str[0] = 'A';
    // str[1] = 'B';
    // str[2] = 'C';
    // str[3] = '\0';
    printf("%s", str);

    return 0;
}