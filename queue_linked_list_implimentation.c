#include<stdio.h>
#include<malloc.h>
struct node{
   int data;
   struct node*next;
};
struct node*front;
struct node*rear;

void enqueue(int x)
{
    struct node*newnode;
    newnode=malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=NULL;
    if(front==0 && rear==0)
    {
        rear=front=newnode;
    }
    else
    {
        rear->next=newnode;
        rear=newnode;
    }
}
void dequeue()
{
    struct node*temp;
    temp=front;
    if(front==0&&rear==0)
    {
        printf("empty");
    }
    else{
        front=front->next;
        free(temp);
    }
}
    void peek()
    {
        if(front==0&&rear==0)
        {
            printf("empty");
        }
        printf("\npeek element is %d:",front->data);
    }
    void display()
    { 
        struct node*temp;
        if(front==0&&rear==0)
        {
            printf("empty");
        }
       temp=front;
       while(temp!=NULL)
       {
        printf("\t%d",temp->data);
        temp=temp->next;
       }
    }
int main()
{
    enqueue(2);
    enqueue(3);
    enqueue(4);
    dequeue();
    display();
    peek();
    
}


