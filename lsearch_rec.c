#include<stdio.h>
#define size 10
int search(int a[],int n,int key,int i)
{
   if(key==a[i])
   {
       return i;
   }
   else if(i>n)
    return -1;
   else
    return search(a,n,key,i+1);
}
int main()
{
    int n,i,key,k;
    int a[size];
    printf("Enter the size of Array:");
    scanf("%d",&n);
    printf("Enter the %d elements of Array:",n);
    for(i=0;i<n;i++)
    {
       scanf("%d",&a[i]);
    }
    printf("Array Elememts:");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\nEnter the element to search:");
    scanf("%d",&key);
    k=search(a,n,key,0);
    if(k!=-1)
        printf("%d found at %dth postion",key,k+1);
    else
        printf("%d is not in the Array of elements");
    return 0;
}
