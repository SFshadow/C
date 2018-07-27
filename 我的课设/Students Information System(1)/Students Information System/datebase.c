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
    LNode* first; /*Ϊԭ����ʣ������ֱ�Ӳ�������Ľڵ�ͷָ��*/
    LNode* t; /*��ʱָ�����������ڵ�*/
    LNode* p; /*��ʱָ�����*/
    LNode* q; /*��ʱָ�����*/
    if(DATEBASE ->next==NULL) return;
    first = DATEBASE ->next; /*ԭ����ʣ������ֱ�Ӳ�������Ľڵ�����*/
    DATEBASE ->next=NULL;
    while (first != NULL) /*����ʣ�����������*/
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
    printf("\n    =====>����ɹ�!\n");
}

char* IntToString(int n)//����nת��Ϊ11�����ȵ��ַ���
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
	int count=0;  /*�����ļ��еļ�¼���������������*/
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
		if(fread(p,sizeof(LNode),1,fp)==1)/*һ�δ��ļ��ж�ȡһ��ѧ���ɼ���¼*/
		{
			p->next=NULL;
			r->next=p;
			r=p;
			count++;
		}
	}
		fclose(fp);
		printf("\n== == =>��ʼ���ɹ���%d����¼������\n",count);
		return OK;
}

status Save(LNode *list)
{
	FILE *fp;
	LNode *p;
	int count=0;
	fp=fopen("student.txt","wb");
	if(fp==NULL)       /*���ļ�ʧ��*/
	{
		return UNOPEN;
	}
	rewind(fp);
	p=list->next;
	while(p)
	{
		if(fwrite(p,sizeof(LNode),1,fp)==1)/*ÿ��дһ����¼��һ���ڵ���Ϣ���ļ�*/
		{
			p=p->next;
			count ++;
		}
		else
			break;
	}
	if(count>0)
	{
	    printf("д����%d��\n",count);
	}
	else
	{
	    return ERROR;
	}
	fclose(fp);/*�رմ��ļ�*/
	return OK;
}

status LoadDatabase()
{
    CreatVoidDatebase();
    if(LoadDataToList(DATEBASE)==OK)return OK;
    return ERROR;
}
