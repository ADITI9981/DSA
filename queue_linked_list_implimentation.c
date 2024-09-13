#include<stdio.h>
#include<malloc.h>
struct node{
   int data;
   struct node*next;
};

struct node*rear;
struct node*front;

int isempty()
{
    if(front==0&&rear==0)
    {
        return 1;
    }
    else{
        return 0;
    }
}

void enqueue(int data)
{
    struct node*temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;
    if (isempty())
    {
       rear=front=temp;
    }
    else{
        rear->next=temp;
        rear=temp;
    }
    
}

int dequeue()
{
    struct node*temp=front;
    if(isempty())
    {
        printf("queue is underflow");
        
    }

    else if(rear==front)
    {
       rear=front=NULL;
    ]
    
    else{
         printf("the deleted element is:%d",front->data);
        front=front->next;
        free(temp);
    }
    
}

void print()
{
    struct node*temp=front;
    if(isempty())
    {
        printf("queue is empty");
    }
    else{
        while(temp!=0)
        {
            printf("%d\t",temp->data);
            temp=temp->next;
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
        printf("the peek element is:%d",front->data);
        
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
     
  
   

  
