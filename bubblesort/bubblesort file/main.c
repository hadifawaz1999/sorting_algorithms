#include <stdio.h>
#include <stdlib.h>

void bubblesort()
{
    FILE *f,*g;
    int x,y,test=0;
    while(1)
    {
        test=0;
        f=fopen("Data.txt","r");
        g=fopen("temp.txt","w");
        fscanf(f,"%d",&x);
        fscanf(f,"%d",&y);
        while(!feof(f))
        {
            if(x>y)
            {
                test+=1;
                fprintf(g,"%d\n",y);
                fscanf(f,"%d",&y);
            }
            else
            {
                fprintf(g,"%d\n",x);
                x=y;
                fscanf(f,"%d",&y);
            }
        }
        fprintf(g,"%d\n",x);
        fclose(f);
        fclose(g);
        f=fopen("Data.txt","w");
        g=fopen("temp.txt","r");
        fscanf(g,"%d",&x);
        while(!feof(g))
        {
            fprintf(f,"%d\n",x);
            fscanf(g,"%d",&x);
        }
        fclose(f);
        fclose(g);
        if(!test) break;
    }
    return;
}

int main()
{
    int x;
    FILE *f;
    f=fopen("Data.txt","w");
    scanf("%d",&x);
    while(x>0)
    {
        fprintf(f,"%d\n",x);
        scanf("%d",&x);
    }
    fclose(f);
    bubblesort();

    return 0;
}
