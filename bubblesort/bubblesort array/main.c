#include <stdio.h>
#include <stdlib.h>

void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
    return;
}

void bubblesort(int a[],int n)
{
    int i,j,temp;
    for(i=0;i<n;i++) for(j=0;j<n-1;j++) if(a[j]>a[j+1]) swap(&a[j],&a[j+1]);
    return;
}

int main()
{
    int n;
    scanf("%d",&n);
    int a[1000],i;
    for(i=0;i<n;i++) scanf("%d",&a[i]);
    bubblesort(a,n);
    for(i=0;i<n;i++) printf("%d ",a[i]);
    return 0;
}
