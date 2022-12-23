#include <stdio.h>
#include <string.h>
int main()
{
    struct student
    {
        int age;
        char name[20];
    } n;
    FILE *ptr;
    ptr = fopen("/home/suraj/Coding/PBL/Details/demo.txt", "a");
    printf("enter your name and age\n");
    scanf("%s", n.name);
    scanf("%d", &n.age);
    fprintf(ptr, "%s %d\n", n.name, n.age);
    fclose(ptr);

    struct student1
    {
        int age;
        char name[20];
    } n1;
    FILE *ptrr;
    ptrr = fopen("/home/suraj/Coding/PBL/Details/demo.txt", "r");

    char name1[100];
    int age1;
    // fread(&n1.name, sizeof(n1.name), 1, ptrr);
    // fread(&n1.age, sizeof(n1.age), 1, ptrr);
    //  printf("%s\n", n1.name);
    //  printf("%d\n", n1.age);
    for (int i = 0; i < 1; i++)
    {
        fscanf(ptrr, "%s\n", n1.name);
        fscanf(ptrr, "%d\n", &n1.age);
        // printf("%s", n1.name);
        // printf("%d\n", n1.age);
        // printf("%d\n", name1);
    }
    printf("%d\n", n1.age);
    printf("%s\n", n1.name);

    printf("Enter your name :\t");
    scanf("%s", name1);
    printf("\n%s\n", name1);
    printf("Enter your age :\t");
    scanf("%d", &age1);
    for (int i = 0; i < 1; i++)
    {
        if (strcmp(n1.name, name1) == 0)
        {
            printf("\nTrue\n");
        }
        else
            printf("Error\n");
    }

    fclose(ptrr);
}