#include<stdio.h>
#include<stdlib.h>
int fibonacci_search(int arr[],int n);
int min(int x1,int x2)
{
    if(x1<x2)
      return x1;
    else 
      return x2;
}
int main()
{
    int n,arr[100];
    printf("enter the number of element:");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("enter the element of index %d:",i);
        scanf("%d",&arr[i]);
    }
    printf("array is:");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
    
    int pos = fibonacci_search(arr, n);
    if(pos >= 0)
        printf("\nThe element is found at index %d", pos);
    else
        printf("\nUnsuccessful Search");

    return 0;
}

int fibonacci_search(int arr[],int n)
{
    int s,offset =-1;
    printf("enter the element to search:");
    scanf("%d",&s);
    int f1=0;
    int f2=1;
    int fm=f1+f2;
    while(fm<n)
    {
        f1=f2;
        f2=fm;
        fm=f1+f2;
    }
    while(fm>1)
    {
     int i=min(offset+f1,n-1);
     
     if (s>arr[i])
     {
        fm = f2;
        f2 = f1;
        f1 = fm -f2;
        offset = i;
     }
     else if(s<arr[i])
     {
       fm = f1;
       f2 = f2-f1;
       f1 = fm-f2; 
     }
     else{
        return i;
     }

    }

}