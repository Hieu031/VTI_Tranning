#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
    int n[10] = {0};
    int i = 0;
    char str1[] = "27/12/2002/21/2";
    char *pt = strtok(str1, "/");
    while(pt){
        n[i++] = atoi(pt);
        printf("%s\n", pt);
        pt = strtok(NULL, "/");//strtok help spit string depend on key. can many keys.
    }

    for(int i = 0; i < 10; i++){
        printf("%d ", n[i]);
    }
    return 0;

    //sprintf help print and creat a array.
}