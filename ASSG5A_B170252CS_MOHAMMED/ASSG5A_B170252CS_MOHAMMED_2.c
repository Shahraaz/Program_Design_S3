#include<stdio.h>
#include<stdlib.h>
#define swap(a,b){int t=a;a=b;b=t;}
int arr[100000],n,i;
FILE *input ,*out;
typedef struct node{
    int data;
    struct node *left,*right;
} Node;
void heapify(int n, int i){ 
    int largest = i; 
    int l = 2*i + 1; 
    int r = 2*i + 2; 
    if (l < n && arr[l] > arr[largest]) 
        largest = l; 
    if (r < n && arr[r] > arr[largest]) 
        largest = r; 
    if (largest != i){ 
        swap(arr[i], arr[largest]); 
        heapify(n, largest); 
    } 
}
void heapSort(){
    for (i = n / 2 - 1; i >= 0; i--) 
        heapify(n, i); 
    for (i=n-1; i>=0; i--){ 
        swap(arr[0], arr[i]); 
        heapify(i, 0); 
    } 
}
int main(int argc,char *argv[]){
    if(argc!=3){
        printf("Invalid Command Line Argument count\n");
        return 0;
    }
    if((input = fopen(argv[1],"r"))==NULL){
        printf("Unable to open Input FIle\n");
        return 0;
    }
    if((out = fopen(argv[2],"w"))==NULL){
        printf("Unable to open Input FIle\n");
        return 0;
    }
    fscanf(input,"%d",&n);
    if(n<=0)
        fprintf(out,"Size of array cannot be negetive");
    else{
        for(i=0;i<n;i++)
            fscanf(input,"%d",&arr[i]);
        heapSort();
        fprintf(out,"\n");
    }
    fclose(out);fclose(input);
    return 0;
}