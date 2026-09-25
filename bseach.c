#include<stdio.h>
#define size 10
int bsearch(int a[],int l,int h,int key)
{
    int mid;
    while(l<=h)
    {
        mid=(l+h)/2;
        if(key==a[mid])
            return mid;
        else if(key<a[mid])
            h=mid-1;
        else
            l=mid+1;
    }
    return -1;
}
int main()
{
    int n,i,key,k;
    int a[size];
    printf("Enter the size of array:");
    scanf("%d",&n);
    printf("Enter the %d Array elements in sorted order:",n);
    for(i=0;i<n;i++)
    {
       scanf("%d",&a[i]);
    }
    printf("Array elements:");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\nEnter the element to search: ");
    scanf("%d",&key);
    k=bsearch(a,0,n-1,key);
    if(key!=-1)
        printf("%d found at %dth position",key,k+1);
    else
        printf("%d is not found",key);
}
