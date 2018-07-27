#ifndef DATEBASE_H_INCLUDED
#define DATEBASE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "List_L.h"
LNode *DATEBASE;//数据库

status CreatVoidDatebase();//新建一个空的数据库
status EnDate(int Number,char Name[20],char College[20],int Grade,char Speciality[20],int ClassNum,char Birth[20],char city[20]);//添加数据，标志位有OVERFLOW,ERROR,OK
status TraverseDate(status (*visit)(ElemType e));//遍历数据库
status show(ElemType e);//显示
void Sort();
char* IntToString(int n);//整型n转换为11个长度的字符串
status Save(LNode *list);//保存
status LoadDataToList(LNode* list);//读取
status LoadDatabase();//加载数据库，把CreatVoidDatebase和LoadDataToList装起来
#endif // DATEBASE_H_INCLUDED
