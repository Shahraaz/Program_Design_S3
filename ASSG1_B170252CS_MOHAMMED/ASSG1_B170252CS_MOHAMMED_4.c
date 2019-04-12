#include<stdio.h>
int main()
{                    
	int i, j, size, maxsum, sum, init=0, final=0 ;
	printf("Size of array    ");
	scanf("%d",&size);   
	int arr[size];
	printf("Array elements   ");    
	for(i=0;i<size;i++)        
		scanf("%d",&arr[i]);   
	for(i=0,maxsum = arr[0];i<size;i++)    
		for(j=i,sum=0;j<size;j++) 
		{                     
			sum += arr[j];   
			if(sum > maxsum)   
			{                    
				maxsum = sum;   
				init = i;
				final = j;
			}       
		}  
	printf("The Largest sum is %d and the subset index begins at %d and ends at %d\n",maxsum,init,final);  
	return 0;
}
