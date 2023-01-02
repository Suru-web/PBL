#include <stdio.h>
#include <string.h>
#include <string.h>
#define MAX 50
struct hireeLogin
{
    int age;
    char name[20];
    char gender[1];
    int uid;
    char skill[20];
    long long int phno;
} hiree_info_check[MAX];
int main()
{
    int linec = 0, tell, line_no = 0;
    char name[15];
    printf("\nEnter name to search\n");
    scanf("%s", name);
    FILE *ptrr;
    ptrr = fopen("/home/suraj/Coding/PBL/Details/hiree.txt", "r");
    if (ptrr == NULL)
    {
        printf("\nFile did not open\n");
    }
    char c;
    c = fgetc(ptrr);
    while (c != EOF)
    {
        if (c == '\n')
        {
            linec++;
        }
        c = fgetc(ptrr);
    }
    rewind(ptrr);
    for (int i = 0; i < linec; i++)
    {
        fscanf(ptrr, "%s", hiree_info_check[i].name);
        fscanf(ptrr, "%d", &hiree_info_check[i].age);
        fscanf(ptrr, "%s", hiree_info_check[i].gender);
        fscanf(ptrr, "%d", &hiree_info_check[i].uid);
        fscanf(ptrr, "%s", hiree_info_check[i].skill);
        fscanf(ptrr, "%lld", &hiree_info_check[i].phno);
        printf("Name : %s, Age : %d, Gender : %s, Contact Number : %lld\n", hiree_info_check[i].name, hiree_info_check[i].age, hiree_info_check[i].gender, hiree_info_check[i].phno);
        line_no++;
        if (strcmp(hiree_info_check[i].name, name) == 0)
        {
            printf("\nTrue\n");
            break;
        }
    }
    tell = ftell(ptrr);
    fclose(ptrr);

    printf("Number of lines : %d", line_no);
    printf("\nNumber of Characters : %d\n", tell);
}