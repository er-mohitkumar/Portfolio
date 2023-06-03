//Employee management system

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

//template for employee record
struct employee
{
    int empid;
    char name[30];
    float salary;
};
typedef struct employee record;

//global variable
record emp;
FILE *fp = NULL;

//FUNCTION prototypes
void printLogo(void);
int password(char *);
void addRec(void);
void displayAll(void);
int countrec(void);
void searchByID(void);
void searchByName(void);
void deleteRec(void);
void updateRec(void);


int main()
{
    char ch;
    char choice;
    printLogo();

    //checking password
    printf("\t\t\tEnter Password");
    if(password("123abc") == 0 )
    {
        printf("\t\t\twrong password");
        getch();
        exit(0);
    }

    while(1)
    {
        system("cls");
        printLogo();
        printf("\t\t\tAvailable choices are:\n");
        printf("\t\t\t1. Add a New record in database\n");
        printf("\t\t\t2. Display all Record(s).\n");
        printf("\t\t\t3. count total Record(s).\n");
        printf("\t\t\t4. search a Record(s).\n");
        printf("\t\t\t5. Delete a Record(s).\n");
        printf("\t\t\t6. Update Record(s).\n");
        printf("\t\t\t7. Exit.\n\n");
        printf("\t\t\tPlease select a choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 :
                addRec();
                getch();
                break;

            case 2 :
                displayAll();
                getch();
                break;
            case 3:
                printf("\t\t\tTotal records: %d\n",countrec());
                getch();
                break;
            case 4:
            system("cls");

                printf("\t\t\tselect a choice\n");
                printf("\t\t\t1.search by id\n");
                printf("\t\t\t2.search by name.\n\n");
                printf("\t\t\tenter a choice: ");
                scanf("%d",&ch);
                switch(ch)
                {
                    case 1:
                        searchByID();
                        getch();
                        break;
                    case 2:
                        searchByName();
                        getch();
                        break;
                    default:
                        printf("\t\t\tWrong choice...");
                        getch();
                }
                getch();
                break;

            case 5:
                deleteRec();
                getch();
                break;  
            case 6:
                updateRec();
                getch();
                break;     


            case 7 :
                printf("\t\t\t Thanku For visit us.");
                getch();
                system("cls");
                exit(0);

            default :
                printf("\t\t\tThis Choice oi NOT available.");
                getch();

        }//end of the switch

    }//end of while
    return 0;
}

// FUNCTION definitions

void printLogo(void)
{
    system("cls");
    printf("\n\t\t\t\tEMPLOYEE MANAGEMENT SYSTEM\n");
    printf("\n\t\t--------------------------------------------------------------------\n");
    printf("\t\t\t\tPOORNIMA COLLEGE OF ENGINEERING\n");
    printf("\t\t\t\t\tSitapura, Jaipur\n");
    printf("\t\t---------------------------------------------------------------------\n");
}

int password(char  *p)
{
    char ch;
    int i, flag = 1;
    for(i =0; i < strlen(p); i++)
    {
        ch = getch();
        putchar('*');
        if( ch != p[i])
        {
                flag = 0;
        }
    }
    return flag;
}

void addRec(void)
{
    fp= fopen("database.bin","ab+");
    if(fp == NULL)
    {
        printf("\t\t\tFile opening error...\n");
        return;
    }
    fflush(stdin);
    printf("\t\t\tEnter Employee Name   : ");
    fgets(emp.name,29,stdin);
    printf("\t\t\tEnter Employee ID     :");
    scanf("%d",&emp.empid);
    printf("\t\t\tEnter Employee Salary :");
    scanf("%f",&emp.salary);

    fwrite ( &emp, sizeof(emp),1, fp);

    fclose(fp);
    printLogo();
    printf("\t\t\tRecord is Added Successfully.");
}

void displayAll(void)
{
     fp= fopen("database.bin","ab+");
    if(fp == NULL)
    {
        printf("\t\t\tFile opening error...\n");
        return;
    }
    while ( fread(&emp, sizeof(emp),1, fp) == 1)
    {
        printf("\t\t\tNAME  : %s",emp.name);
        printf("\t\t\tID    : %d\n",emp.empid);
        printf("\t\t\tSALARY: %.2f\n",emp.salary);
    }
    fclose(fp);
}

int countrec(void)
{
    int count=0;
    fp= fopen("database.bin","ab+");
    fseek(fp,0,2);
    count = ftell(fp)/sizeof(emp);
   // if(fp == NULL)
   // {
   //     printf("\t\t\tFile opening error...\n");
   //     return;
   // }
 //   while ( fread(&emp, sizeof(emp),1, fp) == 1)
 //   {
 //       count++;
 //   }
    fclose(fp);
    return count;
}

void searchByID(void)
{
    int id;
    printf("\t\t\tenter employee id:");
    scanf("%d",&id);
    fp= fopen("database.bin","ab+");
    if(fp == NULL)
    {
        printf("\t\t\tFile opening error...\n");
        return;
    }
    while ( fread(&emp, sizeof(emp),1, fp) == 1)
    {
        if(id == emp.empid)
        {
            printf("\t\t\tNAME  : %s",emp.name);
            printf("\t\t\tID    : %d\n",emp.empid);
            printf("\t\t\tSALARY: %.2f\n",emp.salary);
            fclose(fp);
            return;
        }
    }
    printf("\t\t\tThis record does not exist");
    fclose(fp);
}

void searchByName(void)
{
    char name[30];
    fflush(stdin);
    printf("\t\t\tenter employee name:");
    fgets(name,29,stdin);
    system("cls");
    printLogo();

    fp= fopen("database.bin","ab+");
    if(fp == NULL)
    {
        printf("\t\t\tFile opening error...\n");
        return;
    }
    while ( fread(&emp, sizeof(emp),1, fp) == 1)
    {
        if(strcmp(name,emp.name) == 0)
        {
            printf("\t\t\tNAME  : %s",emp.name);
            printf("\t\t\tID    : %d\n",emp.empid);
            printf("\t\t\tSALARY: %.2f\n",emp.salary);
            fclose(fp);
            return;
        }
    }
    printf("\t\t\tThis record does not exist");
    fclose(fp);
}

void deleteRec(void)
{
    int id;
    int flag = 0;
    FILE *tempf = fopen("temp.bin","wb+");
    fp = fopen("database.bin","rb");
    if(tempf == NULL || fp == NULL)
    {
      printf("\t\t\tFile opening error...\n");
        return;  
    }
    printf("\t\t\tEnter Employee id: ");
    scanf("%d",&id);
    while((fread (&emp, sizeof(emp),1,fp)) == 1)
    {
        if(emp.empid == id)
        {
            flag = 1;
            continue;
        }
        fwrite( &emp, sizeof(emp),1,tempf);
    }
    fclose(fp);
    fclose(tempf);
    system("cls");
    printLogo();
    //_fcloseall();
    if (flag == 1)
    {
    remove("database.bin");
    rename("temp.bin","database.bin");
    printf("\t\t\tRecord is Deleted.");
    }
    else
    {
        printf("\t\t\tRecord does not exist.");
        remove("temp.bin");
    }
}

void updateRec(void)
{
    int id;
    int flag = 0;
    FILE *tempf = fopen("temp.bin","wb+");
    fp = fopen("database.bin","rb");
    if(tempf == NULL || fp == NULL)
    {
      printf("\t\t\tFile opening error...\n");
        return;  
    }
    printf("\t\t\tEnter Employee id: ");
    scanf("%d",&id);
    while((fread (&emp, sizeof(emp),1,fp)) == 1)
    {
        if(emp.empid == id)
        {
            flag = 1;
            printf("\t\t\tEnter updated empid:");
            scanf("%d",&emp.empid);
            printf("Enter updated name :");
            fflush(stdin);
            fgets(emp.name,29,stdin);
            printf("\t\t\tEnter updated Salary :");
            scanf("%f",&emp.salary);
            fwrite(&emp, sizeof(emp),1,tempf);
            continue;
        }
        fwrite( &emp, sizeof(emp),1,tempf);
    }
    fclose(fp);
    fclose(tempf);
    system("cls");
    printLogo();
    //_fcloseall();
    if (flag == 1)
    {
    remove("database.bin");
    rename("temp.bin","database.bin");
    printf("\t\t\tRecord is Updated.");
    }
    else
    {
        printf("\t\t\tRecord does not exist.");
        remove("temp.bin");
    }
}