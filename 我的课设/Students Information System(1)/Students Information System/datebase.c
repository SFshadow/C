#include <string.h>
#include <stdio.h>
#include "datebase.h"

status CreatVoidDatebase()
{
    DATEBASE=NULL;
    if(InitList_L(&DATEBASE)==OVERFLOW)return OVERFLOW;
    else return OK;
}

status EnDate(int Number,char Name[20],char College[20],int Grade,char Speciality[20],int ClassNum,char Birth[20],char city[20])
{
    ElemType e;
    e.Number=Number;
    strncpy(e.Name,Name,20);
    strncpy(e.College,College,20);
    e.Grade=Grade;
    strncpy(e.Speciality,Speciality,20);
    e.ClassNum=ClassNum;
    strncpy(e.Birth,Birth,20);
    strncpy(e.city,city,20);
    if(DATEBASE==NULL)return ERROR;
    if(EnList_L(DATEBASE,e)==OVERFLOW)return OVERFLOW;
    return OK;
}

status TraverseDate(status (*visit)(ElemType e))
{
    if(ListTraverse_L(DATEBASE,visit)==ERROR)return ERROR;
    return OK;
}

status show(ElemType e)
{
    printf("Number:%u\n",e.Number);
    printf("Name:%s\n",e.Name);
    printf("College:%s\n",e.College);
    printf("Grade:%d\n",e.Grade);
    printf("College:%s\n",e.Speciality);
    printf("ClassNum:%d\n",e.ClassNum);
    printf("Birth:%s\n",e.Birth);
    printf("city:%s\n",e.city);
    printf("\n");
    return OK;
}

void Sort()
{
    LNode* first; /*为原链表剩下用于直接插入排序的节点头指针*/
    LNode* t; /*临时指针变量：插入节点*/
    LNode* p; /*临时指针变量*/
    LNode* q; /*临时指针变量*/
    if(DATEBASE ->next==NULL) return;
    first = DATEBASE ->next; /*原链表剩下用于直接插入排序的节点链表*/
    DATEBASE ->next=NULL;
    while (first != NULL) /*遍历剩下无序的链表*/
    {
        t=first;
        first=first->next;
        t->next=NULL;
        p= DATEBASE;
        if(p->next==NULL)
        {
            p->next=t;
        }
        else
        {
            q=p->next;
            while(q!=NULL && t->date.Number >  q->date.Number )
            {
                p=p->next;
                q=p->next;
            }
            t->next=p->next;
            p->next=t;
        }
    }
    printf("\n    =====>排序成功!\n");
}

char* IntToString(int n)//整型n转换为11个长度的字符串
{
    char *str;
    str=(char*)malloc(11*sizeof(char));
    sprintf(str,"%u",n);
    return str;
}

status LoadDataToList(LNode* list)
{
	FILE *fp;
	LNode *p,*r;
	int count=0;  /*保存文件中的记录条数（或结点个数）*/
	r=list;
	fp=fopen("student.txt","ab+");
	if(fp==NULL)
	{
        return UNOPEN;
	}
	while(! feof(fp))
	{
		p=(LNode*)malloc(sizeof(LNode));
		if(!p)
		{
			return  OVERFLOW;
		}
		if(fread(p,sizeof(LNode),1,fp)==1)/*一次从文件中读取一条学生成绩记录*/
		{
			p->next=NULL;
			r->next=p;
			r=p;
			count++;
		}
	}
		fclose(fp);
		printf("\n== == =>初始化成功，%d条记录被调入\n",count);
		return OK;
}

status Save(LNode *list)
{
	FILE *fp;
	LNode *p;
	int count=0;
	fp=fopen("student.txt","wb");
	if(fp==NULL)       /*打开文件失败*/
	{
		return UNOPEN;
	}
	rewind(fp);
	p=list->next;
	while(p)
	{
		if(fwrite(p,sizeof(LNode),1,fp)==1)/*每次写一条记录或一个节点信息至文件*/
		{
			p=p->next;
			count ++;
		}
		else
			break;
	}
	if(count>0)
	{
	    printf("写入了%d条\n",count);
	}
	else
	{
	    return ERROR;
	}
	fclose(fp);/*关闭此文件*/
	return OK;
}

status LoadDatabase()
{
    CreatVoidDatebase();
    if(LoadDataToList(DATEBASE)==OK)return OK;
    return ERROR;
}
