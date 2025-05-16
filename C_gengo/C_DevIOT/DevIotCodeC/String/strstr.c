#include"stdio.h"
#include"string.h"

void removeSpace(char s1[], int index);
int main(){
    char s1[] = "Let Study Programming Together!";
    //char *sub = " "; 
    char *first = strstr(s1, " ");
    while (first != NULL)
    {
        /* code */
        //printf("Find in %d\n", first - string);
        int index = first - s1;
        removeSpace(s1, index);
        first = strstr(s1, " ");
    }
    printf("This is string after remove \"space\":%s", s1);   
    // if(first != NULL){
    //     printf("The remain string: %d\n", first - string);
    // }
    // else{
    //     printf("Not found!\r\n");
    // }
    return 0;
}
void removeSpace(char s1[], int index){
    for (int i = index; i < strlen(s1); i++)
    {
        s1[i] = s1[i+1];
    }
    
}