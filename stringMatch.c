#include<stdio.h>
#include<string.h>
#define size1 20
#define size2 10
int stringMatching(char T[],char P[])
{
   int n=strlen(T);
   int m=strlen(P);
   int i,j;
   for(i=0;i<=n-m;i++)
   {
       j=0;
       while(j<m&&(P[j]==T[i+j]))
       {
           j++;
       }
       if(j==m)
        return i;
   }
   return -1;
}
int main()
{
    int n1,n2,result;
    char Text[size1],Pattern[size2];
    printf("Enter the Text string:");
    scanf("%s",Text);
    printf("Enter the Pattern string:");
    scanf("%s",Pattern);
    n1=strlen(Text);
    n2=strlen(Pattern);
    result=stringMatching(Text,Pattern);
    if(result!=-1)
        printf("Given pattern(%s) matched with text(%s) from %d th index",Pattern,Text,result);
    else
        printf("Given pattern(%s) is not matched with the text(%s)",Pattern,Text);
    return 0;
}
