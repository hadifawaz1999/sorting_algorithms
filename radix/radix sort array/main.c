#include <stdio.h>
#include <stdlib.h>

void printarray(int A[],int n)
{
    int i;
    for(i=0;i<n;i++) printf("%d ",A[i]);
    puts("");
    return;
}

int convert_Decimal_to_Binary(int a)
{
    int b,i=1,res=0;
    while(a>0)
    {
        b=(a%2);
        res+=(b*i);
        i*=10;
        a/=2;
    }
    return res;
}

int convert_Binary_to_Decimal(int a)
{
    int res=0,b,i=0;
    while(a>0)
    {
        b=a%10;
        res+=(b*pow(2,i));
        i+=1;
        a/=10;
    }
    return res;
}

//k starts with 1 than 10 than 100... kermel e5od l unite byrj3 l dizaine... ta 2arenon sawa
void radixsort(int A[],int B[],int n,int k)
{
    int i=0,j=0,test=1;
    for(i=0;i<n;i++)
    {
        if((A[i]/k)%10==0)
        {
            B[j]=A[i];
            j+=1;
        }
    }
    for(i=0;i<n;i++)
    {
        if((A[i]/k)%10==1)
        {
            B[j]=A[i];
            j+=1;
        }
    }
    for(i=0;i<n;i++)
    {
        A[i]=B[i];
        if(A[i]/k !=0) test=0;
    }
    if(!test) radixsort(A,B,n,k*10);
}

int main()
{
    int n,A[1000],B[1000],i;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&A[i]);
    printf("Before:\n");
    printarray(A,n);
    for(i=0;i<n;i++) A[i]=convert_Decimal_to_Binary(A[i]);
    radixsort(A,B,n,1);
    for(i=0;i<n;i++) A[i]=convert_Binary_to_Decimal(A[i]);
    printf("After:\n");
    printarray(A,n);
    return 0;
}
