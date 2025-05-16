#include <stdio.h>
#include <stdlib.h>

//function write to file 
void writeFile(const char *filename){
    FILE *f = fopen(filename, "w"); //Open file to write
    if(f == NULL){
        perror("Error open file!\n");
        exit(EXIT_FAILURE);
    }
    fprintf(f,"Hello, I love VietNam!\n");
    fprintf(f,"プログラムが大好きです!\n");
    fclose(f);
    //use fseek(f, 0, SEEK_SET); 
    //if want to keep opening file
}

//function read from file
void readFile(const char *filename){
    FILE *f = fopen(filename, "r"); //Open file to read
    if(f == NULL){
        perror("Error open file!\n");
        exit(EXIT_FAILURE);
    }
    
    char buffer[256];
    while(fgets(buffer, sizeof(buffer), f) != NULL){
        printf("%s", buffer);
    }

    fclose(f);
}

int main(){
    const char *filename = "test.txt";

    writeFile(filename);
    readFile(filename);

    return 0;
}