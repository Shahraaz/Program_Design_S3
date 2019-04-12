#include<stdio.h>
#include<stdlib.h>
typedef struct Bucket{
    int count;
    int *value;
} bucket;
int findmax(int *arr,int size){
    int max = 0,i;
    for(i=0;i<size;i++)
        if(arr[i]>max) max = arr[i];
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
void print(int *arr,int size){
    for(int i=0;i<size;i++)
        printf("%d ",arr[i]);
    printf("\n");
}
void bucketsort(int *arr,int size){
    int max = findmax(arr,size),i,index,index1,k,j,length;
    for(index=1;max;index*=10)
        max/=10;
    index/=10;
    if(!index) return;
    bucket Buckets[10] ;
    for(i=0;i<10;i++){
        Buckets[i].count = 0;
        Buckets[i].value = (int*)malloc(sizeof(int)*size);
    }
    for(i=0;i<size;i++){
        index1 = arr[i]/index;
        Buckets[index1].value[Buckets[index1].count++] = arr[i];
    }
    for(k=0,i=0;i<10;i++){
        length = Buckets[i].count;
        InsertionsSort(Buckets[i].value,length);
        for(j=0;j<length;j++)
            arr[k+j] = Buckets[i].value[j];
        k += length;
        free(Buckets[i].value);
    }
}
int main(){
    FILE *fptr, *fout ;
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
    int i,*arr = (int*)malloc(sizeof(int)*size);
    for(i=0;i<size;i++)
        fscanf(fptr,"%d",&arr[i]);
    bucketsort(arr,size);
    for(i=0;i<size;i++)
        fprintf(fout,"%d ",arr[i]);
    fclose(fout);fclose(fptr);
    return 0;
}