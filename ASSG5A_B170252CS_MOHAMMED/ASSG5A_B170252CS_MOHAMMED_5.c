#include<stdio.h>
#include<stdlib.h>
#define swap(a,b){int t=a;a=b;b=t;}
int arr[100000],n,i;
int sorted_asc(){
    for(i=0;i<n-1;i++)
        if(arr[i]>arr[i+1]) return 0;
    return 1;
}
int sorted_desc(){
    for(i=0;i<n-1;i++)
        if(arr[i]<arr[i+1]) return 0;
    return 1;
}
int partition (int low, int high){
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high- 1; j++) {
        if (arr[j] <= pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    i++;
    swap(arr[i], arr[high]);
    return i;
}
void QSort(int low, int high) {
    if (low < high){
        int pi = partition(low, high);
        QSort(low, pi - 1);
        QSort(pi + 1, high);
    }
}
int main(int argc,char *argv[]){
    if(argc!=3){
        printf("Invalid Command Line Argument count\n");
        return 0;
    }
    FILE *input ,*out;
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
        if(sorted_asc())
            fprintf(out,"The array is sorted in ascending order.\n");
        else if(sorted_desc())
            fprintf(out,"The array is sorted in descending order.\n");
        else{
            QSort(0,n-1);
            fprintf(out,"The sorted array in ascending order is:\n");
            for (i=0; i<n; ++i)
                fprintf(out,"%d ",arr[i]);
            fprintf(out,"\n");
        }
    }
    fclose(out);fclose(input);
    return 0;
}
