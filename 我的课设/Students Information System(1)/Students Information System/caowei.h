#ifndef CAOWEI_H_INCLUDED
#define CAOWEI_H_INCLUDED

#include "datebase.h"
LNode* Locate(LNode *list,char zeng[],char chaowei[]);
int xiaojianren(char baba[],char xiaokeai[14]);
int paidaxing(char yeye[],char moren[14]);
void StringInput(char *t,int lens,char *msg);
void Modify(LNode *p);
status Delete(LNode *p);

#endif // CAOWEI_H_INCLUDED
