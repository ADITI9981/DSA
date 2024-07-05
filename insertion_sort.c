#include<stdio.h>
#include<stdlib.h>
void insertion(int arr[],int n);
void print_array(int arr[],int n);
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
    print_array(arr,n);
    printf("\narray after sorting:");
    insertion(arr,n);
    print_array(arr,n);
    return 0;
}

void print_array(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("\t%d\t",arr[i]);
    }
}

void insertion(int arr[],int n)
{
    int i,j,key;
    for(i=1;i<n;i++)
    {
        j=i-1;
        key=arr[i];
        while(j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
}