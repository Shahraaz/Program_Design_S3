#include<stdio.h>
int print(int *arr,int *a)
{
    int i,j,n1,count=0,sum=0;
    printf("The sum is : ");
    for(i=0;i<(*a);i++)
    {
        for(j=0,n1=arr[i];n1;n1/=10,j++);
        if(j==4&(arr[i]%2==0))
        {        
            printf("%d + ",arr[i]);
            sum += arr[i];
        }    
    }
    printf("\b\b ");
    return sum;
}
int main()
{
    printf("Enter number of elements : ");
    int a,sum;
    scanf("%d",&a); 
    int arr[a],i;
    printf("Enter the elements       : ");
    for(i=0;i<a;i++)
        scanf("%d",&arr[i]);
    printf("\n");
    sum = print(arr,&a);
    printf(" = %d\n",sum);
	return 0;
}