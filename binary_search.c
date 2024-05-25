#include<stdio.h>

int binarysearch(int l, int r, int data, int arr[])
{
    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (arr[mid] == data)
            return mid;

        if (arr[mid] < data)
            l = mid + 1;

        else
            r = mid - 1;
    }
    return -1;
}

int main()
{
    int N, data;
    int arr[100];

    printf("Enter the number of elements: ");
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        printf("Enter element %d: ", i);
        scanf("%d", &arr[i]);
    }

    printf("Array is: ");
    for (int i = 0; i < N; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");

    printf("Enter the data to search: ");
    scanf("%d", &data);

    int l = 0;
    int r = N - 1;
    int result = binarysearch(l, r, data, arr);

    if (result != -1)
    {
        printf("Element is found at index: %d\n", result);
    }
    else
    {
        printf("Element not found in the array.\n");
    }

    return 0;
}