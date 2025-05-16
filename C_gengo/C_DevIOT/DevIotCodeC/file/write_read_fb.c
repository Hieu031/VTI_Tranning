#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    int n1, n2, n3;
}threeNum;

void wrtieToFileBinary(const char *fn, threeNum numbers){
    FILE *fptr;
    if((fptr = fopen("test1.txt", "wb")) == NULL){
        printf("Error! opening file");
        //program exits if the file poiter returns NULL
        exit(1);
    }

    for (int i = 1; i < 5; i++){
        numbers.n1 = i;
        numbers.n2 = 5*i;
        numbers.n3 = 5*i+1;
        fwrite(&numbers, sizeof(struct threeNum), 1, fptr);
    }
    fclose(fptr);
}

void readToFileBinary(const char *fn, threeNum numbers){
    FILE *fptr;
    if((fptr = fopen("test1.txt", "rb")) == NULL){
        printf("Error! opening file");
        //program exits if the file poiter returns NULL
        exit(1);
    }

    for (int i = 1; i < 5; i++){
        fread(&numbers, sizeof(struct threeNum), 1, fptr);
        printf("n1: %d\nn2: %d\nn3: %d", numbers.n1, numbers.n2, numbers.n3);
    }
    fclose(fptr);
}

int main(){
    threeNum num;
    FILE *fptr;

    wrtieToFileBinary(fptr, num);
    readToFileBinary(fptr, num);

    return 0;
}
