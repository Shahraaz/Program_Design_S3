#include<stdio.h>
#include<stdlib.h>
typedef struct Bucket{
    int count;
    int *value;
} bucket;
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
void InsertionsSort(int *arr,int size){
    int i,j,key;
    for(i=1;i<size;i++){
        j = i - 1; key = arr[i];
        while(j>=0&&arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}
int maxvalue(int size){
    int i,maxvalue = 0,maxfreq=0,value=Head->data,freq=1;
    Node *it = Head->next;
    for(i=1;i<size;i++,it = it->next){
        if(value == it->data)
            freq++;
        else{
            if(freq>maxfreq){
                maxfreq = freq;
                maxvalue = value;
            }
            value = it->data;
            freq = 1;
        }
    }    
    if(freq>maxfreq){
        maxfreq = freq;
        maxvalue = value;
    }
    return maxvalue;
}
void bucketsort(int size,FILE* fout){
    int max = findmax(size),i,index,index1,j,length,count,value;
    Node *it;
    for(index=1;max;index*=10)
        max/=10;
    index/=10;
    if(!index) return;
    bucket Buckets[10];
    for(i=0;i<10;i++){
        Buckets[i].count = 0;
        Buckets[i].value = (int*)malloc(sizeof(int)*size);
    }
    for(i=0,it=Head;i<size;i++,it = it->next){
        index1 = it->data/index;
        Buckets[index1].value[Buckets[index1].count++] = it->data;
    }
    for(it=Head,i=0;i<10;i++){
        length = Buckets[i].count;
        InsertionsSort(Buckets[i].value,length);
        for(j=0;j<length;j++,it = it->next)
            it->data = Buckets[i].value[j];
        free(Buckets[i].value);
    }
    while(size){
        value = maxvalue(size);
        count = 0;
        Node *prev=NULL;
        for(i=0,it=Head;i<size;i++){
            if(it->data==value){
                count++;     
                fprintf(fout,"%d ",value);
                if(prev!=NULL){
                    prev = it->next;
                    it = prev;
                }
                else{
                    Head = Head->next;
                    it = it->next;
                }
            }
            else{ 
                prev = it;
                it = it->next;
            }
        }
        size -= count;
    }
}
int main(){
    FILE *fptr, *fout ;
    Node *it;
    Head  = NULL;
    if((fptr = fopen("buckin.txt","r"))==NULL){
        printf("Error unable to open file\n");
        exit(0);
    }
    if((fout = fopen("buckout.txt","w"))==NULL){
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
    if((fptr = fopen("buckin.txt","r"))==NULL){
        printf("Error unable to open file\n");
        fclose(fout);
        exit(0);
    }
    int i;
    for(i=0;i<size;i++){
        fscanf(fptr,"%d",&temp);
        insert(temp);
    }
    bucketsort(size,fout);
    fclose(fout);fclose(fptr);
    return 0;
}