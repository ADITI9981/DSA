#include<stdio.h>
#include<stdlib.h>
void quick(int arr[],int lb,int ub);
void print_array(int arr[],int n);
int partition(int arr[],int lb,int ub);
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
    
    printf("unsorted array:");
    print_array(arr,n);
    quick(arr,0,n-1);
    printf("sorted array");
    print_array(arr,n);
    return 0;
}
void quick(int arr[],int lb,int ub)
{
  if(lb<ub)
  {
    int pivot = partition(arr,lb,ub);
    quick(arr,lb,pivot-1);
    quick(arr,pivot+1,ub);
  }
}
void print_array(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
}
int partition(int arr[],int lb,int ub)
{
  int pivot = arr[lb];
  int start = lb;
  int end = ub;
  while(start<end)
 { 
    while(arr[start]<=pivot)
   {
    start++;
   }
  while(arr[end]>pivot)
   {
    end--;
   }
   if(start<end)
   {
    int temp=arr[start];
    arr[start]=arr[end];
    arr[end]=temp;
   }
   
 }
  arr[lb]=arr[end];
 arr[end]=pivot;
 return end;
}