#include<stdio.h>
#define size 5
int queue[size];
int rear=-1;
int front=-1;
void enqueue(int x){
    if(rear==size-1)
    {
        printf("queue is full");
    }
    else if(rear==-1&&front==-1)
    {
        front=rear=0;
        queue[rear]=x;
    }
    else{
        rear++;
        queue[rear]=x;
    }
}
void dequeue()
{
    if(rear==front)
    {
       rear=front=-1;
    }
    else if(rear==-1&&front==-1)
    {
       printf("queue is empty");
    }
    else{
        printf("the deleted element is: %d",queue[front]);
        front++;
        printf("\n");
    }
}
void peek()
{
    printf("the peek element is: %d",queue[front]);
    printf("\n");
}
void display()
{
    if(rear==-1&&front==-1)
    {
        printf("empty queue");
    }
    else{
        for(int i=front;i<=rear;i++)
        {
            printf("%d\n",queue[i]);
        }
    }
}
int main()
{
    enqueue(2);
    enqueue(4);
    enqueue(5);
    dequeue();
    peek();
    display();
    return 0;
}