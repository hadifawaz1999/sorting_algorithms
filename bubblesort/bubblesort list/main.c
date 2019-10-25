#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int x;
    struct node *suiv;
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

void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
    return;
}

void bubblesortlist(nd *debut)
{
    nd *ptr1,*ptr2,*ptr3;
    int temp;
    ptr1=debut;
    while(ptr1!=NULL)
    {
        ptr2=debut;
        while(ptr2->suiv!=NULL)
        {
            ptr3=ptr2->suiv;
            if(ptr2->x > ptr3->x)
            {
                temp=ptr2->x;
                ptr2->x=ptr3->x;
                ptr3->x=temp;
            }
            ptr2=ptr2->suiv;
        }
        ptr1=ptr1->suiv;
    }
    return;
}

int main()
{
    nd *debut=NULL;
    debut=postadd(debut,4);
    debut=postadd(debut,2);
    debut=postadd(debut,5);
    debut=postadd(debut,1);
    debut=postadd(debut,3);
    printf("avant:\n");
    printlist(debut);
    printf("apres:\n");
    bubblesortlist(debut);
    printlist(debut);
    return 0;
}
