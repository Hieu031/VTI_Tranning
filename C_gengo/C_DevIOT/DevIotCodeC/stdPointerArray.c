#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 10
#define NAME_LENGTH 100

typedef struct {
    int id;
    char name[NAME_LENGTH];
    int age;
} Student;

void addStudent(Student **students, int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("List Full!\n");
        return;
    }

    Student *newStudent = (Student *)malloc(sizeof(Student));
    if (!newStudent) {
        printf("can't allocate memory!\n");
        return;
    }

    printf("Enter ID: ");
    scanf("%d", &newStudent->id);

    printf("Enter name: ");
    getchar();
    fgets(newStudent->name, NAME_LENGTH, stdin);
    newStudent->name[strcspn(newStudent->name, "\n")] = '\0';
    
    printf("Enter age: ");
    scanf("%d", &newStudent->age);

    students[*count] = newStudent;
    (*count)++;
    printf("Add student successfully!\n");
}

void updateStudent(Student **students, int count) {
    int id, found = 0;
    printf("Enter ID Student to update: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (students[i]->id == id) {
            found = 1;
            printf("Enter name: ");
            getchar();
            fgets(students[i]->name, NAME_LENGTH, stdin);
            students[i]->name[strcspn(students[i]->name, "\n")] = '\0';
            
            printf("Update age:");
            scanf("%d", &students[i]->age);
            printf("Update successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Not found student has ID %d.\n", id);
    }
}

void deleteStudent(Student **students, int *count) {
    int id, found = 0;
    printf("Enter ID student to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < *count; i++) {
        if (students[i]->id == id) {
            found = 1;
            free(students[i]);
            for (int j = i; j < *count - 1; j++) {
                students[j] = students[j + 1];
            }
            (*count)--;
            printf("Delete successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Not found student has ID %d.\n", id);
    }
}

void displayStudents(Student **students, int count) {
    if (count == 0) {
        printf("List Student empty!\n");
        return;
    }

    printf("\nList Student:\n");
    printf("ID\tName\t\tAge\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t\t%d\n", students[i]->id, students[i]->name, students[i]->age);
    }
}



int main() {
    Student *students[MAX_STUDENTS];
    int count = 0;
    int choice;

    do {
        printf("\n=== MENU ===\n");
        printf("1. Add Student\n");
        printf("2. Update information Student\n");
        printf("3. Delete Student\n");
        printf("4. Show list student\n");
        printf("0. Exit!\n");
        printf("Chose: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                updateStudent(students, count);
                break;
            case 3:
                deleteStudent(students, &count);
                break;
            case 4:
                displayStudents(students, count);
                break;
            case 0:
                printf("Exit.\n");
                break;
            default:
                printf("Not valid!\n");
        }
    } while (choice != 0);

    // Giải phóng bộ nhớ
    for (int i = 0; i < count; i++) {
        free(students[i]);
    }

    return 0;
}
