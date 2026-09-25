#include<stdio.h>
#define size 10
int main()
{
    int i,n,key,k=0;
    int a[size];
    printf("Enter the size of array:");
    scanf("%d",&n);
    printf("Enter the %d elements of Array:",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Array Elements:");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\nEnter the element to search:");
    scanf("%d",&key);
    for(i=0;i<n;i++)
    {
        if(key==a[i]){
            k++;
            break;
        }
    }
    if(k==1)
      printf("%d is found at %dth position",key,i+1);
    else
        printf("%d is not found",key);
    return 0;



}
