#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int x;
    struct node *suiv;
} nd;

nd *gettail(nd *debut)
{
    nd *ptr=debut;
    while(ptr->suiv !=NULL)
        ptr=ptr->suiv;
    return ptr;
}

nd *partition(nd *debut,nd *end,nd **newdebut,nd **newend)
{
    nd *pivot=end;
    nd *ptr=debut;
    nd *prev=NULL;
    nd *tail=pivot;
    while(ptr!=pivot)
    {
        if(ptr->x < pivot->x)
        {
            if(*newdebut==NULL) *newdebut=ptr;
            prev=ptr;
            ptr=ptr->suiv;
        }
        else
        {
            if(prev!=NULL) prev->suiv=ptr->suiv;
            nd *temp=ptr->suiv;
            ptr->suiv=NULL;
            tail->suiv=ptr;
            tail=ptr;
            ptr=temp;
        }
    }
    if(*newdebut==NULL) *newdebut=pivot;
    *newend=tail;
    return pivot;
}

nd *qs(nd *debut,nd *end)
{
    if(debut==NULL || debut==end) return debut;
    nd *newdebut=NULL,*newend=NULL;
    nd *pivot=partition(debut,end,&newdebut,&newend);
    if(newdebut!=pivot)
    {
        nd *ptr=newdebut;
        while(ptr->suiv!=pivot) ptr=ptr->suiv;
        ptr->suiv=NULL;
        newdebut=qs(newdebut,ptr);
        ptr=gettail(newdebut);
        ptr->suiv=pivot;
    }
    pivot->suiv=qs(pivot->suiv,newend);
    return newdebut;
}

void quicksort(nd **debut)
{
    nd *tail=gettail(*debut);
    *debut=qs(*debut,tail);
    return;
}

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

void printlist(nd *debut)
{
    if(debut==NULL)
    {
        printf("NULL\n");
        return;
    }
    printf("%d->",debut->x);
    printlist(debut->suiv);
}

int main()
{
    nd *debut=NULL;
    debut=postadd(debut,2);
    debut=postadd(debut,5);
    debut=postadd(debut,1);
    debut=postadd(debut,4);
    debut=postadd(debut,3);
    printlist(debut);
    quicksort(&debut);
    printlist(debut);
    return 0;
}
