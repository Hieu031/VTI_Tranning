#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int (*compare)(int, int);

typedef struct{
    char name[20];
    char ID[10];
    int age;
}Student;

void AddStd(Student** std, int* count);
void DisplayStd(Student* std, int count);
void FindByNameId(Student* std, int count);
void SortByAge(Student* std, int count, compare cmp);
void DeleteStd(Student** std, int* count);
int Ascending(int a, int b);
int Descending(int a, int b);
void SaveToFile(Student* std, int count);
void LoadToFile(Student** std, int* count);

int main(){
    Student* std = NULL;
    int count = 0;
    int choice;
    
    //read data from old access
    LoadToFile(&std, &count);

    do{
        printf("__________________MENU___________________\n");
        printf("1. Add student!\n");
        printf("2. Display list student!\n");
        printf("3. Find student through Name or ID!\n");
        printf("4. Sort list student ascending by age!\n");
        printf("5. Sort list student descending by age!\n");
        printf("6. Delete Student through name or ID!\n");
        printf("7. Exit!\n");
        printf("Choose function: ");
        scanf("%d", &choice);
        getchar(); //consume leftover

        switch(choice){
            case 1: 
                AddStd(&std, &count);
                break;
            case 2:
                DisplayStd(std, count);
                break;
            case 3:
                FindByNameId(std, count);
                break;
            case 4:
                SortByAge(std, count, Ascending);
                break;
            case 5:
                SortByAge(std, count, Descending);
                break;
            case 6:
                DeleteStd(&std, &count);
                break;
            case 7:
                SaveToFile(std, count);
                printf("End program!...\n");
                break;
            default:
                printf("Input not valid! Choice again, please!\n");
                break;
        }
    }while(choice != 7);

    free(std);
    return 0;
}

void AddStd(Student** std, int* count){
    //reallocate memory to hold one more student
    Student* temp = realloc (*std, (*count + 1) * sizeof(Student));
    if(!temp){
        printf("Allocation failed!\n");
        return;
    } 

    //Update list std
    *std = temp;

    //Enter information new student
    printf("Enter name: ");
    fgets(((*std)[*count].name), sizeof((*std)[*count].name), stdin); //type name pass fgets function
    (*std)[*count].name[strcspn((*std)[*count].name, "\n")] = '\0'; //remove key newline
   
    printf("Enter ID: ");
    fgets(((*std)[*count].ID), sizeof((*std)[*count].ID), stdin); //type name pass fgets function
    (*std)[*count].ID[strcspn((*std)[*count].ID, "\n")] = '\0'; //remove key newline

    printf("Enter Age: ");
    scanf("%d", &(*std)[*count].age);
    getchar(); // Consume leftover newline


    (*count)++; //increase numbers student 

    printf("Add student %s succesfully!\n", (*std)[*count-1].name);
}

void DisplayStd(Student* std, int count){
    //check list empty
    if(count == 0){
        printf("List empty!\n");
        return;
    }

    // Print table header
    printf("+----+----------+----------------------+-----+\n");
    printf("| No | ID       | Name                 | Age |\n");
    printf("+----+----------+----------------------+-----+\n");
    // Print each student row
    for (int i = 0; i < count; i++) {
        printf("| %2d | %-8s | %-20s | %3d |\n",
               i + 1,
               std[i].ID,
               std[i].name,
               std[i].age);
    }
    printf("+----+----------+----------------------+-----+\n");
}

void FindByNameId(Student* std, int count){
    if(count == 0){
        printf("List student empty!\n");
        free(std);
        std = NULL;
        return;
    }

    char key[20];
    printf("Enter Name or ID of student need searching: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0'; //remove newline

    int found = 0;
    for(int i = 0; i < count; i++){
        /*
        strcmp return 0 if key is the same as std[i].ID 
        and strstr returns the first pointer if key includes string name    
        */
        if(strcmp(key, std[i].ID) == 0  || strstr(key, std[i].name) != NULL){
            printf("\n________Search Result__________\n");
            printf("+----------+-----------------------+\n");
            printf("|ID        | Name            | Age |\n");
            printf("+----------+-----------------------+\n");
            printf("| %-8s | %-15s | %3d |\n",
                    std[i].ID,
                    std[i].name,
                    std[i].age);
        }
        found = 1;
    }
    if(!found) {printf("No matching sutdent found for %s!\n", key);}
}

void SortByAge(Student* std, int count, compare cmp){
    if(count <= 1){
        printf("List empty or has only 1 element!\n");
        return;
    }

    for(int i = 0; i < count - 1; i++){
        for(int j = i + 1; j < count; j++){
            //using pointer function to sort asc or desc
            //swap if cmp returns > 0
            if(cmp(std[i].age, std[j].age) > 0){
                Student tmp = std[i];
                std[i] = std[j];
                std[j] = tmp;
            }
        }
    }
    printf("Sorted!\n");
}

int Ascending(int a, int b){
    // return a > b ? 1 : (a < b ? -1 : 0);
    return a > b ? 1 : 0;
}

int Descending(int a, int b){
    // return a < b ? 1 : (a > b ? -1 : 0);
    return a < b ? 1 : 0;
}

void DeleteStd(Student** std, int* count){
    if(count == 0){
        printf("List student empty!\n");
        free(*std);
        *std = NULL;
        return;
    }

    char key[20];
    printf("Enter Name or ID of student must delete: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0'; //remove newline

    //check name or id with key
    int index = -1;
    for(int i = 0; i < *count; i++){
        if(strcmp(key, (*std)[i].ID) == 0 || strstr(key, (*std)[i].name) != NULL){
            index = i;
            break;
        }
    }
    //if not found -> not found:))
    if(index == -1) {
        printf("Not found student with name or id %d!\n", key);
        return; //Exit function
    }

    for(int i = index; i < *count - 1; i++){
        (*std)[i] = (*std)[i + 1];
    }
    if(*count - 1 > 0){
        Student* tmp = realloc(*std, (*count - 1) * sizeof(Student));
        if(tmp){
            *std = tmp;
        }
    }else{
        free(*std);
        *std = NULL;
    }

    (*count)--; //after delete decrease numbers student

    printf("Delete Student with name or id %s succesfully!\n", key);
}

void SaveToFile(Student* std, int count){
    FILE* file = fopen("stdudents.dat", "wb");
    if(!file){
        printf("Error: Could not open file!\n");
        return;
    }

    fwrite(&count, sizeof(int), 1, file); //save count of student
    fwrite(std, sizeof(Student), count, file);
    fclose(file);

    printf("Data save successfully!\n");
}

void LoadToFile(Student** std, int* count){
    FILE* file = fopen("stdudents.dat", "rb");
    if(!file){
        printf("No Existing data found!\n");
        return;
    }
    fread(count, sizeof(int), 1, file); //read the count of student
    if(*count >  0){
        *std = malloc(*count * sizeof(Student));
        if(!*std){
            printf("Memory allocation failed while loading data!\n");
            fclose(file);
            *count = 0;
            return;
        }
        fread(*std, sizeof(Student), *count, file); //read students data
    }
    fclose(file);
    printf("Data load succesfully! %d students found.\n", *count);
}