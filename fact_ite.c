/*Factorial of a number using iteratives*/
#include<stdio.h>
int main()
{
    int n,i;
    long int  fact=1;
    printf("Enter a number:");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        fact*=i;
    }
    printf("Factorial of %d=%ld",n,fact);
       return 0;
}
