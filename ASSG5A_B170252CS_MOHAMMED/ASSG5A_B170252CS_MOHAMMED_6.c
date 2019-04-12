#include<stdio.h>
#define isFull() (size == capacity) 
#define isEmpty() (size == 0) 
int queue[100000],choice,n,front=0,rear=-1,x,i,capacity,size;
void Enqueue(int value){
    size++;
    rear = (rear+1)%capacity;
    queue[rear] = value;
}
void Dequeue(){
    if(isEmpty())
        printf("\nEMPTY");
    else{
        printf("\n%d",queue[front]);
        front = (front+1)%capacity;
        size--;
    }
}
void PRINT(){
    if(!isEmpty()){
        printf("\n");
        if(front<=rear)
            for(i=front;i<=rear;i++)
                printf("%d ",queue[i]);
        else{
            for(i=front;i<capacity;i++)
                printf("%d ",queue[i]);
            for(i=0;i<=rear;i++)
                printf("%d ",queue[i]);
        }    
    }
    else
        printf("\nEMPTY");
}
int main(){
    int check ;
    do{
        check = 0;
        printf("Enter the size of Circular Queue[MAX=100000]:");
        scanf("%d",&n);
        if(n<=0){
            check = 1;
            printf("Size of Circular Queue should be positive\n");
        }
    }while(check);
    size = 0;
    rear = n - 1;
    capacity = n;
    printf("\nQueue OPERATIONS USING ARRAY");
    printf("\n1.Enqueue\n2.Dequeue\n3.Print\n4.EXIT\n");
    do{
        printf("\nEnter the operation to be performed:");
        scanf("%d",&choice);
        switch(choice){
            case 1:{
                printf("Enter the element to be inserted:");
                scanf("%d",&x);
                if(isFull())
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