#include<stdio.h>
int main()
{
	int size;
	printf("Size of array              ");
	scanf("%d",&size);
	int i,arr[size],arr2[size];
	printf("Array elements             ");
	for(i=0;i<size;i++)
	{
		scanf("%d",&arr[i]);
		arr2[(i+size-1)%size] = arr[i];
	}
	printf("Cyclic Permuted array is   ");
	for(i=0;i<size;i++)
		printf("%d ",arr2[i]);
	printf("\n");
	return 0;
}
