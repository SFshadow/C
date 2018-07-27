#ifndef QUANBAO_H_INCLUDED
#define QUANBAO_H_INCLUDED

#include "caowei.h"
#include "datebase.h"

int translat(int a);
void messages(int a);
void head();
status Mshow(ElemType e);
void SearchNumber(int Number);
void SearchName(char *Name);
void SearchClassroom(int Grade,int ClassNum,char *Speciality);
int StatisticOfClass(int Grade,char* Speciality,int ClassNum);
int StatisticOfGrade(int Grade);
int StatisticOfCollege(char College[]);

#endif // QUANBAO_H_INCLUDED
