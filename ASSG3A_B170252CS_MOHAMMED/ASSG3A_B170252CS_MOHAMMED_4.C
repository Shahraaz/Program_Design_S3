#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
void swap(int* a, int*b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void print(int* arr,int n){
    int i;
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
}
void SelectionSort(int * arr,int n){
    int i,j,min,minindex;
    for(i=0;i<n;i++){
        min = arr[i];
        minindex = i;
        for(j=i+1;j<n;j++)
            if(arr[j]<min){
                min = arr[j];
                minindex = j;
            }
        swap(&arr[i],&arr[minindex]);
        printf("%d %-27s ",i+1,"Iteration");
        print(arr,n);
        printf("\n");
    }
}
void BubbleSort(int *arr,int n){
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n-i-1;j++)
            if(arr[j]>arr[j+1])
                swap(&arr[j],&arr[j+1]);
}
int main(){
    FILE *fptr = fopen("4.txt","r");
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
    int pos,arr[n],arr2[n],i;
    for(i=0;i<n;i++){
        fscanf(fptr,"%d",&arr[i]);
        arr2[i] = arr[i];
    }
    printf("%-30s","The Sorted List is");
    BubbleSort(arr,n);
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");
    SelectionSort(arr2,n);
    return 0;
}