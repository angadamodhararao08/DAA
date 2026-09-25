#include<stdio.h>
#include<stdlib.h>
#define size 10
void merge(int a[],int l,int mid,int h)
{
    int i,j,k;
    int n1=mid-l+1;  //size of left sub array
    int n2=h-mid;    //size of right sub array
    //Creating temporary arrays
    int *L=(int*)malloc(n1*sizeof(int));
    int *R=(int*)malloc(n2*sizeof(int));
    //Copy data to temporary arrays
    for(i=0;i<n1;i++)
        L[i]=a[l+i];
    for(j=0;j<n2;j++)
        R[j]=a[mid+1+j];
    //Merge tempoeary arrays back into actual array
    i=0;  //initialize index of left sub array
    j=0;  //initialize index of right sun array
    k=l;  //initialize index of merged sub array
    while(i<n1&&j<n2)
    {
        if(L[i]<R[j])
        {
            a[k]=L[i];
            i++;
        }
        else
        {
            a[k]=R[j];
            j++;
        }
        k++;
    }
    //copying remaining elememts of L[] if any
    while(i<n1)
    {
        a[k]=L[i];
        i++;k++;
    }
    //copying elements of R[] if any
    while(j<n2)
    {
        a[k]=R[j];
        j++;k++;
    }
    free(L);free(R);
}
void mergeSort(int a[],int l,int h)
{
    int mid;
    if(l<h)
    {   //calculating middle
        mid=(l+h)/2;
        //sort first and second halves
        mergeSort(a,l,mid);
        mergeSort(a,mid+1,h);
        //merge the sorted halves
        merge(a,l,mid,h);
    }
}
void printArray(int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}
int main()
{
    int i,n;
    int arr[size];
    printf("Enter the siz of Array:");
    scanf("%d",&n);
    printf("Enter the %d elements of array:",n);
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("Array Before Sorting:");
    printArray(arr,n);
    mergeSort(arr,0,n-1);
    printf("\nArray After Sorting:");
    printArray(arr,n);
    return 0;
}
