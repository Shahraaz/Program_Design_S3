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
int counter(int value){
    int counter=0;
    Node *it = Head;
    if(!it)
        return counter;
    while(it->next){
        if(it->data==value)
            counter++;
        it = it->next;
    }
    return counter;
}
int Modcounter(int value){
    int counter=0;
    Node *it = Head;
    if(!it)
        return counter;
    while(it){
        if(it->data==value){
            counter++;
            it->data = 0;
        }
        it = it->next;
    }
    return counter;
}
int main(){
    int n,i,flag,data,temp;
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
    if(counter(0))
        printf("%-25s %d %5d\n","Number of occurences of",0,counter(0));
    Node *it = Head;
    while(it){
        if((temp=it->data)!=0)
            printf("%-25s %d %5d\n","Number of occurences of",temp,Modcounter(temp)); 
        it = it->next;
    }
    return 0;
}