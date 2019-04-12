#include<stdio.h>
#include<stdlib.h>
#define left(i) (2*i+1)
#define right(i) (2*i+2)
#define parent(i) ((i-1)/2)
typedef struct node{
    int data;
    struct node *left,*right,*parent;
} Node;
Node *Root = NULL;
int i,r,k,size,arr[200000],temp;
Node *newnode(int key){
    Node* newnode = malloc(sizeof(Node));
    newnode->data = key;
    newnode->left = newnode->right = NULL;
}
Node* makeLL(int node,Node *curr){
    if(node>=size) return NULL;
    curr = newnode(arr[node]);
    curr->right = makeLL(right(node),curr->right);
    curr->left = makeLL(left(node),curr->left);
    return curr;
}
void create_tree(){
    scanf("%d",&size);
    for(i=0;i<size;i++)
        scanf("%d",&arr[i]);
    Root = makeLL(0,Root);
}
void postorder(Node* node) { 
    if (node == NULL) 
        return; 
    postorder(node->left); 
    postorder(node->right); 
    printf("%d ",node->data);
} 
void inorder(Node* node){ 
    if (node == NULL) 
        return; 
    inorder(node->left); 
    printf("%d ",node->data);
    inorder(node->right); 
} 
void preorder(Node* node){ 
    if (node == NULL) 
        return;  
    printf("%d ",node->data);
    preorder(node->left);  
    preorder(node->right); 
}  
int main(){
    char choice;
    create_tree();
    printf("Preorder traversal : ");
    preorder(Root);
    printf("\nInorder traversal : ");
    inorder(Root);
    printf("\nPostorder traversal : ");
    postorder(Root);
    return 0;
}