#ifndef DATEBASE_H_INCLUDED
#define DATEBASE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "List_L.h"
LNode *DATEBASE;//���ݿ�

status CreatVoidDatebase();//�½�һ���յ����ݿ�
status EnDate(int Number,char Name[20],char College[20],int Grade,char Speciality[20],int ClassNum,char Birth[20],char city[20]);//������ݣ���־λ��OVERFLOW,ERROR,OK
status TraverseDate(status (*visit)(ElemType e));//�������ݿ�
status show(ElemType e);//��ʾ
void Sort();
char* IntToString(int n);//����nת��Ϊ11�����ȵ��ַ���
status Save(LNode *list);//����
status LoadDataToList(LNode* list);//��ȡ
status LoadDatabase();//�������ݿ⣬��CreatVoidDatebase��LoadDataToListװ����
#endif // DATEBASE_H_INCLUDED
