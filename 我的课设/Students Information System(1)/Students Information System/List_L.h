#ifndef LIST_L_H_INCLUDED
#define LIST_L_H_INCLUDED

#define TURE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define UNOPEN -2
typedef int status;
typedef struct ElemType
{
    int Number;             //ѧ��
    char Name[20];          //����
    char College[20];       //ѧԺ
    int Grade;          //�꼶
    char Speciality[20];    //רҵ
    int ClassNum;           //���
    char Birth[20];         //��������
    char city[20];          //��ס����
}ElemType;

typedef struct LNode
{
    ElemType date;
    struct LNode *next;
}LNode;

status InitList_L(LNode **l);//��ʼ��������־λ��OK,OVERFLOW
status EnList_L(LNode *l,ElemType e);//����������������
status deleteAfter_L(LNode *p,ElemType *e);//ɾ�����p���������ݴ�ŵ�e
status InsertAfter_L(LNode *p,LNode *p1);//�����ɽ��pl���뵽������p����
LNode* MakeNode_L(ElemType e);//����һ���ڵ�
status ListTraverse_L(LNode *l,status (*visit)(ElemType e));//��������

#endif // LIST_L_H_INCLUDED
