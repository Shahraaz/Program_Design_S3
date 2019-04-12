#include<stdio.h>
int main()
{
    float num1;
    int num2,count=0;
    printf("Enter a positive decimal fraction less than 1 : ");
    scanf("%f",&num1);
    if(num1 <0 | num1 >=1)
        printf("Entered number is not a positive decimal fraction less than 1\n");
    else 
    {
        printf("0.");
        for(count=0;count<4;count++)
        {
            num1 = num1*2;
            num2 = num1;
            if(num2) num1 -= 1; 
            printf("%d",num2);
            if(num1==0) break;
            if(count==3) printf("...");
        }
	printf("\n");
    }
    return 0;
}