#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX 100
int askHiree();                                                                                           // Asks if the user wants to register or login
int askHirer();                                                                                           // Asks if the user wants to register or login
int wplace();                                                                                             // Asks for workplace of the Applicant
int hireeRegister();                                                                                      // Fills in all the details of the Applicant
int hirerRegister();                                                                                      // Fills in all the details of the Hirer
int idGenerator();                                                                                        // Generates Random ID for Applicant
int hirerLogin();                                                                                         // Login Validation part for Hirer
int hireeLogin();                                                                                         // Login validation part for Applicant
void after_Hirer_login(int logResult, char hirer_name[], int hirer_age, char hemail[], char hpassword[]); // Post login process
void hire_skill(char skill[]);                                                                            // Filtering Applicants based on skills
int overwritting();                                                                                       // Writting the updated values

struct hireeInfo
{
    int age;
    char name[20];
    char gender[1];
    int uid;
    char skill[20];
    long long int phno;
};

struct hireeInfoCheck
{
    int age;
    char name[20];
    char gender[1];
    int uid;
    char skill[20];
    long long int phno;
} hiree_info_check[MAX];

struct hireeLogin
{
    int age;
    char name[20];
    char gender[1];
    int uid;
    char skill[20];
    long long int phno;
} hiree_login[MAX];

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
} hlogin[MAX];

int main()
{
    printf("\t\t\t\t\t\t\t\tHi there, Welcome to Our Program.\n\t\t\t\t\tWe can provide a platform for both hiree and hirer with the help of our program\n\n\n");
    printf("Please select What you want to do in our program :\n");
    printf("1 - If you are a Hirer\t\t2 - If you are Hiree\n");
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
        hireeLogin();
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
    scanf("%s", hi.name);
    printf("\nEnter Your age :\t");
    scanf("%d", &hi.age);
    printf("\nEnter Your gender (M/F/O):\t");
    scanf("%s", hi.gender);
    printf("\nEnter your phone number :\t");
    scanf("%lld", &hi.phno);
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
        scanf("%s", skill);
        break;

    default:
        printf("Invalid choice");
        break;
    }
    strcpy(hi.skill, skill);

    // Displaying the details

    printf("\nName : %s, Age : %d, Gender : %s, ID : %d, Skill : %s, Phone number : %lld\n", hi.name, hi.age, hi.gender, hi.uid, hi.skill, hi.phno);

    FILE *hireedetails;
    hireedetails = fopen("hiree.txt", "a");
    fprintf(hireedetails, "%s %d %s %d %s %lld\n", hi.name, hi.age, hi.gender, hi.uid, hi.skill, hi.phno);
    fclose(hireedetails);
}

int hirerRegister()
{
    struct hirerInfo hr;
    printf("Enter the details :\n");
    printf("Name :\t");
    scanf("%s", hr.name);
    printf("Age :\t");
    scanf("%d", &hr.age);
    printf("Email :\t");
    scanf("%s", hr.email);
    printf("Password :\t");
    scanf("%s", hr.password);
    FILE *hirerDetails;
    hirerDetails = fopen("hirer.txt", "a");
    fprintf(hirerDetails, "Hii");
    fprintf(hirerDetails, "%s %d %s %s\n", hr.name, hr.age, hr.email, hr.password);
    fclose(hirerDetails);
    printf("\nYou are successfully registered now, Thank you\n");
}

int hirerLogin()
{
    char hemail[30], hpassword[20];
    int logResult = 0;
    FILE *ptr;
    ptr = fopen("hirer.txt", "r");
    char hirer_name[20];
    int hirer_age;

    char chr;
    int lineCount = 0;
    chr = fgetc(ptr);
    while (chr != EOF)
    {
        if (chr == '\n')
        {
            lineCount++;
        }
        chr = fgetc(ptr);
    }
    rewind(ptr);
    for (int i = 0; i < lineCount; i++)
    {
        fscanf(ptr, "%s", hlogin[i].name);
        fscanf(ptr, "%d", &hlogin[i].age);
        fscanf(ptr, "%s", hlogin[i].email);
        fscanf(ptr, "%s", hlogin[i].password);
    }

    printf("Enter Your Details to login :\n");
    printf("Email :\t");
    scanf("%s", hemail);
    printf("Password : ");
    scanf("%s", hpassword);

    for (int i = 0; i < lineCount; i++)
    {
        if ((strcmp(hlogin[i].email, hemail) == 0) && (strcmp(hlogin[i].password, hpassword) == 0))
        {
            logResult = 1;
            strcpy(hirer_name, hlogin[i].name);
            hirer_age = hlogin[i].age;
            break;
        }
        else
        {
            logResult = 0;
        }
    }
    printf("%d", logResult);
    if (logResult == 1)
    {
        printf("\nLogin Successfull\n\n");
        after_Hirer_login(logResult, hirer_name, hirer_age, hemail, hpassword);
    }
    else
    {
        logResult = 0;
        printf("\nWrong Credentials, Try again \n");
    }
}

void after_Hirer_login(int logResult, char hirer_name[], int hirer_age, char hemail[], char hpassword[])
{
    int ch;
    int choice_skill;
    char skill[MAX];
    printf("What do you want to do after loging in :\n");
    printf("1.Display Account info\t2. Hire Applicants :\t");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        printf("Your Details are :\n");
        printf("Name     :\t%s\n", hirer_name);
        printf("Age      :\t%d\n", hirer_age);
        printf("Email    :\t%s\n", hemail);
        break;

    case 2:
        printf("Select the skill on which you want to contact the hirer :)\n");
        printf("\n1.Driving\t2.Cooking\t3.Construction\t4.Cleaning\t5.Beautician\t6.Enter your own skill set\t");
        scanf("%d", &choice_skill);
        printf("\n");
        switch (choice_skill)
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
            scanf("%s", skill);
            break;

        default:
            printf("Invalid choice\n");
            break;
        }
        hire_skill(skill);
    }
}

void hire_skill(char skill[])
{
    int linec = 0;
    FILE *p;
    p = fopen("hiree.txt", "r");
    if (p == NULL)
    {
        printf("\nFile did not open\n");
    }

    char c;
    c = fgetc(p);
    while (c != EOF)
    {
        if (c == '\n')
        {
            linec++;
        }
        c = fgetc(p);
    }
    fclose(p);

    FILE *ptrr;
    ptrr = fopen("hiree.txt", "r");
    if (ptrr == NULL)
    {
        printf("\nFile did not open\n");
    }
    rewind(ptrr);
    printf("Here is the list of all the applicants with %s skill :\n\n", skill);
    for (int i = 0; i < linec; i++)
    {
        fscanf(ptrr, "%s", hiree_info_check[i].name);
        fscanf(ptrr, "%d", &hiree_info_check[i].age);
        fscanf(ptrr, "%s", hiree_info_check[i].gender);
        fscanf(ptrr, "%d", &hiree_info_check[i].uid);
        fscanf(ptrr, "%s", hiree_info_check[i].skill);
        fscanf(ptrr, "%lld", &hiree_info_check[i].phno);

        if (strcmp(skill, hiree_info_check[i].skill) == 0)
        {
            printf("Name : %s, Age : %d, Gender : %s, Contact Number : %lld\n", hiree_info_check[i].name, hiree_info_check[i].age, hiree_info_check[i].gender, hiree_info_check[i].phno);
        }
    }
    printf("\nYou can contact the applicant now using their number.\nThank you for using our application :)\n\n");
    fclose(ptrr);
}

int hireeLogin()
{
    FILE *p;
    p = fopen("hiree.txt", "r");
    char name[20], c, newSkill[15];
    int uid, lines = 0, result, j, ch1, ch2;
    int newAge;
    long long int phno;
    printf("Enter the details to login -\n");
    printf("Name      :\t");
    scanf("%s", name);
    printf("Unique ID :\t");
    scanf("%d", &uid);
    printf("Phone no. :\t");
    scanf("%lld", &phno);
    c = fgetc(p);
    while (c != EOF)
    {
        if (c == '\n')
        {
            lines++;
        }
        c = fgetc(p);
    }
    rewind(p);
    for (int i = 0; i < lines; i++)
    {
        fscanf(p, "%s", hiree_login[i].name);
        fscanf(p, "%d", &hiree_login[i].age);
        fscanf(p, "%s", hiree_login[i].gender);
        fscanf(p, "%d", &hiree_login[i].uid);
        fscanf(p, "%s", hiree_login[i].skill);
        fscanf(p, "%lld", &hiree_login[i].phno);

        if ((strcmp(name, hiree_login[i].name) == 0) && (uid == hiree_login[i].uid) && (phno == hiree_login[i].phno))
        {
            j = i;
            result = 1;
            break;
        }
        else
            result = 0;
    }
    fclose(p);
    if (result == 1)
    {
        printf("\nLogin Successfull\n\n");
        printf("Select any one choice -\t1.Display My Details\t");
        scanf("%d", &ch1);
        switch (ch1)
        {
        case 1:
            printf("\nName\t   :\t%s", hiree_login[j].name);
            printf("\nAge\t   :\t%d", hiree_login[j].age);
            printf("\nGender\t   :\t%s", hiree_login[j].gender);
            printf("\nUnique ID  :\t%d", hiree_login[j].uid);
            printf("\nSkill\t   :\t%s", hiree_login[j].skill);
            printf("\nPhone no   :\t%lld\n", hiree_login[j].phno);
            break;

            // case 2:
            //     printf("What do you want to update?\n 1-Age\t\t2-Skill\t\t3.Phone number\t\t");
            //     scanf("%d", &ch2);
            //     if (ch2 == 1)
            //     {
            //         printf("Enter your new age :\t");
            //         scanf("%d", &newAge);
            //         hiree_login[j].age = newAge;
            //         printf("\nNew updated Details are :\n");
            //         printf("\nName\t   :\t%s", hiree_login[j].name);
            //         printf("\nAge\t   :\t%d", hiree_login[j].age);
            //         printf("\nGender\t   :\t%s", hiree_login[j].gender);
            //         printf("\nUnique ID  :\t%d", hiree_login[j].uid);
            //         printf("\nSkill\t   :\t%s", hiree_login[j].skill);
            //         printf("\nPhone no   :\t%lld\n", hiree_login[j].phno);
            //     }
            //     else if (ch2 == 2)
            //     {
            //         printf("\nEnter your new skill\n");
            //         scanf("%s", newSkill);
            //         strcpy(hiree_login[j].skill, newSkill);
            //         printf("\nNew updated Details are :\n");
            //         printf("\nName\t   :\t%s", hiree_login[j].name);
            //         printf("\nAge\t   :\t%d", hiree_login[j].age);
            //         printf("\nGender\t   :\t%s", hiree_login[j].gender);
            //         printf("\nUnique ID  :\t%d", hiree_login[j].uid);
            //         printf("\nSkill\t   :\t%s", hiree_login[j].skill);
            //         printf("\nPhone no   :\t%lld\n", hiree_login[j].phno);
            //     }
            //     else if (ch2 == 3)
            //     {
            //         printf("\nEnter your new phone number :\n");
            //         long long int newPhNo;
            //         scanf("%lld", &newPhNo);
            //         hiree_login[j].phno = newPhNo;
            //         printf("\nNew updated Details are :\n");
            //         printf("\nName\t   :\t%s", hiree_login[j].name);
            //         printf("\nAge\t   :\t%d", hiree_login[j].age);
            //         printf("\nGender\t   :\t%s", hiree_login[j].gender);
            //         printf("\nUnique ID  :\t%d", hiree_login[j].uid);
            //         printf("\nSkill\t   :\t%s", hiree_login[j].skill);
            //         printf("\nPhone no   :\t%lld\n", hiree_login[j].phno);
            //     }
        }
    }
    else
        printf("\nInvalid Credentials, Try again\n");
    printf("\nProgram Ending\n\n");
}
