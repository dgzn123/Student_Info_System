#include <stdio.h>
#include <string.h>
typedef struct
{
    char name[50];
    int age;
    float grade;
} Student;
void printStudentInfo(Student s)
{
    printf("Name: %s\n", s.name);
    printf("Age: %d\n", s.age);
    printf("Grade: %.2f\n", s.grade);
}
int main(void)
{
    Student class[30];
    char name[50];
    int age;
    float grade;
    int ID;
    int choice;
    printf("Welcome to the Student Information System.\n");
restart:
    printf("You want to check information or add new student? Press 0 for check, 1 for add. Press 2 to exit.\n");
    scanf("%d", &choice);
    getchar();
    if (choice == 0)
    {
        printf("Enter student's ID to check: \n");
        scanf("%d", &ID);
        getchar();
        if (ID < 0 || ID >= 30)
        {
            printf("Invalid ID. Please enter an ID between 0 and 29.\n");
            goto restart;
        }
        printStudentInfo(class[ID]);
        goto restart;
    }
    else if (choice == 1)
    {
        printf("Enter student's ID: \n");
        scanf("%d", &ID);
        getchar();
        if (ID < 0 || ID >= 30)
        {
            printf("Invalid ID. Please enter an ID between 0 and 29.\n");
            goto restart;
        }
        printf("Enter student's name: \n");
        fgets(class[ID].name, sizeof(class[ID].name), stdin);
        class[ID].name[strcspn(class[ID].name, "\n")] = '\0';
        printf("Enter student's age: \n");
        scanf("%d", &class[ID].age);
        getchar();
        printf("Enter student's grade: \n");
        scanf("%f", &class[ID].grade);
        getchar();
        printf("Student added successfully.\n");
        goto restart;
    }
    else if (choice == 2)
    {
        return 0;
    }
    else
    {
        printf("Invalid choice. Please try again.\n");
        goto restart;
    }
}