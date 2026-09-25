#include<stdio.h>
int Fibn(int n)
{
    if(n==0)
        return 0;
    else if(n==1)
        return 1;
    else
        return Fibn(n-1)+Fibn(n-2);
}
int main()
{
    int n,i;
    printf("Enter the number of digits:");
    scanf("%d",&n);
    printf("Fibonaci series=");
    for(i=0;i<n;i++)
    {
    printf("%d\t",Fibn(i));
    }
    return 0;
}
