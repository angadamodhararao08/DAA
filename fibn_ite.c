#include<stdio.h>
int main()
{
    int i,n,a=0,b=1,c;
    printf("Enter the number of digits:");
    scanf("%d",&n);
    printf("Fibonaci series=");
    for(i=1;i<=n;i++)
    {
       printf("%d\t",a);
       c=a+b;
       a=b;
       b=c;
    }
}
