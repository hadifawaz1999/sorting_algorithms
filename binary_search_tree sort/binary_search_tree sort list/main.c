#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int x;
    struct node *l,*r;
} nd;

typedef struct liste
{
    int x;
    struct liste *suiv;
} list;

list *postadd(list *debut,int x)
{
    if(debut==NULL)
    {
        debut=(list *)malloc(sizeof(list));
        debut->x=x;
        debut->suiv=NULL;
        return debut;
    }
    list *ptr=debut;
    while(ptr->suiv != NULL) ptr=ptr->suiv;
    list *nvnd=(list *)malloc(sizeof(list));
    nvnd->x=x;
    nvnd->suiv=NULL;
    ptr->suiv=nvnd;
    return debut;
}

void printlist(list *debut)
{
    if(debut==NULL)
    {
        printf("NULL\n");
        return;
    }
    printf("%d->",debut->x);
    printlist(debut->suiv);
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

void Inorder(list **debut,nd *tree)
{
    if(tree==NULL) return;
    Inorder(debut,tree->l);
    (*debut)=postadd(*debut,tree->x);
    Inorder(debut,tree->r);
}

void sortlist(list *debut)
{
    nd *tree=NULL;
    list *ptr=debut;
    while(ptr!=NULL)
    {
        Insert(&tree,ptr->x);
        ptr=ptr->suiv;
    }
    list *temp=NULL;
    Inorder(&temp,tree);
    list *p=debut,*q=temp;
    while(p!=NULL)
    {
        p->x=q->x;
        p=p->suiv;
        q=q->suiv;
    }
    return;
}

int main()
{
    list *debut=NULL;
    debut=postadd(debut,4);
    debut=postadd(debut,1);
    debut=postadd(debut,3);
    debut=postadd(debut,5);
    debut=postadd(debut,2);
    printlist(debut);
    sortlist(debut);
    printlist(debut);
    return 0;
}
