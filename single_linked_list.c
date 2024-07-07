#include<stdio.h>
#include<malloc.h>

struct node{
    int data;
    struct node*next;
};

struct node*addtoempty(struct node*head,int data)
{
    struct node*temp =malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;
    head=temp;
    return head;
}

struct node*addtoend(struct node*head,int data)
{
    struct node*temp=malloc(sizeof(struct node));
    struct node*temp2=head;
    temp->data=data;
    temp->next=NULL;
    while(temp2->next!=NULL)
    {
        temp2=temp2->next;
    }
    temp2->next=temp;
    return head;
}

struct node*addatbegg(struct node*head,int data)
{
    struct node*temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->next=head;
    head=temp;
    return head;
}

struct node*addatpos(struct node*head,int data,int pos)
{
    struct node*temp2=malloc(sizeof(struct node));
    struct node*temp=head;
    
    if(pos==1)    {
        head=addatbegg(head,data);
        return head;
    }
    while(pos>2)
    {
        temp=temp->next;
        pos--;
    }
    if(temp->next==NULL)
    {
        head=addtoend(head,data);
        return head;
    }
    else{
        temp2->data = data;
        temp2->next=temp->next;
        temp->next=temp2;
        return head;
    }

}

struct node*delfirst(struct node*head)
{
    struct node*temp=head;
    head=head->next;
    free(temp);
    return head;
}

struct node*delend(struct node*head)
{
  struct node*temp=head;
  if(temp->next==NULL)
  {
    head=delfirst(head);
  }
  while(temp->next->next!=NULL)
  {
    temp=temp->next;
  }
  free(temp->next);
  temp->next=NULL;
  return head;
}

struct node*delpos(struct node*head,int pos)
{
    struct node*temp=head;
    struct node*temp2=head;
    if(pos==1)
    {
        head=delfirst(head);
        return head;
    }
    while(pos>2)
    {
        temp=temp->next;
        pos--;
    }
    temp2=temp->next;
    if(temp->next=NULL)
    {
        head=delend(head);
        return head;
    }
    
       else
      {
         temp->next=temp2->next;
         temp2->next=NULL;
         free(temp2);
      }
    
     return head;
}

struct node*createlist(struct node*head)
{
   int data,n;
   printf("enter the number of nodes:");
   scanf("%d",&n);

   printf("enter the data of node 1:");
   scanf("%d",&data);
   head=addtoempty(head,data);
   
   for(int i=1;i<n;i++)
   {
    printf("enter the data of node %d:",i+1);
    scanf("%d",&data);
    head=addtoend(head,data);
   }
   return head;

}

void print(struct node*head)
{
    struct node*temp=head;
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main()
{
    struct node*head=NULL;
    int choice,data,pos;

    while(1)
    {
        printf("1:Create list\n");
        printf("2:Display list\n");
        printf("3:add node at position\n");
        printf("4:delete first node\n");
        printf("5:delete last node\n");
        printf("6:delete node at position\n");
        printf("7:exit\n");
        printf("enter your choice:");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            head=createlist(head);
            break;

        case 2:
            print(head);
            break;
        
        case 3:
            printf("enter the data:");
            scanf("%d",&data);
            printf("enter the position of node:");
            scanf("%d",&pos);
            head=addatpos(head,data,pos);
            print(head);
            break;

        case 4:
            head=delfirst(head);
            break;

        case 5:
            head=delend(head);
            break;

        case 6:
            printf("enter the position of node:");
            scanf("%d",&pos);  
            head=delpos(head,pos);
            break;

        case 7: 
            exit(0);
            break;

        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    }

    return 0;
}