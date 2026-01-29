#include<stdio.h>
#include<string.h>

#define MAX_STUDENTS 50
#define MAX_NAME_LENGTH 50

struct Student {
    char name[MAX_NAME_LENGTH];
    int rNumber;
    int marks;
};

void displayStudent(struct Student student) {
    printf("Name: %s\n", student.name);
    printf("R Number: %d\n", student.rNumber);
    printf("Marks: %d\n", student.marks);
    printf("\n");
}

int addStudent(struct Student students[], int numStudents, char name[], int rNumber, int marks) {
    if (numStudents < MAX_STUDENTS) {
        struct Student newStudent;
        strncpy(newStudent.name, name, sizeof(newStudent.name) - 1);
        newStudent.name[sizeof(newStudent.name) - 1] = '\0';
        newStudent.rNumber = rNumber;
        newStudent.marks = marks;

        students[numStudents] = newStudent;
        return numStudents + 1;
    } else {
        printf("Error: Maximum number of students reached. Cannot add more students.\n");
        return numStudents;
    }
}

int main() {
    struct Student students[MAX_STUDENTS];
    int numStudents = 0;

    // Example usage
    numStudents = addStudent(students, numStudents, "John Doe", 101, 85);
    numStudents = addStudent(students, numStudents, "Jane Smith", 102, 92);

    printf("Student Records:\n");
    for (int i = 0; i < numStudents; i++) {
        displayStudent(students[i]);
    }

    return 0;
}
