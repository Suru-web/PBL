#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    time_t t1;
    srand(time(&t1));
    int n = rand() % 10000 + 99999;
    printf("%d",n);
}