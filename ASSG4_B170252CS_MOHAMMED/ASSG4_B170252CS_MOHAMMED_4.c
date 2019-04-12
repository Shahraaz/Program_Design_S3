#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* next;
} Node;
Node *Head;
void insert(int data){
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
int findmax(int size){
    int max = 0,i;
    Node *it = Head;
    for(i=0;i<size;i++,it = it->next){
        if(it->data>max) max = it->data;}
    return max;
} 
void reverse() { 
    Node *current = Head; 
    Node *prev = NULL, *next = NULL; 
    while (current != NULL){ 
        next = current->next; 
        current->next = prev; 
        prev = current; 
        current = next; 
    } 
        Head = prev; 
} 
void countSort(int size, int exp) { 
    int *output = (int*)malloc(sizeof(int)*size); 
    int i, count[10] = {0},index;
    Node *it;
    for (i = 0,it = Head; i < size; i++, it = it->next) 
        count[(it->data/exp)%10]++; 
    for (i = 1; i < 10; i++) 
        count[i] += count[i - 1];
    for (i = size - 1,it=Head; i >= 0; i--,it = it->next) {   
        index = (it->data/exp)%10;
        output[count[index]-1] = it->data; 
        count[index]--; 
    }  
    for (i = 0,it=Head; i < size; i++,it=it->next) 
        it->data = output[i];
}
void radixsort(int size){
    int max = findmax(size),exp;
    for(exp=1;max/exp>0;exp *=10)
        countSort(size,exp);
    reverse();
}
int main(){
    FILE *fptr, *fout ;
    Head = NULL;
    Node *it;
    if((fptr = fopen("radixin.txt","r"))==NULL){
        printf("Error unable to open file\n");
        exit(0);
    }
    if((fout = fopen("radixout.txt","w"))==NULL){
        fclose(fptr);
        printf("Error unable to open file\n");
        exit(0);
    }
    int temp, size;
    for(size=0;!feof(fptr);size++){
        fscanf(fptr,"%d ",&temp);
        if(temp<0){
            printf("Program designed for non-negetive integers\n");
            exit(0);
        }
    }
    if((fptr = fopen("radixin.txt","r"))==NULL){
        printf("Error unable to open file\n");
        fclose(fout);
        exit(0);
    }
    int i;
    for(i=0;i<size;i++){
        fscanf(fptr,"%d",&temp);
        insert(temp);
    }
    radixsort(size);
    for(i=0,it=Head;i<size;i++,it=it->next)
        fprintf(fout,"%d ",it->data);
    fclose(fout);fclose(fptr);
    return 0;
}