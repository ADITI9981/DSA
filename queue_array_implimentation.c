#include<stdio.h>
#include<stdlib.h>
# define size 5
int queue[size];
int rear=-1;
int front=-1;

int isempty()
{
    if(front==-1&&rear==-1)
    {
        return 1;
    }
    else{
        return 0;
    }
}

int isfull()
{
    if(rear==size-1)
    {
        return 1;
    }
    else{
        return 0;
    }
}

void enqueue(int data)
{
    if(isfull())
    {
        printf("queue is overflow");
    }
    else if (isempty())
    {
        rear=front=0;
        queue[rear]=data;
    }
    else{
        rear=rear+1;
        queue[rear]=data;
    }
    
}

int dequeue()
{
    if(isempty())
    {
        printf("queue is underflow");
        
    }
    else if (rear==front)
    {
        rear=front=-1;
        
    }
    else{
        printf("the deleted element is:%D",queue[front]);
        front++;
    }
    
}

void print()
{
    if(isempty())
    {
        printf("queue is empty");
    }
    else{
        for(int i=front;i<rear+1;i++)
        {
            printf("%d\t",queue[i]);
        }
    }
    printf("\n");
}

void peek()
{
    if(isempty())
    {
        printf("queue is empty");
        
    }
    else{
        printf("the peek element is:%d",queue[front]);
        
    }
    printf("\n");
}



int main()
  {
     int choice,data;
      while (1)
      {
        
      
        printf("\n");
        printf("1.enqueue\n");
        printf("2.dequeue\n");
        printf("3.print the top element\n");
        printf("4.print all the element of the stack\n");
        printf("5.quit\n");
        printf("6.please enter your choice:");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            printf("enter the element to add:");
            scanf("%d",&data);
            enqueue(data);
            break;
        case 2:

        dequeue();
        break;

        case 3:
        peek();
        break;

        case 4:
        print();
        break;

        case 5:
        exit(1);
        break;

        default:
        printf("wrong choice");
        break;
        }
      }
        return 0;
    }
     
  
   

  