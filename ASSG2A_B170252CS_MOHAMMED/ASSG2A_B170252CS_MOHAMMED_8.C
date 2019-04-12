#include<stdio.h>
int perfect(int a)
{
	if(a==1) return 0;
	int sum = 1,i;
	for(i=2;i*i<=a;i++)
        if(a%i==0)
        {
            if(a==i*i) sum += i;
            else sum += i + a/i;
        }
	return a==sum;
}
int main()
{
    printf("Enter an integer number : ");
    int a,check;
    scanf("%d",&a);
    	check = perfect(a);
	if(check)
        printf("%d is a perfect number\n",a);
    else printf("%d is not a perfect number\n",a);

    return 0;
}