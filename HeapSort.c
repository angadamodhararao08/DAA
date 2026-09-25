//progarm to perform Heap Sort
#include<stdio.h>
#include<conio.h>
#define size 10
void swap(int i,int largest,int a[])
{
    int temp;
    temp=a[i];
    a[i]=a[largest];
    a[largest]=temp;
}
void maxHeapify(int a[],int n,int i)
{
    int largest=i;
    int left=2*i+1,right=2*i+2;
    if(left<n&&a[left]>a[largest])
        largest=left;
    if(right<n&&a[right]>a[largest])
        largest=right;
    if(largest!=i)
    {
        swap(i,largest,a);
        maxHeapify(a,n,largest);
    }
}
void buildMaxHeap(int a[],int n)
{
    int i;
    for(i=n/2-1;i>0;i--)
        maxHeapify(a,n,i);
}
void heapSort(int a[],int n)
{
    int i;
    buildMaxHeap(a,n);
    for(i=n-1;i>0;i--)
    {
        swap(0,i,a);
        maxHeapify(a,i,0);
    }
}
void printArray(int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
}
int main()
{
    int n,i;
    int arr[size];
    printf("Enter the size of the Array:");
    scanf("%d",&n);
    printf("Enter the %d elements of the Array:",n);
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("Array Elements Before Sort:");
    printArray(arr,n);
    buildMaxHeap(arr,n);
    heapSort(arr,n);
    printf("\nArray Elements After Sort:");
    printArray(arr,n);
}
