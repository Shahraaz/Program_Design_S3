#include<stdio.h>
int gcd(int a, int b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}
void print(int n,int x, int y)
{
    int i,lcm=0,n1,n2,n3;
    printf("Multiple of %d are   : ",x);
    if(x==0)
	printf("0");
	else 
	for(i=1;i<n&i*x<n;i++)
        printf("%d ",i*x);
    printf("\nMultiple of %d are   : ",y);
    if(y==0)
	printf("0");
	else 
	for(i=1;i<n&i*y<n;i++)
        printf("%d ",i*y);
    n--;
	if(x==0)
		n1 = 0;
	else n1 = n / x;
	if(y==0)
		n2 = 0;
	else n2 = n / y;
	if(x==0|y==0)
		n3 = 0;
	else 
	{
		lcm = x*y/gcd(x,y);
		n3 = n/lcm;
	}
    printf("\nTotal sum is : %d\n",x*n1*(n1+1)/2+y*n2*(n2+1)/2-lcm*n3*(n3+1)/2);   
    return ;
}

int main()
{
    printf("Enter the value of n   : ");
    int n,x,y;
    scanf("%d",&n);
    printf("Enter the value of x   : ");
    scanf("%d",&x);
    printf("Enter the value of y   : ");
    scanf("%d",&y);
    print(n,x,y);
    return 0;
}