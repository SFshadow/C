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
    int Number;             //学号
    char Name[20];          //名字
    char College[20];       //学院
    int Grade;          //年级
    char Speciality[20];    //专业
    int ClassNum;           //班别
    char Birth[20];         //出生年月
    char city[20];          //居住城市
}ElemType;

typedef struct LNode
{
    ElemType date;
    struct LNode *next;
}LNode;

status InitList_L(LNode **l);//初始化链表，标志位有OK,OVERFLOW
status EnList_L(LNode *l,ElemType e);//在链表最后插入数据
status deleteAfter_L(LNode *p,ElemType *e);//删除结点p，并把数据存放到e
status InsertAfter_L(LNode *p,LNode *p1);//把自由结点pl插入到链表结点p后面
LNode* MakeNode_L(ElemType e);//生成一个节点
status ListTraverse_L(LNode *l,status (*visit)(ElemType e));//遍历链表

#endif // LIST_L_H_INCLUDED
