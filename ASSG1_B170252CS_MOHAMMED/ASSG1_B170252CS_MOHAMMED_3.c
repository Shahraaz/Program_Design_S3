#include<stdio.h>
int main()
{
        int i,size,maxodd,counter=0;
        printf("Size of Array     ");
        scanf("%d",&size);
        int arr[size];
        printf("Array Elements    ");
        for(i=0;i<size;i++)
        {
                scanf("%d",&arr[i]);
                if(arr[i]%2)
                        if(arr[i]>maxodd)
                        {
                                maxodd = arr[i];
                                counter = 1;
                        }
        }
        if(counter==0)
                printf("NO odd integer in the array\n");
        else printf("The larget odd integer is %d\n",maxodd);
        return 0;
}
