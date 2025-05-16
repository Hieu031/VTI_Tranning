#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//declare struct explicit - Tường minh
// struct student{
//     char name[30];
//     int age;
//     char phoneNumber[20];
//     float class;
// };

#define MAX_STUDENT 10 //Maximum add 10 student
#define NAME_LENGTH 30 //Length maximum of name is 30 characters

//declare struct implicit - Không tường minh
typedef struct{
    char name[30];
    int id; //ID student
    char sex; // "M" or "F"
    int age;
    float math;
    float physics;
    float chemistry;
    float average; //computed average score
}student;

//a variable value, access via "."
//a variable pointer, acess via "->"

//Declare prototpye fuction
void EnterStudent(student **std1, int *count); //Type information student
void printStudent(student *std1, int count); //print information student
void DeleteStudent(student **std1, int *count); //delete student at position pos
void UpdateStudent(student *std1, int count); //update student        
void FindStudent(student *std1, int count); //find student by name
void SortAtoZ(student *std1, int count); //sort student by name
void SortAverage(student *std1, int count); //sort student by average score
void SaveToFile(student *std1, int count);
void LoadFile(student **std1, int *count);

int main(){
    student* std1 = NULL;
    int count = 0;
    int choice;

    //read datafrom file located if have
    LoadFile(&std1, &count);
    do
    {
        printf("\n------MENU: HANDLE INFORMATION STUDENT------\n");
        printf("1. Add information student!\n");
        printf("2. Show information student!\n");
        printf("3. Update Student according to ID!\n");
        printf("4. Delete Student according to ID!\n");
        printf("5. Find Student according to ID!\n");
        printf("6. Sort Student according to Name!\n");
        printf("7. Sort Student according to Average score!\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf(" %d", &choice);
        getchar(); //consume leftover newline

        switch (choice)
        {
            case 0:
                SaveToFile(std1, count);
                printf("Exiting...\n");
                break;    
            case 1:
                EnterStudent(&std1, &count);
                break;
            case 2:
                printf("\n------------List student--------------\n");
                printStudent(std1, count);
                break;
            case 3:
                UpdateStudent(std1, count);
                break;
            case 4: 
                DeleteStudent(&std1, &count);
                break;
            case 5:
                FindStudent(std1, count);
                break;
            case 6:
                SortAtoZ(std1, count);
                break;
            case 7:
                SortAverage(std1, count);
                break;
            default:
                printf("Not Invalid! Please try agian.\n");
                break;
        }
    } while (choice != 0);

    //free alloacted memory for each student before exiting
    // for(int i = 0; i < count; i++){
    //     free(std1[i]);
    // }
    free(std1);

    return 0;

}

void EnterStudent(student **std1, int *count){
    if(*count >= MAX_STUDENT){
        printf("List Full!\nStop Update until confirm again.\n");
        return;
    }   
    
    //Allocate memory for add student
    student *newstd1 = realloc(*std1, (*count + 1) * sizeof(student));
    if(!newstd1){
        printf("Allocate failure!\n");
        return;
    }

    *std1 = newstd1;

    //enter in4 student need added.
    printf("Enter information Student %d!\n", *count + 1);

    //enter name
    printf("Enter name: ");
    // getchar(); //clear any leftover newlone from previous input
    fgets((*std1)[*count].name, sizeof((*std1)[*count].name), stdin);
    (*std1)[*count].name[strcspn((*std1)[*count].name, "\n")] = 0; //clear key "\n"

    printf("Enter ID: ");
    scanf("%d", &((*std1)[*count].id));
    
    //enter sex
    printf("Enter Sex (M/F): ");
    scanf(" %c", &((*std1)[*count].sex)); 
    //use the space before %c to skip any whitespace
    // fflush(stdin); //clear stdin

    //enter age
    printf("Enter age: ");
    scanf("%d", &((*std1)[*count].age));

    //enter mark math
    printf("Enter math: ");
    scanf("%f", &((*std1)[*count].math));
    
    //Enter mark physics
    printf("Enter physics: ");
    scanf("%f", &((*std1)[*count].physics));
    
    //Enter mark chemistry
    printf("Enter Chemistry: ");
    scanf("%f", &((*std1)[*count].chemistry));

    //Calculate average marks
    (*std1)[*count].average = ((*std1)[*count].math + (*std1)[*count].physics + (*std1)[*count].chemistry) / 3.0f;

    //Update new student
    // std1[*count] = newstd1;
    (*count)++;
    printf("Add student successfully!\n"); 
}

void printStudent(student *std1, int count){
    //Check list empty
    if(count == 0){
        printf("List student empty!\n");
        return;
    }

    //print in4 stduent
    // printf("\nList Student:\n");
    printf("Name\t\tid\tSex\tAge\tMath\tPhysics\tChemistry\tAverage\n");
    for(int i =  0; i < count; i++){
        printf("%-15s\t%d\t%c\t%d\t%.2f\t%.2f\t%.2f\t\t%.2f\n", 
                std1[i].name,
                std1[i].id,
                std1[i].sex,
                std1[i].age, 
                std1[i].math, 
                std1[i].physics, 
                std1[i].chemistry, 
                std1[i].average);
    }
}

void UpdateStudent(student *std1, int count){
    if(count == 0){
        printf("List empty!\n");
        return;
    }

    int id, found = 0;
    printf("Enter id student need updating: ");
    scanf("%d", &id);

    for(int i = 0; i < count; i++){
        if(std1[i].id == id){
            found = 1;
            printf("Update name: ");
            getchar(); //clear any leftover newlone from previous input
            fgets(std1[i].name, sizeof(std1[i].name), stdin);
            std1[i].name[strcspn(std1[i].name, "\n")] = 0; //clear key "\n"

            printf("Update ID: ");
            scanf("%d", &std1[i].id);
            
            //enter sex
            printf("Update Sex (M/F): ");
            scanf(" %c", &std1[i].sex); 

            //enter age
            printf("Update age: ");
            scanf("%d", &std1[i].age);

            //enter mark math
            printf("Update math: ");
            scanf("%f", &std1[i].math);
            
            //Enter mark physics
            printf("Update physics: ");
            scanf("%f", &std1[i].physics);
        
            //Enter mark chemistry
            printf("Update Chemistry: ");
            scanf("%f", &std1[i].chemistry);
            
            // Recalculate average
            std1[i].average = (std1[i].math + std1[i].physics + std1[i].chemistry) / 3.0f;

            printf("Student updated successfully!\n");
            break;
        }
    }
    if(!found){
        printf("Not found student matched with ID: %d\n", id);
    }
}

void DeleteStudent(student **std1, int *count){
    if(*count == 0){
        printf("List empty!\n");
        return;
    }

    int id, found = 0;
    printf("Enter id of student need deleting: ");
    scanf("%d", &id);

    for(int i = 0; i < *count; i++){
        if((*std1)[i].id == id){
            found = 1;
            for(int j = i; j < *count - 1; j++){
                (*std1)[j] = (*std1)[j+1];
            }
            (*count)--;

            *std1 = realloc(*std1, (*count) * sizeof(student));
            printf("Delete student with id %d successfully!\n", id);
            break;
        }
    }
    if(!found){
        printf("Not found student with id %d!\n", id);
    }
}

void FindStudent(student *std1, int count){
    if(count == 0){
        printf("List student empty!\n");
        return;
    }

    printf("Enter id student need finding: ");
    int key; scanf(" %d", &key);

    int found = 0;
    for(int i = 0; i < count; i++){
        if(std1[i].id == key){
            printf("Student found!\nInformation of student need finding: \n");
            printStudent(&std1[i], 1);
            found = 1;
        }
    }
    if(!found) {
        printf("No matching student found for %d!\n", key);
    }
}

void SortAtoZ(student *std1, int count){
    if(count == 0){
        printf("No stduent to sort!\n");
        return;
    }

    for(int i = 0; i < count - 1; i++){
        for(int j = i + 1; j < count; j++){
            if(strcmp(std1[i].name, std1[j].name) > 0){
                student temp = std1[i];
                std1[i] = std1[j];
                std1[j] = temp;
            }
        }
    }
    printf("Student sorted by name (A-Z) successfully!\n");
}

void SortAverage(student *std1, int count){
    if(count == 0){
        printf("No stduent to sort!\n");
        return;
    }

    for(int i = 0; i < count - 1; i++){
        for(int j = i + 1; j < count; j++){
            if(std1[i].average < std1[j].average){
                student temp = std1[i];
                std1[i] = std1[j];
                std1[j] = temp;
            }
        }
    }
    printf("Student sorted by average score successfully!\n");
}

void SaveToFile(student *std1, int count){
    FILE* file = fopen("student.dat", "wb"); //write a file with write binary type
    if(!file){
        printf("Error: Cound not open file!\n");
        return;
    }

    fwrite(&count, sizeof(int), 1, file); //save count student to file
    fwrite(std1, sizeof(student), count, file); //save data student to file
    fclose(file); //close file after finish process saving
    printf("Save data student successfully!\n");
}

void LoadFile(student **std1, int *count){
    FILE* file = fopen("student.dat", "rb"); //read a file binary type
    if(!file){
        printf("No Existing data found!\n");
        return;
    }

    fread(count, sizeof(int), 1, file); //read count of student
    if(*count > 0){
        *std1 = malloc ((*count) * sizeof(student));//allocate memory for student from file
        if(!*std1){
            printf("Memory allocation failed while loading data!\n");
            *count = 0;
            return;
        }        
        fread(*std1, sizeof(student), *count, file);
    }
    fclose(file);
    printf("Data load successfully! %d students found!\n", *count);
}
