#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int x;
    struct node *l,*r;
} nd;

nd *CREE(int x)
{
    nd *nvnd=(nd *)malloc(sizeof(nd));
    nvnd->x=x;
    nvnd->l=nvnd->r=NULL;
    return nvnd;
}

void Insert(nd **root,int x)
{
    if(*root==NULL)
    {
        *root=CREE(x);
        return;
    }
    nd *ptr=*root;
    nd *prev=*root;
    while(ptr!=NULL)
    {
        if(x<ptr->x)
        {
            prev=ptr;
            ptr=ptr->l;
        }
        else if(x>ptr->x)
        {
            prev=ptr;
            ptr=ptr->r;
        }
    }
    if(x<prev->x) prev->l=CREE(x);
    else if(x>prev->x) prev->r=CREE(x);
    return;
}

void inorder(nd *root)
{
    if(root==NULL) return;
    inorder(root->l);
    FILE *f;
    f=fopen("temp.txt","a");
    fprintf(f,"%d\n",root->x);
    fclose(f);
    inorder(root->r);
}

void bstsort()
{
    nd *tree=NULL;
    FILE *f,*g;
    f=fopen("Data.txt","r");
    int x;
    fscanf(f,"%d",&x);
    while(!feof(f))
    {
        Insert(&tree,x);
        fscanf(f,"%d",&x);
    }
    fclose(f);
    inorder(tree);
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
    return;
}

int main()
{
    FILE *f,*g;
    g=fopen("temp.txt","w");
    fclose(g);
    f=fopen("Data.txt","w");
    int x;
    scanf("%d",&x);
    while(x>0)
    {
        fprintf(f,"%d\n",x);
        scanf("%d",&x);
    }
    fclose(f);
    bstsort();
    return 0;
}
