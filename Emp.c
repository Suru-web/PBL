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

struct hireeInfo
{
    int age;
    char name[20];
    char gender[1];
    int uid;
};
struct hirerInfo
{
    int age;
    char name[20];
    char gender[1];
    char email[30];
    char password[20];
};

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
        checkInfoHiree();
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
    printf("Hello");
    int count, id;
    printf("\nEnter the number of applications you want to fill : \t");
    scanf("%d", &count);
    struct hireeInfo hi[count];
    // Storing data in structures :

    for (int i = 0; i < count; i++)
    {
        printf("\nEnter the details of applicant %d\n", i + 1);
        printf("\nEnter Your name : \t");
        scanf("%s", &hi[i].name);
        printf("\nEnter Your age :\t");
        scanf("%d", &hi[i].age);
        printf("\nEnter Your gender (M/F/O):\t");
        scanf("%s", &hi[i].gender);
        id = idGenerator();
        hi[i].uid = id;
    }
    // Displaying the details
    for (int i = 0; i < count; i++)
    {
        printf("\nName : %s, Age : %d, Gender : %s, ID : %d", hi[i].name, hi[i].age, hi[i].gender, hi[i].uid);
    }
    FILE *hireedetails;
    hireedetails = fopen("C:\\Coding\\PROJECTS\\PBL\\Details\\hiree.txt", "a");
    for (int i = 0; i < count; i++)
    {
        fprintf(hireedetails, "%s %d %s %d\n", hi[i].name, hi[i].age, hi[i].gender, hi[i].uid);
    }

    fclose(hireedetails);
}

int hirerRegister()
{
    struct hirerInfo hr;
    // Storing data in structure
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
    hirerDetails = fopen("C:\\Coding\\PROJECTS\\PBL\\Details\\hirer.txt", "a");
    fprintf(hirerDetails, "%s %d %s %s\n", hr.name, hr.age, hr.email, hr.password);
    fclose(hirerDetails);
}
int hirerLogin()
{
    struct temp
    {
        int age;
        char name[20];
        char gender[1];
        char email[30];
        char password[20];
    } t1;

    struct hirerInfo hr[MAX];
    FILE *hirerDetails;
    hirerDetails = fopen("C:\\Coding\\PROJECTS\\PBL\\Details\\hirer.txt", "r");
    while (!feof(hirerDetails))
    {
        fseek(hirerDetails, sizeof(struct hirerInfo), SEEK_SET);
        fread(&hr, sizeof(struct hirerInfo), 1, hirerDetails);
        printf("%s", hr->name);
    }

    fclose(hirerDetails);
}

int checkInfoHiree()
{
    char name[20], getname[20];
    int uid, ide;
    printf("Enter your name :\t");
    scanf("%s", &name);
    printf("Enter your Unique ID :\t");
    scanf("%d", &uid);
    FILE *details;
    details = fopen("C:\\Coding\\PROJECTS\\PBL\\Details\\Hiree Details\\hiree.txt", "r");
    fscanf(details, "%s%d", &getname, &ide);
    printf("Got the value from the file, name = %s\t", getname); // Check this out

    fclose(details);
}
