#include<stdio.h>
#include<stdlib.h>
void indexsearch(int arr[],int n);
void linear_search(int arr[],int start,int end,int s);
int main()
{
    int n,arr[100];
    printf("enter the number of elements:");
    scanf("%d",&n);

    for(int i=0;i<=n;i++)
    {
        printf("enter the element %d :",i+1);
        scanf("%d",&arr[i]);
    }
    printf("array is:");
    for(int i=0;i<=n;i++)
    {
        printf("%d\t",arr[i]);
    }

    indexsearch(arr,n);
    return 0;
}

void indexsearch(int arr[],int n)
{
    int g=3,indices[g],s;
    printf("\nenter the element to search:");
    scanf("%d",&s);
    int ind=0,start=0,end=0;
    for(int i=0;i<n;i=i+g)
    {
        indices[ind]=i;
        ind++;
        
    }

    if(s<arr[indices[0]] || s>arr[indices[ind-1]])
    {
      printf("element not found");
      exit(0);
    }
    else{
        for(int i=0;i<=ind;i++)
        {
          if(s<=arr[indices[i]])
          {
            start =indices[i-1];
            end =start+g;
            break;
          }
        }
      
    }

    linear_search(arr,start,end,s);
}
void linear_search(int arr[],int start,int end,int s)
{
    int i,flag=0;
    for( i=start;i<end;i++)
    {
        if(arr[i] == s)
        {
            flag = 1;
            break;
        }
        
    }
    if(flag == 1)
    {
        printf("element is found at index  :%d",i);

    }
    else{
        printf("element is not found");
    }
    
}