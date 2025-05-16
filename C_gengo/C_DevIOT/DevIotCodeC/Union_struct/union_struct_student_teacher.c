#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Student{
    char name[10];
    int iD;
    float gpa;
};

struct Teacher
{
    char name[10];
    char subject[10];
    char yoe[10];
};

union Person{
    struct Student student;
    struct Teacher teacher;
};

int main(){
    union Person person;
    int choice;

    while(1){
        printf("----Management Information Student and Teacher-----------\n");
        printf("1. Type Student information!\n");
        printf("2. Type teacher information!\n");
        printf("3. Exit!\n");
        printf("___________________________________________________________\n");

        printf("Enter choice:");
        scanf("%d", &choice);

        if(choice == 3){
            printf("You chose exit program. See you again!");
            break;
        }

        switch (choice)
        {
        case 1:
             printf("Type data for Student:\n");
            
            printf("Name: ");
            getchar(); //delate memory
            fgets(person.student.name, 50, stdin);
            person.student.name[strcspn(person.student.name, "\n")] = '\0'; //delete key '/n'

            printf("ID: ");
            scanf("%d", &person.student.iD);

            printf("GPA: ");
            scanf("%f", &person.student.gpa);

            printf("Information of Student:\n");
            printf("Name: %s\n", person.student. name);
            printf("ID: %d\n", person.student.iD);
            printf("GPA: %f\n", person.student.gpa);
            
            break;
        case 2:
            printf("Type data for Teacher:\n");
            
            printf("Name: ");
            getchar(); //delate memory
            fgets(person.teacher.name, 50, stdin);
            person.teacher.name[strcspn(person.teacher.name, "\n")] = '\0'; //delete key '/n'

            printf("Subject be in charge of: ");
            fgets(person.teacher.subject, 50, stdin);
            person.teacher.subject[strcspn(person.teacher.subject, "\n")] = '\0'; //delete key '/n'


            printf("Year of experience: ");
            scanf("%d", &person.teacher.yoe);

            printf("Information of Teacher:\n");
            printf("Name: %s\n", person.teacher. name);
            printf("Subject: %s\n", person.teacher.subject);
            printf("YOE: %d\n", person.teacher.yoe);
            break;
        default:
            printf("Chose failed. Let choice again!\n");
            //break;
        }
    }
    return 0;
}