#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_LENGTH_NAME 50

//define mode teacher: 1 student: 0
#define TEACHERMODE 1

typedef struct {
    char name[MAX_LENGTH_NAME];
    float gpa;
}Student;

Student student[MAX_STUDENTS];
int student_count = 0;

void SaveDataToFile(){
    FILE *file = fopen("students.txt", "w");

    if(file == NULL){
        printf("Can't open file!\n");
        return;
    }
    
    for(int i = 0; i < student_count; i++){
        fprintf(file, "%s %.f\n", student[i].name, student[i].gpa);
    }

    fclose(file);
    printf("Data stored in file!\n");
}

void ReadDataFromFile(){
    FILE *file = fopen("students.txt", "r");

    if(file == NULL){
        printf("Not found students! Start w empty list.\n");
        return;
    }
    
    student_count = 0; //Reset student counts
    while(fscanf(file, "%49s %f\n", student[student_count].name, &student[student_count].gpa) == 2){
        student_count++;
        if(student_count >= MAX_STUDENTS){
            printf("List full!\n");
            break;
        }
    }
    
    printf("Struct: \n");
    for(int i = 0; i < student_count; i++){
        printf("%s %.2f\n", student[i].name, student[i].gpa);
    }

    fclose(file);
    printf("Data stored in struct successfully!!\n");
}

//Mode Teacher to search and manage students
#if TEACHERMODE

//Function type in4 stu
void inputScores(){
    int n;
    printf("Enter quantity: ");
    scanf("%d", &n);
    getchar(); //delete key newline

    for(int i = 0; i < n; i++){
        printf("Enter name no %d: ", i + 1);
        fgets(student[student_count].name, MAX_LENGTH_NAME, stdin);
        student[student_count].name[strcspn(student[student_count].name, "\n")] = '\0';//remove '\n' of fgets()

        printf("Enter gpa: ");
        scanf("%f", &student[student_count].gpa);
        getchar();

        student_count++;
    }
}

//Function show in4 stu
void printGPA(){
    printf("List GPA of Student:\n");
    for(int i = 0; i < student_count; i++){
        printf("%s: %.f\n", student[i].name, student[i].gpa);
    }   
}

//Function find gpa of student
void findStuGpa(){
    char name[MAX_LENGTH_NAME];
    printf("\nEnter name: ");
    getchar();
    fgets(name, MAX_LENGTH_NAME, stdin);
    name[strcspn(name, "\n")] = '\0';

    for(int i = 0; i < student_count; i++){
        if(strcmp(student[i].name, name) == 0){
            printf("%s : %.2f\n", student[i].name, student[i].gpa);
            return;
        }
    }
    printf("Not found!\n");
}

#else //Student search gpa following name
void checkGpa(){
    char name[MAX_LENGTH_NAME];
    printf("Enter name: ");
    getchar();
    fgets(name, MAX_LENGTH_NAME, stdin);
    name[strcspn(name, "\n")] = '\0';//remove '\n'

    for(int i = 0; i < student_count; i++){
        if(strcmp(student[i].name, name) == 0){
            printf("Gpa of %s: %.f\n", student[i].name, student[i].gpa);
            return;
        }
    }
    printf("Not found your name!\n");
}
#endif

int main(){
    int choice;

#if TEACHERMODE
    ReadDataFromFile();
    do{
        printf("----Program type or check gpa!------\n");
        printf("1. Type gpa\n");
        printf("2. Show gpa\n");
        printf("3. Find gpa follow name\n");
        printf("0. Exit!\n");
        printf("-----------------------------------\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            inputScores();
            SaveDataToFile();
            break;
        case 2:
            printGPA();
            break;
        case 3: 
            findStuGpa();
            break;
        case 0:
            printf("Exit!\n");
            break;
        default:
            printf("Not valid!\n");
        }
    }while(choice != 0);
#else
    ReadDataFromFile();
    printf("----Program Check gpa for Stu----\n");
    checkGpa();
#endif
    return 0;
}

