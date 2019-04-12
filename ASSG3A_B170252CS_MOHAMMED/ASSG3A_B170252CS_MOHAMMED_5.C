#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
void print(int* arr,int n){
    int i;
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
}
void InsertionSort(int* arr,int n){
    int i,j,key;
    for(i=1;i<n;i++){
        key = arr[i];
        j = i - 1;
        while(j>=0&arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}
int main(){
    FILE *fptr = fopen("5.txt","r");
    if(fptr==NULL){
        printf("Error Opening File");
        exit(0);
    }
    int n;
    if(n<0){
        printf("Cannot Have Negetive elements\n");
        exit(0);
    }
    fscanf(fptr,"%d",&n);
    int arr[n],i;
    for(i=0;i<n;i++){
        fscanf(fptr,"%d",&arr[i]);
    }
    InsertionSort(arr,n);
    print(arr,n);
    return 0;
}