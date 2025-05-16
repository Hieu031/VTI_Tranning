#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    char *name;
    int age;
} svInfo;

int main(){
    svInfo sv1;

    //allocate memory for sv1
    sv1.name = calloc(30, sizeof(char));
    if(sv1.name == NULL){
        fprintf(stderr, "Allocation failure! Exit.\n");
        exit(EXIT_FAILURE);
    }


    printf("Enter name: ");
    if(fgets(sv1.name, 30, stdin) != NULL){
        size_t size = strlen(sv1.name);
        //remove newline character if present
        if(size > 0 && sv1.name[size - 1] == '\n'){
            sv1.name[size - 1] == '\0';
        }else{
            fprintf(stderr, "Type error name!\n");
            free(sv1.name);
            exit(EXIT_FAILURE);
        }
    }

    printf("Enter age: ");
    if(scanf("%d", &sv1.age) != 1){
        fprintf(stderr, "Type error age!\n");
        free(sv1.name);
        exit(EXIT_FAILURE);

    }

    printf("Name: %s\n", sv1.name);
    printf("Age: %d\n", sv1.age );

    free(sv1.name);

    return 0;
}
