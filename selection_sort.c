#include<stdio.h>
#include<stdlib.h>
void selection(int arr[],int n);
void print(int arr[],int n);
int main()
{
    int n,arr[50];
    printf("enter the number of element:");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("enter the element at index %d:",i);
        scanf("%d",&arr[i]);
    }
    printf("array before sorting:");
    print(arr,n);
    printf("array after sorting:");
    selection(arr,n);
    print(arr,n);
    return 0;
}
void print(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
}

void selection(int arr[],int n)
{
    
    for(int i=0;i<n-1;i++)
    {
        int min =i;
        for(int j=i+1;j<n;j++)
        {
          if(arr[j]<arr[min])
          {
            min=j;
          }
         
        }
         if(min!=i)
          {
            int temp=arr[min];
            arr[min]=arr[i];
            arr[i]=temp;
          }
    }
}