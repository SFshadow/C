#include <stdarg.h>
#include "InterfaceTree.h"

//Tree* PreOrderCreateTreeRecursion(char *definition,int *i,Tree *parent)
//{
//    Tree *T;
//    TElemType ch;
//    ch=definition[(*i)++];
//    if(ch=='#')T=NULL;
//    else
//    {
//		T=(Tree *)malloc(sizeof(Tree));
//		if(!T)exit(OVERFLOW);
//		T->data = ch;
//		T->parent=parent;
//        T->firstChild=PreOrderCreateTreeRecursion(definition,i,T);
//        T->nextSibling=PreOrderCreateTreeRecursion(definition,i,T);
//    }
//    return T;
//}
//
//Tree* PreOrderCreateTree(char *definition)
//{
//    int a;
//    return PreOrderCreateTreeRecursion(definition,&a,NULL);
//}

Status PreOrderTraveseTree(Tree *T,Status(*visit)(TElemType))
{
    if(T==NULL)return OK;
    if(visit(T->data)==ERROR)return ERROR;
    if(PreOrderTraveseTree(T->firstChild,visit)==ERROR)return ERROR;
    if(PreOrderTraveseTree(T->nextSibling,visit)==ERROR)return ERROR;
    return OK;
}

Status Tshow(TElemType a)
{
    printf("%d,",a);
    return OK;
}

Tree* MakeTree(TElemType e,int n,...)//创建根节点e和n棵子树的树
{
    int i;
    Tree *t,*p,*p1;
    va_list argptr;
    t=(Tree*)malloc(sizeof(Tree));
    if(NULL==t)return NULL;
    t->data=e;
    t->firstChild=t->nextSibling=NULL;
    if(n<=0)return t;
    va_start(argptr,n);
    p=va_arg(argptr,Tree*);
    t->firstChild=p;
    p->parent=t;
    p1=p;
    for(i=0;i<n-1;i++)
    {
        p=va_arg(argptr,Tree*);
        p1->nextSibling=p;
        p->parent=t;
        p1=p;
    }
    va_end(argptr);
    return t;
}

Tree* Creatmenu()
{
    Tree *p0,*p3[6],*p2[8],*p1[5];
    int i,j;
    p0=(Tree*)malloc(sizeof(Tree));
    j=0;
    for(i=15;i<=20;i++)
    {
        p3[j++]=MakeTree(i,0,NULL);
    }
    j=0;
    for(i=7;i<=14;i++)//i是树的数据域内容，j是第二层二维数组的编号
    {
        if(i==9)p2[j]=MakeTree(i,2,p3[0],p3[1]);
        else if(i==10)p2[j]=MakeTree(i,2,p3[2],p3[3]);
        else if(i==11)p2[j]=MakeTree(i,2,p3[4],p3[5]);
        else  p2[j]=MakeTree(i,0,NULL);
        j++;
    }
    j=0;
    for(i=2;i<=6;i++)//i是树的数据域内容，j是第二层二维数组的编号
    {
        if(i==3)p1[j]=MakeTree(i,2,p2[0],p2[1]);
        else if(i==4)p1[j]=MakeTree(i,3,p2[2],p2[3],p2[4]);
        else if(i==6)p1[j]=MakeTree(i,3,p2[5],p2[6],p2[7]);
        else  p1[j]=MakeTree(i,0,NULL);
        j++;
    }
    p0=MakeTree(1,5,p1[0],p1[1],p1[2],p1[3],p1[4]);
    return p0;
}

void Link(Tree **now,int nextStep)
{
    int i;
    int ReEntry,error;
    if(nextStep==0)
    {
        if((*now)->parent==NULL)MessageOfLink(3);
        else *now=(*now)->parent;
    }
    else
    {
        do
        {
            error=0;
            for(i=0;i<nextStep&&error==0;i++)
            {
                if(i==0)
                {
                    if((*now)->firstChild==NULL)error=1;
                    else *now=(*now)->firstChild;
                }
                else
                {
                    if((*now)->nextSibling==NULL)error=1;
                    else *now=(*now)->nextSibling;
                }
            }
            if(error==1)
            {
                if((*now)->firstChild==NULL)
                {
                    MessageOfLink(1);
                }
                else if((*now)->nextSibling==NULL)
                {
                    MessageOfLink(2);
                }
                ReEntry=1;
            }
            else ReEntry=0;
        }while(ReEntry);
    }
}

void MessageOfLink(int a)
{
    switch (a)
    {
        case 1:printf("没有下一级菜单了!\n");Sleep(1000);break;
        case 2:printf("输入出错。没有该选项，请看清楚再重新输入。\n");Sleep(1000);break;
        case 3:printf("没有上一级菜单了！\n");Sleep(1000);break;
        default:printf("发生什么事了？");Sleep(1000);
    }
}
