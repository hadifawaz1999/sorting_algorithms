#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int x;
    struct node *l,*r;
} nd;

void printarray(int *A,int n)
{
    int i=0;
    for(i=0;i<n;i++) printf("%d ",*(A+i));
    puts("");
    return;
}

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

void Inorder(nd *root,int *A,int *i)
{
    if(root==NULL) return;
    Inorder(root->l,A,i);
    *(A+ *i)=root->x;
    *i= *i+1;
    Inorder(root->r,A,i);
}

void sort(int *A,int n)
{
    nd *tree=NULL;
    int i=0;
    Insert(&tree,*(A+i));
    for(i=1;i<n;i++) Insert(&tree,*(A+i));
    i=0;
    Inorder(tree,A,&i);
    return;
}

int main()
{
    int n,x,*A;
    printf("n=");
    scanf("%d",&n);
    A=(int *)malloc(n*sizeof(int));
    int i=0;
    for(i=0;i<n;i++) scanf("%d",A+i);
    printarray(A,n);
    sort(A,n);
    printarray(A,n);
    return 0;
}
