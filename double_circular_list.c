#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
    struct node*prev;
};

struct node*addtoempty(int data)
{
    struct node*temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->next=temp;
    temp->prev=temp;
    return temp;
}

struct node*addatbegg(struct node*tail,int data)
{
    struct node*temp=malloc(sizeof(struct node));
    struct node*temp2=tail->next;
    temp->data=data;
    temp->next=temp2;
    temp->prev=tail;
    tail->next=temp;
    temp2->prev=temp;
    return tail;
}

struct node*addatend(struct node*tail,int data)
{
    struct node*temp=malloc(sizeof(struct node));
    struct node*temp2=tail->next;
    temp->data=data;
    temp->prev=tail;
    temp->next=temp2;
    tail->next=temp;
    temp->prev=temp;
    tail=temp;
    return tail;
}

struct node*createlist(struct node*tail)
{
   int n,data,i;
    printf("enter the number of nodes");
    scanf("%d",&n);
    if(n==0)
    {
        return tail;
    }
   
    printf("enter the element of node 1:");
    scanf("%d",&data);
    tail=addtoempty(data);
    
    for(i=1;i<n;i++)
    {
        printf("enter the element of node %d:",i+1);
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
    if(temp2->next==tail)
    {
        tail=addatend(tail,data);
        return tail;
    }
    
    else{
        temp->data=data;
        temp->prev=temp2;
        temp2->next->prev=temp2;
        temp->next=temp2->next;
        temp2->next=temp;
    }
    return tail;

}

struct node*delfirst(struct node*tail)
{
   struct node*temp=tail->next;
   temp->next->prev=tail;
   tail->next=temp->next;
   free(temp);
   temp=NULL;
   return tail;
}

struct node* delend(struct node* tail) {
    
    struct node* temp2 = tail->prev;
    temp2->next = tail->next;
    tail->next->prev = temp2;
    free(tail);
    tail = temp2;
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
    if(temp2==tail)
    {
        tail=delend(tail);
        return tail;
    }
    else{
        temp->next=temp2->next;
        temp2->next->prev=temp;
        free(temp2);
        temp2=NULL;
    }
    return tail;
}

void print(struct node*tail)
{
    struct node*p=tail->next;
    do{
        printf("%d\t\t",p->data);
        p=p->next;
    }while(p!=tail->next);
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