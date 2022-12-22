#include <stdio.h>
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
    };
    FILE *ptrr;
    ptrr = fopen("/home/suraj/Coding/PBL/Details/demo.txt", "r");
    struct student n1;
    char name1;
    fread(&n1, sizeof(struct student1), 1, ptrr);
    printf("%s\n", n1.name);
    fclose(ptrr);
}