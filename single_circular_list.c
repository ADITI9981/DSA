#include<stdio.h>
#include<malloc.h>
struct node{
    int data;
    struct node*next;
};

struct node*addtoempty(int data)
{
    struct node*temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->next=temp;
    return temp;
}

struct node*addatbegg(struct node*tail,int data)
{
    struct node*temp=malloc(sizeof(struct node));
    temp->next=tail->next;
    tail->next=temp;
    return tail;
}

struct node*addatend(struct node*tail,int data)
{
    struct node*temp=malloc(sizeof(struct node));
    temp->next=tail->next;
    temp->data=data;
    tail->next=temp;
    tail=tail->next;
    return tail;
}

struct node*createlist(struct node*tail)
{
    int data,n;
    printf("enter the number of nodes:");
    scanf("%d",&n);

    printf("enter the data of node 1:");
    scanf("%d",&data);
    tail=addtoempty(data);

    for(int i=1;i<n;i++)
    {
        printf("enter the data of node %d:",i+1);
        scanf("%d",&data);
        tail=addatend(tail,data);
    }
    return tail;
}

struct node*addatpos(struct node*tail,int data,int pos)
{
    struct node*temp=malloc(sizeof(struct node));
    struct node*temp2=tail->next;
    if(pos==1)
    {
        tail=addatbegg(tail,data);
        return tail;
    }

    while(pos>2)
    {
        temp2=temp2->next;
        pos--;
    }

    if(temp2->next==temp2)
    {
        tail=addatend(tail,data);
        return tail;
    }
    
    else{
        temp->data=data;
        temp->next=temp2->next;
        temp2->next=temp;
    }
    return tail;

}

struct node*delfirst(struct node*tail)
{
    struct node*temp=tail->next;
    tail->next=temp->next->next;
    free(temp);
    temp=NULL;
    return tail;
}

struct node*delend(struct node*tail)
{
    struct node*temp=tail->next;
    if(tail->next==tail)
    {
        free(tail);
        return tail;
    }
    
    while(temp->next!=tail)
    {
        temp=temp->next;
    }

    temp->next=tail->next;
    free(tail);
    tail=temp;
    return tail;
}

struct node*delatpos(struct node*tail,int pos)
{
    struct node*temp=tail->next;
    if(pos==1)
    {
        tail=delfirst(tail);
        return tail;
    }
    while(pos>2)
    {
        temp=temp->next;
        pos--;
    }
    struct node*temp2=temp->next;
    if(temp->next==tail)
    {
        tail=delend(tail);
        return tail;
    }
   
    else{
       temp->next=temp2->next;
       free(temp2);
       temp2=NULL;
    }
    return tail;

}

void print(struct node*tail)
{
    struct node*temp=tail->next;
    do
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }while(temp!=tail->next);
    printf("\n");
}

int main()
{
    int data,pos,choice;
    struct node*tail=NULL;

    while(1)
    {
        printf("1:create list\n");
        printf("2:display list\n");
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
            tail=createlist(tail);
            break;
        
        case 2:
            print(tail);
            break;

        case 3:
           printf("enter the data:");
           scanf("%d",&data);
           printf("enter the node position:");
           scanf("%d",&pos);
           tail=addatpos(tail,data,pos);
           print(tail);
           break;

        case 4:
           tail=delfirst(tail);
           print(tail);
           break;

        case 5:
           tail=delend(tail);
           print(tail);
           break;

        case 6:
           printf("enter the node position:");
           scanf("%d",&pos);
           tail=delatpos(tail,pos);
           print(tail);
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