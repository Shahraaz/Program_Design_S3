#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char str1[30] = "Enter your choice";
char str2[30] = "Enter Name";
char str3[30] = "Salary";
char str4[30] = "Work per day(in hours)";
struct Node{
    int salary;
    int work_time ;
    char Name[50];
};
struct Node Head[20] = {0,0,'/0'} ;
int NumberOfRecords;
void DispayNONINcrement()
{
    int counter = 0,i;
    printf("%-15s %-16s %-5s\n",str2,str3,str4);  
    if(NumberOfRecords==0)
    {
        printf("-----Nothing_To_Show-----");
        return;  
    }
    for(i=0;i<=NumberOfRecords;i++)
    {
        if(Head[i].work_time!=8&Head[i].work_time!=10&Head[i].work_time<12)
        {
            printf("%-15s %-16d %-5d\n",Head[i].Name,Head[i].salary,Head[i].work_time);
            counter = 1 ;
        }
    }
    if(counter==0) printf("-----Nothing_To_Show-----");
}
void DispayEverything()
{
    struct Node* temp = Head;
    printf("%-15s %-16s %-5s\n",str2,str3,str4);  
    if(temp==NULL)
    {
        printf("-----Nothing_To_Show-----");
        return;  
    }
    while(temp!=NULL)
    {
        printf("%-15s %-16s %-5d\n",temp->Name,temp->AccountNO,temp->Balance);
        temp = temp->next;
    }
}
void Dispaygreaterthan1000()
{
    int counter=1;
    struct Node* temp = Head;
    printf("%-15s %-16s %-5s\n",str2,str3,str4);
    if(temp==NULL)
    {
        printf("-----Nothing_To_Show-----");
        return;  
    }
    while(temp!=NULL)
    {
        if(temp->Balance>1000)
        {
            printf("%-15s %-16s %-5d\n",temp->Name,temp->AccountNO,temp->Balance);
            counter = 1; 
        }
        temp = temp->next;
    }
    if(counter==0) printf("-----Nothing_To_Show-----");
}
void Insert()
{
    int i,choice=1;
    printf("%-30s",str2);
    char ch;
    while((ch=getc(stdin))=='\n');
    (Head[NumberOfRecords]).Name[0] = ch;
    scanf("%[^\n]s",&(Head[NumberOfRecords].Name[1]));
    printf("%-30s",str3);
    do
    {
        scanf("%d",&(Head[NumberOfRecords]).salary);
        if(Head[NumberOfRecords].salary<0)
        {
            printf("Warning : Salary is negetive!!\n");
            printf("Will that person pay you\n");
            printf("(1) For Yes\n");
            printf("(2) For No \n");
            printf("%-30s",str1);
            scanf("%d",&choice);
        }    
    }while(choice!=1);
    choice = 1;
    do
    {
        printf("%-30s",str4);
        scanf("%d",&Head[NumberOfRecords].work_time);
        if(Head[NumberOfRecords].work_time<0)
        {
            printf("Warning : worktime is negetive!!\n");
            printf("Enter Again\n");
        }
    }while(Head[NumberOfRecords].work_time<0);
    NumberOfRecords++;
}
int main()
{
    NumberOfRecords = 0; ;
    printf("(1) Add an employee record.\n");
    printf("(2) Display the details of all the employees who did not get any increment in salary.\n");
    printf("(3) Display the details of all the employees with their final salaries.\n");
    printf("(4) Display the details of all the employees, given work per day(in hours).\n");
    printf("(5) Exit.\n");
    int choice;
    while(1)
    {
        printf("%-30s",str1);
        scanf("%d",&choice);
        if(choice==1)
            Insert();
        else if(choice==2)
            DispayNONINcrement();
        else if(choice==3)
            Dispaygreaterthan1000();
        else if(choice==4)
            DispayEverything();
        else if(choice==5)break;
        else printf("---Invalid Choice---");
        printf("\n");
    }
    return 0;
}