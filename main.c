#include <stdio.h>
#include <string.h>
#include <windows.h>
typedef struct
{
    char name[50];
    int age;
    float grade;
} Student;
void printStudentInfo(Student s)
{
    printf("姓名: %s\n", s.name);
    printf("年龄: %d\n", s.age);
    printf("成绩: %.2f\n", s.grade);
}
int main(void)
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    Student class[30];
    char name[50];
    int age;
    float grade;
    int ID;
    int choice;
    int number = 0;
    printf("欢迎来到学生档案管理系统\n");
restart:
    printf("您想查看信息还是添加新学生？按0查看，按1添加，按2查看当前档案信息，按3退出。\n");
    scanf("%d", &choice);
    getchar();
    if (choice == 0)
    {
        printf("请输入要查看的学生ID：\n");
        scanf("%d", &ID);
        getchar();
        if (ID < 0 || ID >= 30)
        {
            printf("无效的ID。请输入0到29之间的ID。\n");
            goto restart;
        }
        printStudentInfo(class[ID]);
        goto restart;
    }
    else if (choice == 1)
    {
        printf("请输入学生的ID：\n");
        scanf("%d", &ID);
        getchar();
        if (ID < 0 || ID >= 30)
        {
            printf("无效的ID。请输入0到29之间的ID。\n");
            goto restart;
        }
        printf("请输入学生的姓名：\n");
        fgets(class[ID].name, sizeof(class[ID].name), stdin);
        class[ID].name[strcspn(class[ID].name, "\n")] = '\0';
        printf("请输入学生的年龄：\n");
        scanf("%d", &class[ID].age);
        getchar();
        printf("请输入学生的成绩：\n");
        scanf("%f", &class[ID].grade);
        getchar();
        printf("学生添加成功。\n");
        number++;
        goto restart;
    }
    else if (choice == 2)
    {
        printf("当前学生档案信息：\n");
        for (int i = 0; i < number; i++)
        {
            if (strlen(class[i].name) > 0)
            {
                printf("ID: %d\n", i);
                printStudentInfo(class[i]);
                printf("---------------------\n");
            }
        }
        goto restart;
    }
    else if (choice == 3)
    {
        return 0;
    }
    else
    {
        printf("无效的选择。请再试一次。\n");
        goto restart;
    }
}