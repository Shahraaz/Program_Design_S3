#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* next;
} Node;
Node* push_down(Node* Head,int data){
    Node *newNode = (Node*)malloc(sizeof(Node)),*it=Head;
    newNode->data = data;
    newNode->next = NULL;
    if(!Head){
        Head = newNode;
        return Head;
    }
    while(it->next)
        it = it->next;
    it->next = newNode;
    return Head;
}
Node* MergeLL(Node* Head,Node* Head1,Node* Head2){
    while(Head1!=NULL & Head2!=NULL){
        if(Head1->data<Head2->data){
            Head = push_down(Head,Head1->data);
            Head1 = Head1->next;
        }
        else{
            Head = push_down(Head,Head2->data);
            Head2 = Head2->next;
        }
    }
    while(Head1){
        Head = push_down(Head,Head1->data);
        Head1 = Head1->next;
    }
    while(Head2){
        Head = push_down(Head,Head2->data);
        Head2 = Head2->next;
    }
    return Head;
}
void check(Node* Head){
    if(!Head) return ;
    while(Head->next){
        if(Head->data>Head->next->data){
            printf("Not Sorted\n");
            exit(0);
        }
        Head = Head->next;
    }
    return;
}
int main(){
    Node *Head=NULL,*Head1=NULL,*Head2=NULL,*it=NULL;
    int m,n,i,data,temp;
    printf("%-30s","Enter the value of m");
    scanf("%d",&m);
    if(m<0){
        printf("Cannot have negtive number of nodes\n");
        exit(0);
    }
    printf("%-30s","Enter the value of n");
    scanf("%d",&n);
    if(n<0){
        printf("Cannot have negtive number of nodes\n");
        exit(0);
    }  
    printf("%-30s","Enter the elements of List1");
    for(i=0;i<m;i++){
        scanf("%d",&data);
        Head1 = push_down(Head1,data);
    }
    check(Head1);
    printf("%-30s","Enter the elements of List2");
    for(i=0;i<n;i++){
        scanf("%d",&data);
        Head2 = push_down(Head2,data);
    }
    check(Head2);
    Head = MergeLL(Head,Head1,Head2);
    it = Head;
    printf("%-30s","The Merged List is");
    while(it){
        printf("%d ",it->data);
        it = it->next;
    }
    printf("\n");
    return 0;
}