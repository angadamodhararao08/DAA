/*Factorial of a number using Recursion*/
#include<stdio.h>
int Fact(int n)
{
    if(n==0)
        return 1;
    else if(n==1)
        return 1;
    else return n*Fact(n-1);
}
int main()
{
    int n;
    long int fact;
    printf("Enter the value for n:");
    scanf("%d",&n);
    printf("Factorial of %d=%ld",n,Fact(n));
    return 0;
}
