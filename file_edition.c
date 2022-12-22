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
    scanf("%s", &n.name);
    scanf("%d", &n.age);
    fprintf(ptr, "%s %d", n.name, n.age);
    fclose(ptr);
    FILE *ptrr;
    ptrr = fopen("/home/suraj/Coding/PBL/Details/demo.txt", "r");
    struct student inp;
    // fread(&inp, "%*s", inp.name);
    fread(&inp, sizeof(struct student), 1, ptrr);
    printf("%s\t%d\n", inp.name, inp.age);
    fclose(ptrr);
}