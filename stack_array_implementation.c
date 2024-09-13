  #include<stdio.h>
  #include<stdlib.h>
  #define size 4
  int stack_arr[size];
  int top=-1;
   int isfull()
  {
      if(top==size-1)
         return 1;
      else 
         return 0;
  }
  int isempty()
  {
    if(top==-1)
       return 1;
    else
       return 0;
  }
  void push(int data)
  {
    if(isfull())
    {
        printf("stack overflow\n");
        return;
    }
    top=top+1;
    stack_arr[top]=data;
  }
  int pop()
  {
    int value;
    if(isempty()){
        printf("stack underflow");
        exit(1);
    }
    value=stack_arr[top];
    top=top-1; 
    return value;
  }
 
  int peek()
  {
    if(isempty())
    {
        printf("stack underflow\n");
        exit(1);
    }
    return stack_arr[top];
  }
  void print()
  {
    if(top==-1)
    {
        printf("stack underflow\n");
        return;
    }
    for(int i=top;i>=0;i--)
    {
        printf("%d",stack_arr[i]);
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
        printf("the topmost element is %d",peek());
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
     
  
   

  