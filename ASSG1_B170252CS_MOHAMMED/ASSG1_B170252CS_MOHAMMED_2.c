#include<stdio.h>
int main()
{
	int i, n, k;
	printf("Size of Array                 ");
	scanf("%d",&n);
	int arr[n+1];
	printf("Array Elements                ");
	for(i=0;i<n;i++)
        	scanf("%d",&arr[i]);
	printf("Position(k)                   ");
	scanf("%d",&k);
	if(k>=n)
		{
		printf("INVALID INDEX\n");
		return 0;
	}
	printf("Element at %d position is	 %d\n",k,arr[k-1]);
	for(i=k-1;i<n;i++)
        	arr[i]=arr[i+1];
	printf("Resultant array               ");
	for(i=0,n--;i<n;i++)
        	printf("%d ",arr[i]);
	printf("\n");
	return 0;
}
