#include <stdio.h>
#include <stdlib.h>

int split(int a[],int start,int end)
{
    int pivot=a[start];
    int i=start;
    int j=end;
    int temp;
    while(i<j)
    {
        while(a[i]<=pivot && i<=end) i+=1;
        while(a[j]>pivot && j>=0) j-=1;
        if(i<j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    temp=a[start];
    a[start]=a[j];
    a[j]=temp;
    return j;
}

void quicksort(int a[],int start,int end)
{
    if(start<end)
    {
        int j=split(a,start,end);
        quicksort(a,start,j-1);
        quicksort(a,j+1,end);
    }
}

int main()
{
    int n;
    int a[10000];
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++) scanf("%d",&a[i]);
    quicksort(a,0,n-1);
    for(i=0;i<n;i++) printf("%d ",a[i]);
    return 0;
}
