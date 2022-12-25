#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX 100
int askHiree();
int wplace();
int hireeRegister();
int loginWithID();
int idGenerator();
int checkInfoHiree();
int askHirer();
int hirerRegister();
int hirerLogin();
void after_Hirer_login(int logResult, char hirer_name[], int hirer_age, char hemail[], char hpassword[]);

struct hireeInfo
{
    int age;
    char name[20];
    char gender[1];
    int uid;
    char skill[20];
};
struct hirerInfo
{
    int age;
    char name[20];
    char gender[1];
    char email[30];
    char password[20];
};
struct hirerLogin
{
    char name[20];
    int age;
    char email[30];
    char password[20];
} hlogin;

int main()
{
    printf("Hi there, Welcome to Our Program.\nWe can provide a platform for both hiree and hirer with the help of our program\n");
    printf("Please select What you want to do in our program :\n");
    printf("1 - If you are a Hirer \t 2 - If you are Hiree\n");
    int n;
    scanf("%d", &n);
    switch (n)
    {
    case 1:
        askHirer();
        break;

    case 2:
        askHiree();

        break;
    default:
        printf("Invalid choice, Please enter a valid option\n\n");
    }
}

int idGenerator()
{
    time_t t;
    srand(time(&t));
    int id = rand() % 1111 + 9999;
    return (id);
}

int askHiree()
{
    printf("\nSelect the options : 1) Register New user  2) Login with ID :\t");
    int ch;
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        wplace();
        break;

    case 2:
        // checkInfoHiree();
        printf("\nWe are working on login part\n");
        break;

    default:
        printf("\nEnter Valid choice please");
        break;
    }
}

int askHirer()
{
    int op;
    printf("\nSelect an option : 1) Register 2) Login\n");
    scanf("%d", &op);
    switch (op)
    {
    case 1:
        hirerRegister();
        break;

    case 2:
        hirerLogin();
        // printf("\nWe are working on login part\n");
        break;
    default:
        printf("\nInvalid Choice");
    }
}

int wplace()
{
    char ans;
    printf("We only hire people who can work in Bengaluru. Type Y if you agree or else Type N\n");
    scanf("%s", &ans);
    if (ans == 'y' || ans == 'Y')
    {
        hireeRegister();
    }
    else
    {
        printf("There is no work apart from Bengaluru right now, We will expand our work place soon, Please check again later !!\n\n");
    }
}

int hireeRegister()
{
    int id, ch;
    char skill[20];
    struct hireeInfo hi;

    // Storing data in structures :

    printf("\nEnter the details of applicant\n");
    printf("\nEnter Your name : \t");
    scanf("%s", &hi.name);
    printf("\nEnter Your age :\t");
    scanf("%d", &hi.age);
    printf("\nEnter Your gender (M/F/O):\t");
    scanf("%s", &hi.gender);
    id = idGenerator();
    hi.uid = id;

    printf("\nSelect your skill :\n");
    printf("1.Driving\t2.Cooking\t3.Construction\t4.Cleaning\t5.Beautician\t6.Enter your own skill set\n");
    scanf("%d", &ch);

    switch (ch)
    {
    case 1:
        strcpy(skill, "Driving");
        break;

    case 2:
        strcpy(skill, "Cooking");

        break;

    case 3:
        strcpy(skill, "Construction");

        break;

    case 4:
        strcpy(skill, "Cleaning");

        break;

    case 5:
        strcpy(skill, "Beautician");

        break;

    case 6:
        scanf("%s", &skill);
        break;

    default:
        printf("Invalid choice");
        break;
    }
    strcpy(hi.skill, skill);

    // Displaying the details

    printf("\nName : %s, Age : %d, Gender : %s, ID : %d, Skill : %s\n", hi.name, hi.age, hi.gender, hi.uid, hi.skill);

    FILE *hireedetails;
    hireedetails = fopen("/home/suraj/Coding/PBL/Details/hiree.txt", "a");
    fprintf(hireedetails, "%s %d %s %d %s\n", hi.name, hi.age, hi.gender, hi.uid, hi.skill);
    fclose(hireedetails);
}

int hirerRegister()
{
    struct hirerInfo hr;
    printf("Enter the details :\n");
    printf("Name :\t");
    scanf("%s", &hr.name);
    printf("Age :\t");
    scanf("%d", &hr.age);
    printf("Email :\t");
    scanf("%s", &hr.email);
    printf("Password :\t");
    scanf("%s", &hr.password);
    FILE *hirerDetails;
    hirerDetails = fopen("/home/suraj/Coding/PBL/Details/hirer.txt", "a");
    fprintf(hirerDetails, "%s %d %s %s\n", hr.name, hr.age, hr.email, hr.password);
    fclose(hirerDetails);
    int ch;
    printf("Select the category you wish to hire from :\n");
    // printf("1.Driving\t2.Cooking\t3.Construction\t4.Cleaning\t5.Beautician\n");
    // scanf("%d", &ch);
}

int hirerLogin()
{
    char hemail[30], hpassword[20];
    int logResult;
    FILE *ptr;
    ptr = fopen("/home/suraj/Coding/PBL/Details/hirer.txt", "r");
    char hirer_name[20];
    int hirer_age;
    fscanf(ptr, "%s", hirer_name);
    fscanf(ptr, "%d", &hirer_age);
    fscanf(ptr, "%s", hlogin.email);
    fscanf(ptr, "%s", hlogin.password);
    printf("%s, %s\n", hlogin.email, hlogin.password);
    printf("Enter Your Details to login :\n");
    printf("Email :\t");
    scanf("%s", hemail);
    printf("Password :\t");
    scanf("%s", hpassword);
    if ((strcmp(hlogin.email, hemail) == 0) && (strcmp(hlogin.password, hpassword) == 0))
    {
        logResult = 1;
        printf("\nLogin Successfull\n");
        after_Hirer_login(logResult, hirer_name, hirer_age, hemail, hpassword);
    }
    else
    {
        logResult = 0;
        printf("\nWrong Credentials, Try again \n");
    }
}

void after_Hirer_login(int logResult, char hirer_name[], int hirer_age, char hemail[], char hpassword[]);
{
    printf("What do you want to do after loging in :\n");
    printf("1.Display Account info\t2. Update Account\t3. Hire Applicants")
}