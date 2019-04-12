#include<stdio.h>
#include<stdlib.h>
int findmax(int *arr,int size){
    int max = 0,i;
    for(i=0;i<size;i++)
        if(arr[i]>max) max = arr[i];
    return max;
} 
void print(int *arr,int size){
    for(int i=0;i<size;i++)
        printf("%d ",arr[i]);
    printf("\n");
}
void fprint(int *arr,int size,FILE *fout){
    for(int i=0;i<size;i++)
        fprintf(fout,"%d ",arr[i]);
    fprintf(fout,"\n");
}
void countSort(int *arr, int size, int exp,FILE* fout) { 
    int *output = (int*)malloc(sizeof(int)*size); 
    int i, count[10] = {0},index;
    for (i = 0; i < size; i++) 
        count[(arr[i]/exp)%10]++; 
    for (i = 1; i < 10; i++) 
        count[i] += count[i - 1];
    for (i = size - 1; i >= 0; i--) {   
        index = (arr[i]/exp)%10;
        output[count[index]-1] = arr[i]; 
        count[index]--; 
    }  
    for (i = 0; i < size; i++) 
        arr[i] = output[i];
    fprint(arr,size,fout); 
}
void radixsort(int *arr,int size,FILE *fout){
    int max = findmax(arr,size),exp;
    if(max==0){
        fprint(arr,size,fout); 
        fclose(fout);
        exit(0);    
    }
    for(exp=1;max/exp>0;exp *=10)
        countSort(arr,size,exp,fout);
}
int main(){
    FILE *fptr, *fout ;
    if((fptr = fopen("sortin.txt","r"))==NULL){
        printf("Error unable to open file\n");
        exit(0);
    }
 /*   if((fout = fopen("radixout.txt","w"))==NULL){
        fclose(fptr);
        printf("Error unable to open file\n");
        exit(0);
    }
  */  int temp, size1, size2,size;
    size1 = size2 = 0;
    char ch;
    
    printf("%d %d\n",size1,size2);
    if((fptr = fopen("radixin.txt","r"))==NULL){
        printf("Error unable to open file\n");
        fclose(fout);
        exit(0);
    }
    int i,*arr = (int*)malloc(sizeof(int)*size);
    for(i=0;i<size;i++)
        fscanf(fptr,"%d",&arr[i]);
    radixsort(arr,size,fout);
    fclose(fout);fclose(fptr);
    return 0;
}