#include<stdio.h>
int stack[100000],choice,n,top,x,i;
void push(int value){
    top++;
    stack[top] = value;
}
void pop(){
    if(top<=-1)
        printf("\nEMPTY");
    else{
        printf("\n%d",stack[top]);
        top--;
    }
}
void PRINT(){
    if(top>=0){
        printf("\n");
        for(i=top; i>=0; i--)
            printf("%d ",stack[i]);
    }
    else
        printf("\nEMPTY");
    
}
int main(){
    top=-1;
    int check ;
    do{
        check = 0;
        printf("Enter the size of STACK[MAX=100000]:");
        scanf("%d",&n);
        if(n<=0){
            check = 1;
            printf("Size of array should be positive\n");
        }
    }while(check);
    printf("\nSTACK OPERATIONS USING ARRAY");
    printf("\n1.PUSH\n2.POP\n3.PRINT\n4.EXIT\n");
    do{
        printf("\nEnter the operation to be performed:");
        scanf("%d",&choice);
        switch(choice){
            case 1:{
                printf("Enter the element to be inserted:");
                scanf("%d",&x);
                if(top>=n-1)
                    printf("\nOVERFLOW");
                else push(x);
                break;
            }
            case 2:{
                pop();
                break;
            }
            case 3:{
                PRINT();
                break;
            }
            case 4:{
                printf("\nEXIT POINT ");
                break;
            }
            default: printf ("\nPlease Enter a Valid Choice(1/2/3/4)");                 
        }
    }
    while(choice!=4);
    return 0;
}