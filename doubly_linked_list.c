#include<stdio.h>
#include<malloc.h>

struct node{
   int data;
   struct node*next;
   struct node*prev;
};

struct node*addtoempty(struct node*head,int data)
{
    struct node*temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;
    temp->prev=NULL;
    head=temp;
    return head;
}

struct node*addatbegg(struct node*head,int data)
{
    struct node*temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->prev=NULL;
    temp->next=head;
    head=temp;
    return head;
}

struct node*addatend(struct node*head,int data)
{
    struct node*temp=malloc(sizeof(struct node));
    struct node*temp2=head;
    
    while(temp2->next!=NULL)
    {
        temp2=temp2->next;
    }
    temp->data=data;
    temp->next=NULL;
    temp->prev=temp2;
    temp2->next=temp;
    return head;
}

struct node*createlist(struct node*head)
{
    int data,n;
    printf("enter the number of node:");
    scanf("%d",&n);

    printf("enter the data of node 1:");
    scanf("%d",&data);
    head=addtoempty(head,data);

    for(int i=1;i<n;i++)
    {
        printf("enter the data of node %d:",i+1);
        scanf("%d",&data);
        head=addatend(head,data);
    }
    return head;
}

struct node*addatpos(struct node*head,int data,int pos)
{
    struct node*temp=malloc(sizeof(struct node));
    struct node*temp2=head;

    if(pos==1)
    {
        head=addatbegg(head,data);
        return head;
    }

    while(pos>1)
    {
        temp2=temp2->next;
        pos--;
    }

    if(temp2->next==NULL)
    {
        head=addatend(head,data);
        return head;
    }

    else{
        temp->data=data;
        temp->next=temp2;
        temp->prev=temp2->prev;
        temp->prev->next=temp;
    }
    return head;
}

struct node*delfirst(struct node*head)
{
    struct node*temp=head;
    head=head->next;
    head->prev=NULL;
    free(temp);
    return head;
}

struct node*delend(struct node*head)
{
    struct node*temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->prev->next=NULL;
    free(temp);
    return head;
}

struct node*delatpos(struct node*head,int pos)
{
    struct node*temp=head;
    if(pos==1)
    {
        head=delfirst(head);
        return head;
    }

    while(pos>1)
    {
        temp=temp->next;
        pos--;
    }

    if(temp->next==NULL)
    {
        head=delend(head);
        return head;
    }

    else{
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        free(temp);
        temp=NULL;
    }

    return head;
}

void print(struct node*head)
{
    struct node*temp=head;
    while(temp!=0)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main()
{
    struct node*head=NULL;
    int pos,data,choice;
    while(1)
    {
        printf("1:create the list\n");
        printf("2:display the list\n");
        printf("3:add node at pos\n");
        printf("4:delete first node\n");
        printf("5:delete last node\n");
        printf("6:delete node at pos\n");
        printf("7:exit\n");
        printf("your choice:");
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
            printf("enter the position:");
            scanf("%d",&pos);
            head=addatpos(head,data,pos);
            print(head);
            break;

        case 4:
            head=delfirst(head);
            print(head);
            break;

        case 5:
            head=delend(head);
            print(head);
            break;

        case 6:
            printf("enter the position :");
            scanf("%d",&pos);
            head=delatpos(head,pos);
            print(head);
            break;

        case 7:
            exit(0);
            break;

        default:
            printf("invalid choice,please try again");
            break;
        }
    }
    return 0;
}