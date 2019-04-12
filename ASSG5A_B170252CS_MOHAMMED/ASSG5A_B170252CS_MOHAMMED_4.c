#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
} Node;
Node *stack = NULL;
int choice,n,top,x,i;
void push(int value){
    Node *newnode = malloc(sizeof(Node));
    newnode->data = value;
    newnode->next = stack; 
    stack = newnode;
}
void pop(){
    if(stack==NULL)
        printf("\nEMPTY");
    else{
        printf("\n%d",stack->data);
        stack = stack->next;
    }
}
void PRINT(){
    if(stack!=NULL){
        printf("\n");
        Node *it = stack;
        while(it){
            printf("%d ",it->data);
            it = it->next;
        }
    }
    else
        printf("\nEMPTY");
}
int main(){
    int check ;
    printf("\nSTACK OPERATIONS USING ARRAY");
    printf("\n1.PUSH\n2.POP\n3.PRINT\n4.EXIT\n");
    do{
        printf("\nEnter the operation to be performed:");
        scanf("%d",&choice);
        switch(choice){
            case 1:{
                printf("Enter the element to be inserted:");
                scanf("%d",&x);
                push(x);
                break;
            }
            case 2:{
                pop();
                break;
            }
            case 3:{
                PRINT();
                break;
            }
            case 4:{
                printf("\nEXIT POINT ");
                break;
            }
            default: printf ("\nPlease Enter a Valid Choice(1/2/3/4)");                 
        }
    }
    while(choice!=4);
    return 0;
}