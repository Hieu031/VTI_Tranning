#include <stdio.h>

#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float score;
} Student;

int main() {
    FILE *file;
    Student students[MAX_STUDENTS];
    int student_count = 0;

    // Mở file ở chế độ đọc
    file = fopen("students.txt", "r");
    if (file == NULL) {
        printf("can't open!\n");
        return 1;
    }

    // Đọc dữ liệu từ file
    while (fscanf(file, "%49s %f", students[student_count].name, &students[student_count].score) == 2) {
        student_count++;
        if (student_count >= MAX_STUDENTS) {
            printf("List full!\n");
            break;
        }
    }

    // Đóng file
    fclose(file);

    // In dữ liệu đã đọc
    printf("List students:\n");
    for (int i = 0; i < student_count; i++) {
        printf("Name: %s, Score: %.2f\n", students[i].name, students[i].score);
    }

    return 0;
}
