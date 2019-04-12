#include<stdio.h>
int main()
{
	int size1, size2;
	char arrcount[1000000]={0};
	printf("Size of the first array         ");
	scanf("%d",&size1);
	int i,arr1[size1];
	printf("Array elements			");
	for(i=0;i<size1;i++)
		scanf("%d",&arr1[i]);
	printf("Size of second array            ");
	scanf("%d",&size2);
	int arr2[size2],arr[size1+size2],j;
	printf("Array Elements			");
	for(i=0;i<size2;i++)
		scanf("%d",&arr2[i]);
	printf("Merged array                    ");
	for(i=0,j=0;i<size1;i++)
		if(arrcount[arr1[i]+1000000/2]==0)
		{
			arr[j++] = arr1[i];
			arrcount[arr1[i]+1000000/2]++;
		}
	for(i=0;i<size2;i++)
		if(arrcount[arr2[i]+1000000/2]==0)
		{
			arr[j++] = arr2[i] ;
			arrcount[arr2[i]+1000000/2]++;
		}
	for(i=0;i<j;i++)
		printf("%d ",arr[i]);
	printf("\n");
	return 0;
}
