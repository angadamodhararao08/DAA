#include<stdio.h>
#define size 10
void exchange(int a[],int b,int c)
{
    int temp;
    temp=a[b];
    a[b]=a[c];
    a[c]=temp;;
}
int partition(int a[],int l,int h)
{
    int x,i,j;
    x=a[h];
    i=l-1;
    for(j=l;j<=h-1;j++)
    {
        if(a[j]<=x)
        {
            i++;
            exchange(a,i,j);
        }
    }
    exchange(a,i+1,h);
    return i+1;
}

void quickSort(int a[],int l,int h)
{
    int q;
    if(l<h)
    {
        q=partition(a,l,h);
        quickSort(a,l,q-1);
        quickSort(a,q+1,h);
    }
}
void printArray(int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
}
int main()
{
    int i,n;
    int arr[size];
    printf("Enter the siz eof the array:");
    scanf("%d",&n);
    printf("Enter the %d elements of the array: ",n);
    for (i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("Array Before Sort:");
    printArray(arr,n);
    quickSort(arr,0,n-1);
    printf("\nArray After Sorting:");
    printArray(arr,n);
}
