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
int main(){
    int n,i,k,data;
    printf("%-26s","Enter the value of n");
    scanf("%d",&n);
    if(n<0){
        printf("Cannot have negive number of nodes\n");
        exit(0);
    }
    printf("%-26s","Enter the elements");
    for(i=0;i<n;i++){
        scanf("%d",&data);
        push_down(data);
    }
    printf("%-26s","Enter the value of k");
    scanf("%d",&k);
    if(k>n){
        printf("OverFlow k is greater than N");
        exit(0);
    }
    else if(k<=0){
        printf("UnderFlow k is lesser than 1");
        exit(0);
    }
    Node *it=Head;
    for(i=0;i<n-k;i++)
        it=it->next;
    printf("The %d element from the\n",k);
    printf("%-25s %d","end of the linked list is",it->data);
    return 0;
}