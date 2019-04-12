#include<stdio.h>
int main()
{
	int size;
	printf("Size of Array    	             ");
	scanf("%d",&size);
	int i, tore, toin, count=0, arr[size];
	printf("Array Elements         	             ");
	for(i=0;i<size;i++)
		scanf("%d",&arr[i]);
	printf("Enter the element to be replaced     ");
	scanf("%d",&tore);
	printf("Enter the element to be inserted     ");
	scanf("%d",&toin);
	for(i=0;i<size;i++)
	{
		if(arr[i]==tore)
		{
			arr[i] = toin;
			count = 1 ;
		}
	}
	if(count==0)
	{
		printf("%d is 'NOT FOUND' in the array\n",tore);
		return 0;
	}
	printf("Resultant array                      ");
	for(i=0;i<size;i++)
		printf("%d ",arr[i]);
	printf("\n");
	return 0;
}
