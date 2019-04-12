#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data ;
    struct Node* next;
};
struct Node* Head ;
void print()
{
    struct Node* temp = Head;
    while(temp!=NULL)
    {
        printf("%-2d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void Insert()
{
    int i ;
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)),*iterator;
    if(new_node==NULL)
    {
        printf("Out of memory\n");
        exit(0);
    }
    scanf("%d",&new_node->data);
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
    char str1[30] = "Enter the value of n";
    char str2[30] = "Enter the Element(s)";
    char str3[30] = "The Element(s) of the list";
    int i,n ;
    printf("%-30s",str1);
    scanf("%d",&n);
    if(n<0)
    {
        printf("Cannot have a list with negetive number of element(s)\n");
        exit(0);
    }
    if(n==0)
    {
        printf("%-30s----No_Elements----\n",str3);
        exit(0);
    }
    printf("%-30s",str2);
    for(i=0;i<n;i++)
        Insert();
    struct Node* iterator = Head,*temp;
  while(iterator->next!=NULL)
    {
        if((iterator->next)->data==iterator->data)
        {
            temp = iterator->next;
            iterator->next = temp->next;
            free(temp);
        }
        else
            iterator = iterator->next;
    }
    printf("%-30s",str3);
    print();
    return 0;
}