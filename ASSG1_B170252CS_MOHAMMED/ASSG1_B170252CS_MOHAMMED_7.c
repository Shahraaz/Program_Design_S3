#include<stdio.h>
int main()
{
	int m,n;
	printf("Enter the value of m    ");
	scanf("%d",&m);
	printf("Enter the value of n    ");
	scanf("%d",&n);
	int matrix[m][n], resmatrix[n][m], i, j;
	printf("Elements of matrix    \n");
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
		{
			scanf("%d",&matrix[i][j]);
			resmatrix[j][i] = matrix[i][j];
		}
	printf("\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
			printf("%d ",resmatrix[i][j]);
		printf("\n");
	}
	return 0;
}
