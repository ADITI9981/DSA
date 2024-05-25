#include<stdio.h>
int main()
{
    int n,arr[100];
    printf("enter the number of elements:");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("enter the element %d :",i);
        scanf("%d",&arr[i]);
    }
    printf("array is:");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
    
    int l= linear_search(arr,n);
    if(l == -1)
    {
        printf("element is not present in the list");
    }
    else{
        printf("element is found at index : %d",l);
    }
    return 0;
}

int linear_search(int arr[],int n)
{
    int i,s;
    printf("\nenter the element to search: ");
    scanf("%d",&s);
    for(i=0;i<n;i++)
    {
        if(arr[i] == s)
        {
            return i;
        }
        
    }
   return -1;
}