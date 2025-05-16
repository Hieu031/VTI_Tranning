#include"stdio.h"
#include"string.h"

int main(){
    char str3[] = "HieuBeo";
    // char str2[] = "HieuBEo";
    //char *str1 = "HieuBeo";
    char *str2 = "HieuBEo";
    
    strcat(&str3[2], str2);
    //function: connect str3 and str2

    printf("%s\n", str3);

}