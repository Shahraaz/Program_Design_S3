#include<stdio.h>
int main()
{
    int i;
    char bin[100];
    start :
    printf("Enter a binary number         : ");
    scanf("%s",bin);
    for(i=0;bin[i];i++)
	if(bin[i]!='0'&bin[i]!='1') goto start;
    int decimal = 0;
    for(i=0;bin[i];i++)
        decimal = decimal*2 + bin[i] - '0';
    printf("The equivalent decimal number : %d\n",decimal);
    return 0;
}