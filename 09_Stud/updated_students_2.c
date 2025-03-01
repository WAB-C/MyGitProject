#include <stdio.h>
struct Student {
    int id;
    char name[50];
    float grade;
};
void printStudents(struct Student students[], int count) {
    printf("List of students:\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d, Name: %s\n, Grade: %.2f\n", students[i].id, students[i].name, students[i].grade);
    }
}
void findStudentById(struct Student students[], int count, int id) {
    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            printf("Student found: ID: %d, Name: %s\n, Grade: %.2f\n", students[i].id, students[i].name, students[i].grade);
            return;
        }
    }
    printf("Student with ID %d not found.\n", id);
}
void findAverageGrade(struct Student students[],int  f_count) {
	float sum;
	float res;
	for (int i = 0; i < f_count; i++) {
		sum += students[i].grade;
	}
	res = sum/(float)f_count;
	printf("Average grade in class: %.2f\n", res);
	return;
}
int main() {
    struct Student students[5] = {
        {1, "John Doe", 5.0},
        {2, "Jane Smith", 4.0},
        {3, "Alice Johnson", 3.0},
	{4, "Kasul Rusnuyarov", 5.0},
	{5, "Jleb Guravlev", 2.0}
    };
    int f_count = sizeof(students)/sizeof(students[0]);
    printStudents(students, 5);
    int searchId;
    printf("Average grade: \n")
    findAverageGrade(students, f_count);
    printf("Enter student ID to search: ");
    scanf("%d", &searchId);
    findStudentById(students, 5, searchId);
    return 0;
}

