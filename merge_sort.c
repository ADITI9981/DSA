#include<stdio.h>
#include<stdlib.h>
void merge_sort(int arr[],int lb,int ub);
void merge(int arr[],int l,int mid,int r);
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
    merge_sort(arr,0,n);
    print_array(arr,n);
    return 0;
}

void merge_sort(int arr[],int lb,int ub)
{
   if(lb<ub)
   {
    int mid=(lb+ub)/2;
    merge_sort(arr,0,mid);
    merge_sort(arr,mid+1,ub);
    merge(arr,lb,mid,ub);

   }

}

void merge(int arr[],int l,int mid,int r)
{
   int n1,n2;
   n1=mid-l+1;
   n2=r-mid;
   int L[n1],R[n2];
   
   for(int i=0;i<n1;i++)
   {
    L[i]=arr[l+i];
   }
   for(int i=0;i<n2;i++)
   {
    R[i]=arr[mid+1+i];
   }

   int i=0,j=0,k=l;
   while(i<n1 && j<n2)
   {
    if(L[i]<=R[j])
    {
        arr[k]=L[i];
       
        i++;
    }
    else{
        arr[k]=R[j];
        j++;
    }
    k++;
   }
   while(i<n1)
   {
    arr[k]=L[i];
    i++;
    k++;
   }
   while(j<n2)
   {
    arr[k]=R[j];
    j++;
    k++;
   }

}

void print_array(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("\t%d\t",arr[i]);
    }
}