#include <stdio.h>

void Split()
{
    FILE *f,*f1,*f2;
    int a=-1,x,prec;
    f=fopen("Data.txt","r");
    f1=fopen("temp1.txt","w");
    f2=fopen("temp2.txt","w");
    fscanf(f,"%d",&x);
    while(1)
    {
        while(!feof(f))
        {
            prec=x;
            fprintf(f1,"%d\n",x);
            fscanf(f,"%d",&x);
            if(prec>x) break;
        }
        fprintf(f1,"%d\n",a);
        if(x<0) fscanf(f,"%d",&x);
        if(feof(f)) break;
        while(!feof(f))
        {
            prec=x;
            fprintf(f2,"%d\n",x);
            fscanf(f,"%d",&x);
            if(prec>x) break;
        }
        fprintf(f2,"%d\n",a);
        if(x<0) fscanf(f,"%d",&x);
        if(feof(f)) break;
    }
    fclose(f);
    fclose(f1);
    fclose(f2);
    return;
}

void MergeFiles()
{
    FILE *f,*f1,*f2;
    f=fopen("Data.txt","w");
    f1=fopen("temp1.txt","r");
    f2=fopen("temp2.txt","r");
    int a=-1,x1,x2;
    fscanf(f1,"%d",&x1);
    fscanf(f2,"%d",&x2);
    while(!feof(f1) && !feof(f2))
    {
        while(x1>=0 && x2>=0)
        {
            if(x1<x2)
            {
                fprintf(f,"%d\n",x1);
                fscanf(f1,"%d",&x1);
            }
            else
            {
                fprintf(f,"%d\n",x2);
                fscanf(f2,"%d",&x2);
            }
        }
        while(x1>=0)
        {
            fprintf(f,"%d\n",x1);
            fscanf(f1,"%d",&x1);
        }
        while(x2>=0)
        {
            fprintf(f,"%d\n",x2);
            fscanf(f2,"%d",&x2);
        }
        fprintf(f,"%d\n",a);
        fscanf(f1,"%d",&x1);
        fscanf(f2,"%d",&x2);
    }
    while(!feof(f1) && x1>=0)
    {
        fprintf(f,"%d\n",x1);
        fscanf(f1,"%d",&x1);
    }
    while(!feof(f2) && x2>=0)
    {
        fprintf(f,"%d\n",x2);
        fscanf(f2,"%d",&x2);
    }
    fprintf(f,"%d\n",a);
    fclose(f);
    fclose(f1);
    fclose(f2);
    return;
}

int test_if_sorted()
{
    FILE *f2=fopen("temp2.txt","r");
    int x;
    fscanf(f2,"%d",&x);
    if(x==-1)
    {
        fclose(f2);
        return 1;
    }
    else
    {
        fclose(f2);
        return 0;
    }
}

void MergeSortFile()
{
    Split();
    while(test_if_sorted()==0)
    {
        MergeFiles();
        Split();
    }
    return;
}

int main()
{
    FILE *f=fopen("Data.txt","w");
    int x;
    scanf("%d",&x);
    while(x>=0)
    {
        fprintf(f,"%d\n",x);
        scanf("%d",&x);
    }
    fclose(f);
    MergeSortFile();
    FILE *t=fopen("temp.txt","w");
    f=fopen("Data.txt","r");
    fscanf(f,"%d",&x);
    while(!feof(f) && x>=0)
    {
        fprintf(t,"%d\n",x);
        fscanf(f,"%d",&x);
    }
    fclose(f);
    fclose(t);
    f=fopen("Data.txt","w");
    t=fopen("temp.txt","r");
    fscanf(t,"%d",&x);
    while(!feof(t))
    {
        fprintf(f,"%d\n",x);
        fscanf(t,"%d",&x);
    }
    fclose(f);
    fclose(t);
    return 0;
}
