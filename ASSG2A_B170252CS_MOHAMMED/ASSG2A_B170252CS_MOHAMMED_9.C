#include<stdio.h>
int fib(int n)
{
	if(n==0) return 0;
	if(n==1) return 1;
	return fib(n-1) + fib(n-2);
}
int main()
{
    printf("Enter a number(n) : ");
    int number;
    scanf("%d",&number);
    printf("Fibonacci series    ");
    int i;
    for(i=0;i<number;i++)
        printf("%d ",fib(i));
    printf("\n");    
    return 0;
}