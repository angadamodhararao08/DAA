#include<stdio.h>
#define size 10
int bsearch(int a[],int l,int h,int key,int n)
{
   if(l>h)
    return -1;
   int mid=(l+h)/2;
   if(key==a[mid])
   {
       return mid;
   }
   else if(key<a[mid])
    return bsearch(a,l,mid-1,key,n);
   else
    return bsearch(a,mid+1,h,key,n);
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
    k=bsearch(a,0,n-1,key,n);
    if(k==-1)
        printf("%d is not found",key);
    else
        printf("%d found at %dth position",key,k+1);
    return 0;
}
