 #include<stdio.h>
#include<malloc.h>

struct node{
    int data;
    struct node*next;
}*top=NULL;

int isempty()
{
    if(top==NULL)
    {
        return 1;
    }
    else{
        return 0;
    }
}

void push(int data)
{
    struct node*temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->next=top;
    top=temp;
}

int pop()
{
   if(isempty())
   {
    printf("stack is empty");
   }
   
    int value=top->data;
    struct node*temp=top;
    top=top->next;
    temp=NULL;
    return value;
   
}

void peek()
{
    if(isempty())
   {
    printf("stack is empty");
   }
   printf("the peek element is:%D",top->data);
}

void display()
{
    struct node*temp=top;

  if(isempty())
     {
       printf("stack is empty");
       exit(0);
     }
  while (temp)
     {
       printf("%d",temp->data);
       temp=temp->next;
       printf("\n");
     }
   
}

int main()
  {
     int choice,data;
      while (1)
      {
        
      
        printf("\n");
        printf("1.push\n");
        printf("2.pop\n");
        printf("3.print the top element\n");
        printf("4.print all the element of the stack\n");
        printf("5.quit\n");
        printf("6.please enter your choice:");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            printf("enter the element to be pushed:");
            scanf("%d",&data);
            push(data);
            break;
        case 2:

        data=pop();
        printf("deleted element is %d\n",data);
        break;

        case 3:
        peek();
        break;

        case 4:
        display();
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
     
  
   

  