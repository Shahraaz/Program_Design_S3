#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char str1[30] = "Enter your choice";
char str2[30] = "Name";
char str3[30] = "Account number";
char str4[30] = "Balance";
struct Node{
    char Name[50],AccountNO[20];
    int Balance ;
    struct Node* next;
};
struct Node* Head ;
void Dispaylessthan200()
{
    int counter = 0;
    struct Node* temp = Head;
    while(temp!=NULL)
    {
        if(temp->Balance<200)
        {
            printf("%s\n",temp->Name);
            counter = 1 ;
        }
        temp = temp->next;
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
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)),*iterator;
    if(new_node==NULL)
    {
        printf("Out of memory\n");
        exit(0);
    }
    printf("%-30s",str2);
    char ch;
    while((ch=getc(stdin))=='\n');
    new_node->Name[0] = ch;
    scanf("%[^\n]s",new_node->Name+1);
    printf("%-30s",str3);
    do
    {
        scanf("%s",new_node->AccountNO);
        if(strlen(new_node->AccountNO)!=5)
            printf("Account Number Should be of 5 Digits\n%-30s","Enter Acount Number Again");
    }while(strlen(new_node->AccountNO)!=5);
    do
    {
        printf("%-30s",str4);
        scanf("%d",&new_node->Balance);
        if(new_node->Balance<0)
        {
            printf("Warning : Account BAlance is negetive!!\n");
            printf("Do you want Negetive Balance in account\n");
            printf("(1) For Yes\n");
            printf("(2) For No \n");
            printf("%-30s",str1);
            scanf("%d",&choice);
        }
    }while(choice!=1);
    if(new_node->Balance>1000) new_node->Balance += 100 ;
    new_node->next = NULL;
    if(Head==NULL)
        Head = new_node;
    else{
    iterator = Head;
    while(iterator->next!=NULL)
        iterator = iterator->next;
    iterator->next = new_node;
    }
}
int main()
{
    Head = NULL ;
    printf("(1) Add a customer record.\n");
    printf("(2) Display the name of customers having balance less than 200.\n");
    printf("(3) Display the details of the customers whose balance amount got incremented.\n");
    printf("(4) Display the details of all the customers.\n");
    printf("(5) Exit.\n");
    int choice;
    while(1)
    {
        printf("%-30s",str1);
        scanf("%d",&choice);
        if(choice==1)
            Insert();
        else if(choice==2)
            Dispaylessthan200();
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