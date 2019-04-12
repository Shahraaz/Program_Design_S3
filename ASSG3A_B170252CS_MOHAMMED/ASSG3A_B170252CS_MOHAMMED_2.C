#include<stdio.h>
#include<stdlib.h>
int search(int* arr,int n,int key){
    for(int i =-0;i<n;i++)
        if(arr[i]==key)
            return i;
    return -1;
}
int main(){
    FILE *fptr = fopen("2.txt","r");
    if(fptr==NULL){
        printf("Error Opening File");
        exit(0);
    }
    int key;
    fscanf(fptr,"%d",&key);
    int n;
    if(n<0){
        printf("Cannot Have Negetive elements\n");
        exit(0);
    }
    fscanf(fptr,"%d",&n);
    int pos,arr[n],i;
    for(i=0;i<n;i++){
        fscanf(fptr,"%d",&arr[i]);
    }
    if((pos=search(arr,n,key))==-1)
        printf("NOT FOUND\n");
    else{
        printf("%d\n",pos);
    }
    return 0;
}