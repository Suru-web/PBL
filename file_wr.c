#include<stdio.h>
#include<stdlib.h>
int main()
{
    int num;
    FILE *fptr;
    fptr = fopen("C:\\Coding\\PROJECTS\\PBL\\numadd.txt","a");
    printf("Enter a number :\t");
    scanf("%d",&num);
    fprintf(fptr,"\n%d",num);
    fclose(fptr);
}