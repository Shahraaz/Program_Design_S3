#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* next;
} Node;
Node *Head=NULL;
void push_down(int data){
    Node *newNode = (Node*)malloc(sizeof(Node)),*it=Head;
    newNode->data = data;
    newNode->next = NULL;
    if(!Head){
        Head = newNode;
        return;
    }
    while(it->next)
        it = it->next;
    it->next = newNode;
    return ;
}
void Reverse(){
    if(!Head)
        return;
    Node *it=Head,*next=Head->next,*prev=NULL;
    while(it){     
        next = it->next;
        it->next = prev;
        prev = it;
        it = next;
    }
    Head = prev;
    return ;
}
int main(){
    int n,i,flag=0,data,temp,nodecount=1;
    printf("%-36s","Enter the value of n");
    scanf("%d",&n);
    if(n<0){
        printf("Cannot have negtive number of nodes\n");
        exit(0);
    }
    printf("%-36s","Enter the elements");
    for(i=0;i<n;i++){
        scanf("%d",&data);
        push_down(data);
    }
    printf("%-36s","Enter the element to be searched");
    scanf("%d",&temp);
    Node *it=Head;
    while(it){
        if(it->data==temp){
        printf("%-36s %d ","Element found at node",nodecount);
        flag = 1;
        break;
        }
        it = it->next;
        nodecount++;
    }
    if(!flag)
        printf("Integer Not Found\n");
    return 0;
}