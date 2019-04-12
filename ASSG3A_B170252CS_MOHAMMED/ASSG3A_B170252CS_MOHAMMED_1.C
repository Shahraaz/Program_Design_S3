#include<stdio.h>
#include<stdlib.h>
int search(int* arr,int n,int key){
    for(int i =-0;i<n;i++)
        if(arr[i]==key)
            return i;
    return -1;
}
int main(){
    FILE *fptr = fopen("1.txt","r");
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
    printf("%-40s %d\n","The number of elements in the array",n);
    int pos,arr[n],i,key;
    printf("%-40s ","The Array Elements are",n);
    for(i=0;i<n;i++){
        fscanf(fptr,"%d",&arr[i]);
        printf("%d ",arr[i]);
    }
    fscanf(fptr,"%d",&key);
    if((pos=search(arr,n,key))==-1)
        printf("\nNOT FOUND\n");
    else{
        printf("\n%-40s %d\n","The key is found in the position ",pos);
    }
    return 0;
}