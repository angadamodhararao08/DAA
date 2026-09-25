#include<stdio.h>
void towerOfHonoi(int n,char from_rod,char to_rod,char aux_rod)
{
    if(n==1)
    {
        printf("Move disk 1 from %c rod to %c rod\n",from_rod,to_rod);
        return;
    }
    towerOfHonoi(n-1,from_rod,aux_rod,to_rod);
    printf("Move disk %d from %c rod to %c rod\n",n,from_rod,to_rod);
    towerOfHonoi(n-1,aux_rod,to_rod,from_rod);
}
int main()
{
    int n;
    printf("Enter the number of plates:");
    scanf("%d",&n);
    if(n<=0)
        printf("Invalid number of plates\n");
    else
    {
        printf("Perform the following  sequence of steps\n");
        //S is source rod,D is destination rod &A is auxilary rod
        towerOfHonoi(n,'S','D','A');
    }
    return 0;
}
