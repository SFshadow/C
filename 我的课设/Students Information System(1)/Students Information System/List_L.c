#include <stdio.h>
#include <stdlib.h>
#include "List_L.h"

status InitList_L(LNode **l)
{
    *l=(LNode*)malloc(sizeof(LNode));
    if((*l)==NULL)return OVERFLOW;
    (*l)->next=NULL;
    return OK;
}//头链表为空，数据从第二个链表开始存放

status EnList_L(LNode *l,ElemType e)
{
    LNode *p,*t;
    p=(LNode*)malloc(sizeof(LNode));
    if(p==NULL)return OVERFLOW;
    p->date=e;
    p->next=NULL;
    t=l;
    while(t->next!=NULL)
        t=t->next;
    t->next=p;
    return OK;
}

status deleteAfter_L(LNode *p,ElemType *e)
{
    LNode *q;
    q=p->next;
    if(q==NULL)return ERROR;
    *e=q->date;
    if(q->next==NULL)
        p->next=NULL;
    else
        p->next=q->next;
    free(q);
    return OK;
}

status InsertAfter_L(LNode *p,LNode *p1)
{
    LNode *p0;
    if(p->next==NULL)
        p->next=p1;
    else
    {
        p0=p->next;
        p->next=p1;
        p1->next=p0;
    }
    return OK;
}

LNode* MakeNode_L(ElemType e)
{
    LNode* p;
    p=(LNode*)malloc(sizeof(LNode));
    if(p==NULL)return NULL;
    p->date=e;
    p->next=NULL;
    return p;
}

status ListTraverse_L(LNode *l,status (*visit)(ElemType e))
{
    LNode *p;
    p=l->next;
    if(p==NULL)return ERROR;
    while(p->next!=NULL)
    {
        if(visit(p->date)==ERROR)return ERROR;
        p=p->next;
    }
    if(visit(p->date)==ERROR)return ERROR;
    return OK;
}
