#include<stdio.h>
#include<stdlib.h>
void bubble(int arr[],int n);
void print_array(int arr[],int n);
int main()
{
    int n,arr[100];
    printf("enter the number of element:");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("enter the element at index %d:",i);
        scanf("%d",&arr[i]);
    }
    printf("array before sorting:");
    print_array(arr,n);
    bubble(arr,n);
    printf("\narray after sorting");
    print_array(arr,n);
    return 0;
}
void bubble(int arr[],int n)
{
    int i,j;
    for(int i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
       {
         if(arr[j]>arr[j+1])
        {
           int temp =arr[j];
           arr[j] =arr[j+1];
           arr[j+1] =temp;
        }
      }
    }
    
}
void print_array(int arr[],int n)
{
  for(int i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
}