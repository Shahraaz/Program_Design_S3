#include<stdio.h>
int main()
{
	int size;
	printf("Enter the size of array	       		");
	scanf("%d",&size);
	int i, arr[size],min,secmax,max;
	printf("Array elements		       	 	");
	scanf("%d",&arr[0]);
	for(i=1,min=max=secmax=arr[0];i<size;i++)
	{
		scanf("%d",&arr[i]);
		if(arr[i]<min)
			min = arr[i];
		else if(arr[i]>=max)
		{
			secmax = max;
			max = arr[i];
		}
	}
	printf("Second largest number in array is	%d\n",secmax);
	printf("Smallest number in the array is         %d\n",min);
	return 0;
}
