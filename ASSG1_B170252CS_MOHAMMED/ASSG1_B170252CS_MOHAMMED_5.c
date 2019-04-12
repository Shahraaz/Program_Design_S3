#include<stdio.h>
int main()
{
	int size;
	printf("Size of Array                   ");
	scanf("%d",&size);
	int arr[size],arr2[size],i,j,k;
	printf("Array elements                  ");
	for(i=0;i<size;i++)
		scanf("%d",&arr[i]);
	printf("Enter the position of elemnts\n");
	printf("To split the array              ");
	scanf("%d",&k);
	if(k>size)
	{
		printf("INVALID INDEX\n");
		return 0;
	}
	for(i=0,j=k-1;i<size;i++,j++)
		arr2[i] = arr[j%size];
	printf("Resultant Array                 ");
	for(i=0;i<size;i++)
		printf("%d ",arr2[i]);
	printf("\n");
	return 0;
}
