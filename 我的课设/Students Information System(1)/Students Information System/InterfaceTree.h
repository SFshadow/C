#ifndef INTERFACETREE_H_INCLUDED
#define INTERFACETREE_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>

#define TURE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -1
typedef int Status;
typedef int TElemType;
typedef struct Tree
{
    TElemType data;
    struct Tree *firstChild,*nextSibling,*parent;
}Tree;


Status PreOrderTraveseTree(Tree *T,Status(*visit)(TElemType));//先序遍历树
Status Tshow(TElemType a);//显示
Tree* MakeTree(TElemType e,int n,...);//创建根节点e和n棵子树的树
Tree* Creatmenu();//创造我们的树
void Link(Tree **now,int nextStep);//链接全部子菜单
void MessageOfLink(int a);//错误提示
#endif // INTERFACETREE_H_INCLUDED
