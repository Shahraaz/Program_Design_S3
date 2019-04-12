#include<stdio.h> 
#include<stdlib.h>
int intcmp(const void *a, const void *b)
{ 
	return *(const int *)a - *(const int *)b;
}                                                                             
int main()
{                                                                                      
	int MAXnum=1000000;                                                          
       	int n,i,max=MAXnum/2;
	printf("Size of array(n) : ");
	scanf("%d",&n);
	int arr[n],arrcount[1000000] = {0} ;
	printf("Array Elements     ");
	for(i=0;i<n;i++)
	{ 
		scanf("%d",&arr[i]);
		arrcount[arr[i]+max]++;
	}
	qsort(arr,n,sizeof(int),intcmp);
	printf("Frequency of elements :\n");
	for(i=0;i<n;i++)
	{  
		if(arrcount[arr[i]+max])
		{  
			printf("                            %3d %3d\n",arr[i],arrcount[arr[i]+max]); 
			arrcount[arr[i]+max] = 0 ;
		}
	}                                                                             
       	return 0;
}
