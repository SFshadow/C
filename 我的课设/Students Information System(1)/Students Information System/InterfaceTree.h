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


Status PreOrderTraveseTree(Tree *T,Status(*visit)(TElemType));//���������
Status Tshow(TElemType a);//��ʾ
Tree* MakeTree(TElemType e,int n,...);//�������ڵ�e��n����������
Tree* Creatmenu();//�������ǵ���
void Link(Tree **now,int nextStep);//����ȫ���Ӳ˵�
void MessageOfLink(int a);//������ʾ
#endif // INTERFACETREE_H_INCLUDED
