#include<stdio.h>
int queue[100000],choice,n,front=0,rear=-1,x,i;
void Enqueue(int value){
    queue[++rear] = value;
}
void Dequeue(){
    if(front>rear)
        printf("\nEMPTY");
    else
        printf("\n%d",queue[front++]);
}
void PRINT(){
    if(front<=rear){
        printf("\n");
        for(i=front;i<=rear;i++)
            printf("%d ",queue[i]);
    }
    else
        printf("\nEMPTY");
}
int main(){
    int check ;
    do{
        check = 0;
        printf("Enter the size of Queue[MAX=100000]:");
        scanf("%d",&n);
        if(n<=0){
            check = 1;
            printf("Size of array should be positive\n");
        }
    }while(check);
    printf("\nQueue OPERATIONS USING ARRAY");
    printf("\n1.Enqueue\n2.Dequeue\n3.Print\n4.EXIT\n");
    do{
        printf("\nEnter the operation to be performed:");
        scanf("%d",&choice);
        switch(choice){
            case 1:{
                printf("Enter the element to be inserted:");
                scanf("%d",&x);
                if(rear>=n-1)
                    printf("\nOVERFLOW");
                else Enqueue(x);
                break;
            }
            case 2:{
                Dequeue();
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