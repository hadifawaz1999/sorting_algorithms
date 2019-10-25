#include <stdio.h>
#include <stdlib.h>

typedef struct noeud
{
    int x;
    struct noeud *suiv;
} nd;

nd *postadd(nd *debut,int x)
{
    if(debut==NULL)
    {
        debut=(nd *)malloc(sizeof(nd));
        debut->x=x;
        debut->suiv=NULL;
        return debut;
    }
    nd *ptr=debut;
    while(ptr->suiv!=NULL) ptr=ptr->suiv;
    nd *nvnd=(nd *)malloc(sizeof(nd));
    nvnd->x=x;
    nvnd->suiv=NULL;
    ptr->suiv=nvnd;
    return debut;
}

nd *mergelist(nd *a,nd *b)
{
    nd *c=NULL;
    if(a==NULL) return b;
    if(b==NULL) return a;
    if(a->x <= b->x)
    {
        c=(nd *)malloc(sizeof(nd));
        c->x=a->x;
        c->suiv=mergelist(a->suiv,b);
    }
    else
    {
        c=(nd *)malloc(sizeof(nd));
        c->x=b->x;
        c->suiv=mergelist(a,b->suiv);
    }
    return c;
}

void splitlist(nd *debut,nd **a,nd **b)
{
    nd *fast,*slow;

    slow=debut;
    fast=debut->suiv;

    while(fast!=NULL)
    {
        fast=fast->suiv;
        if(fast!=NULL)
        {
            fast=fast->suiv;
            slow=slow->suiv;
        }
    }
    *a=debut;
    *b=slow->suiv;
    slow->suiv=NULL;
    return;
}

void mergesortlist(nd **debut)
{
    nd *temp=*debut;
    nd *a=NULL;
    nd *b=NULL;
    if(temp==NULL || temp->suiv==NULL) return;
    splitlist(temp,&a,&b);
    mergesortlist(&a);
    mergesortlist(&b);
    *debut=mergelist(a,b);
    return;
}

void printlist(nd *debut)
{
    if(debut==NULL)
    {
        printf("NULL.\n");
        return;
    }
    printf("%d->",debut->x);
    printlist(debut->suiv);
}

int main()
{
    nd *debut=NULL;
    debut=postadd(debut,4);
    debut=postadd(debut,2);
    debut=postadd(debut,1);
    debut=postadd(debut,5);
    debut=postadd(debut,3);
    printf("Liste originalle:\n");
    printlist(debut);
    mergesortlist(&debut);
    printf("Liste triee:\n");
    printlist(debut);
    return 0;
}
