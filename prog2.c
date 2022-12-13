#include<stdio.h>
#include <stdlib.h>
int capacity=200;
char name[100];
int usn[100];
int finger_print[100];
int entered,attented,no_of_days=0;
float current_attendance;
int attended=0;
char cancelled_name[100];
int cancelled_usn;
int cancelled_finger_print;


void registration(int *top,char nname,int nusn,int nfinger_print)
{
    if(*top==capacity-1)
    {
        printf("reallocate the memory");
    }
        
        *top=*top+1;
        name[*top]= nname;
        usn[*top]=nusn;
        finger_print[*top]=nfinger_print;
        
    
   
}

void cancel_registration(int *top)
{
    cancelled_name=name[*top];
    cancelled_usn=usn[*top];
    cancelled_finger_print=finger_print[*top];
    *top=*top-1;
    printf("cancelled registration \n name = %s \n usn = %d \n finger print = %d \n",cancelled_name,cancelled_usn,cancelled_finger_print);
}

void attendance(int finger_print, int no_of_days)
{
    if(entered==finger_print)
    {
        attended++;
    }
    else
    {
        printf("student absent");
    }
    
    if(no_of_days%7==0)
    {
        int weekly_attendance=(attended/7)*100;
        printf("attendance for the week %d \n",weekly_attendance);

    }


    {
        if((no_of_days/30==0)||(no_of_days/31==0))
        {
            int monthly_attendance=(attended/30)*100;
             printf("attendance for the month %d \n",monthly_attendance);
        }
    }

    current_attendance=(((float)attended)/no_of_days)*100;
    printf("current attendance %f \n", current_attendance);
}

void check_attendance()
{
    if((current_attendance>=80.0)&&(current_attendance<=100.0))
    {
        printf("attendance %f \n",current_attendance);
        printf("eligible to take up exam");
    }
    else if((current_attendance>=75.0)&&(current_attendance<80.0))
    {
        printf("attendance %f \n",current_attendance);
        printf("eligible to take up exam");
    }
    else if((current_attendance<75.0))
    {
        printf("attendance %f \n", current_attendance);
        printf("student is not eligible to take up exams");
    }
}

void main()
{
    printf("registration of students into the attendance data \n");
    printf("enter the student name\n");
    scanf("%s",&name);
    printf("enter the USN \n");
    scanf("%d",&usn);
    printf("enter the finger_print \n"); //to mark attendance
    int top=-1;
    
    for( ; ; )
    {

    
        int choice;
        printf("select the choice as per ur choice \n 1. registration \n 2.cancel registration \n 3. give ur attendance \n 4.check ur attendance and eligibility for exams \n 5.exit");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:printf("enter ur name as per records");
                   scanf("%s",&name);
                   printf("enter ur usn \n");
                   scanf("%d",&usn);
                   printf("enter your finger print \n");
                   scanf("%d",&finger_print);
                   registration(&top,name,usn,finger_print);
                   break;

            case 2:cancel_registration(&top);
                   break;
            
            case 3://enter 1 for present(finger print given) and 0 for not present(finger print not given)
                   no_of_days++;
                   printf("enter the finger print");
                   scanf("%d",&finger_print);
                   check_attendance(finger_print,no_of_days);
                   break;
            
             case 4:check_attendance();
                   break;

            


       }

    }
}