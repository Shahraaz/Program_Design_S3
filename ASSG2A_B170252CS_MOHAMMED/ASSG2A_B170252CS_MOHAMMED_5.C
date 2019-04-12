#include<stdio.h>
#include<math.h>
int main()
{
    double a,b,c,d,k;
    printf("Enter a, b, c : ");
    scanf("%lf %lf %lf",&a,&b,&c);
    if(a==0&b==0)
        printf("No roots.a & b both zero\n");
    else if(a==0)
        printf("Liner eqation\nRoot        :  %.3lf\n",-c/b);
    else 
    {
        k = b*b-4*a*c;
        if(k==0)
            printf("Roots are real and equal\nRoots:        %.3lf and %.3lf",-b/(2*a),-b/(2*a));
        else if(k>0)
            printf("Roots are real\nRoots:        %.3lf and %.3lf",-b/(2*a)+sqrt(k)/(2*a),-b/(2*a)-sqrt(k)/(2*a));
        else 
            printf("Roots are Complex\nRoots:        %.3lf+%.3lfi and %.3lf-%.3lfi",-b/(2*a),sqrt(-k)/(2*a),-b/(2*a),sqrt(-k)/(2*a));
    }
    return 0;
}