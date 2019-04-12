#include<stdio.h>
#include<stdlib.h>
void swap(int* a, int*b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void BubbleSort(int *arr,int n){
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n-i-1;j++)
            if(arr[j]>arr[j+1])
                swap(&arr[j],&arr[j+1]);
}
int main(){
    FILE *fptr = fopen("3.txt","r");
    if(fptr==NULL){
        printf("Error Opening File");
        exit(0);
    }
    int n;
    fscanf(fptr,"%d",&n);
    if(n<0){
        printf("Cannot Have Negetive elements\n");
        exit(0);
    }
    int pos,arr[n],i;
    for(i=0;i<n;i++){
        fscanf(fptr,"%d",&arr[i]);
    }
    BubbleSort(arr,n);
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
    return 0;
}