#include"stdio.h"
#include"string.h"

int main(){
    char str3[] = "HieuBeo";
    // char str2[] = "HieuBEo";
    char *str1 = "HieuBeo";
    char *str2 = "HieuBEo";
    
    strcpy(&str3[2], str2);
    //function: copy str2 to str3[2]

    printf("%s\n", str3);

    int res = strcmp(str1, str2);
//strcmp is function used to compare str1 and str2

    if(res > 0){
        printf("str1 > str2");
    }
    else if(res < 0){
        printf("str1 < str2");
    }
    else{
        printf("str1 = str2");
    }
    return 0;
}