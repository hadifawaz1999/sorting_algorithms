#include <stdio.h>
#include <stdlib.h>

void sp(int *a,int *b)
{
    int temp=(*a);
    (*a)=(*b);
    (*b)=temp;
    return;
}

void quicksort(int A[],int left,int right)
{
    int test=0;
    if(left == right) return;
    int pivot,ipivot;
    pivot=A[left];
    ipivot=left;
    int i=left+1;
    int j=right;
    while(i<=j)
    {
        while(A[i]<pivot) i++;
        while(A[j]>pivot) j--;
        if(i<=j)
        {
            test+=1;
            sp(&A[i],&A[j]);
            i++;
            j--;
        }
        else
        {
            ipivot=j;
            sp(&A[left],&A[j]);
        }
    }
    if(ipivot-1>left) quicksort(A,left,ipivot-1);
    if(ipivot+1<right) quicksort(A,ipivot+1,right);
}

int main()
{
    int A[90]={3,2,1,4,5},i;
    quicksort(A,0,4);
    for(i=0;i<5;i++) printf("%d ",A[i]);
    return 0;
}
