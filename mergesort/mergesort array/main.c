#include <stdio.h>
#include <stdlib.h>

void merge(int *A,int l,int m,int r)
{
    int s1=m-l+1;
    int s2=r-m;
    int i,j,k;
    int *L,*R;
    L=(int *)malloc(s1*sizeof(int));
    R=(int *)malloc(s2*sizeof(int));
    for(i=0;i<s1;i++) *(L+i) = *(A+i+l);
    for(j=0;j<s1;j++) *(R+j) = *(A+j+m+1);
    i=0;
    j=0;
    k=l;
    while(i<s1 && j<s2)
    {
        if(*(L+i) <= *(R+j))
        {
            *(A+k) = *(L+i);
            i+=1;
        }
        else
        {
            *(A+k) = *(R+j);
            j+=1;
        }
        k+=1;
    }
    while(i<s1)
    {
        *(A+k) = *(L+i);
        k+=1;
        i+=1;
    }
    while(j<s2)
    {
        *(A+k) = *(R+j);
        j+=1;
        k+=1;
    }
}

void mergesort(int *A,int l,int r)
{
    if(l<r)
    {
        int m=(l+r)/2;
        mergesort(A,l,m);
        mergesort(A,m+1,r);
        merge(A,l,m,r);
    }
    return;
}

int main()
{
    int *A,i,n;
    scanf("%d",&n);
    A=(int *)malloc(sizeof(int)*n);
    for(i=0;i<n;i++) scanf("%d",A+i);

    mergesort(A,0,n-1);
    for(i=0;i<n;i++) printf("%d ",*(A+i));
    return 0;
}
