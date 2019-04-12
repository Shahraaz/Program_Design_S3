#include<stdio.h>
struct matrix
{
    int arr[100][100];
    int m;
    int n;
};
void print(struct matrix temp,int m, int n)
{
    static char c = 'A';
    printf("Matix %c is \n",c++);
    int i,j;
    for(i=0;i<m;i++,printf("\n"))
        for(j=0,printf("	   ");j<n;j++)
            printf("%2d ",temp.arr[i][j]);
}
struct matrix substract(struct matrix temp1,struct matrix temp2)
{
    int i,j;
    for(i=0;i<temp1.m;i++)
        for(j=0;j<temp1.n;j++)
            temp1.arr[i][j] -= temp2.arr[i][j];
    return temp1;
}
struct matrix sum(struct matrix temp1,struct matrix temp2)
{
    int i,j;
    for(i=0;i<temp1.m;i++)
        for(j=0;j<temp1.n;j++)
            temp1.arr[i][j] += temp2.arr[i][j];
    return temp1;
}
void read(struct matrix *temp ,int m, int n)
{
    static char c = 'A';
    printf("Enter the Elements of matrix %c \n",c++);
    int i,j;
    for(i=0;i<m;i++)
        for(j=0,printf("			        ");j<n;j++)
            scanf("%d",&(temp->arr[i][j]));
} 
int main()
{
    struct matrix matrices[4];
    printf("Enter the order of matrix A : ");
    scanf("%d %d",&matrices[0].m,&matrices[0].n);
    printf("Enter the order of matrix B : ");
    scanf("%d %d",&matrices[1].m,&matrices[1].n);
    read(&matrices[0],matrices[0].m,matrices[0].n);
    read(&matrices[1],matrices[1].m,matrices[1].n);
    print(matrices[0],matrices[0].m,matrices[0].n);
    print(matrices[1],matrices[1].m,matrices[1].n);
    if(matrices[0].m==matrices[1].m&matrices[0].n==matrices[1].n)
    {
        matrices[2] = sum(matrices[0],matrices[1]);
        matrices[3] = substract(matrices[0],matrices[1]);
        print(matrices[2],matrices[0].m,matrices[0].n);
        print(matrices[3],matrices[0].m,matrices[0].n);
    }
    else 
    {
        printf("Matrix Addition is not possible\nMatrix Subtraction is not possible.\n");
    }
    return 0;
}