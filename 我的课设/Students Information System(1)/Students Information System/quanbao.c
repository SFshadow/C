#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "quanbao.h"
#include "string.h"

int translat(int a)
{
   int next,Number,ClassNum,Grade,sure;
   char Name[20],College[20],Speciality[20],Birth[20],city[20];
   LNode *p=DATEBASE;
   switch (a)
   {
       case 1:messages(1);scanf("%d",&next);
              return next;
       case 2:
           messages(14);scanf("%d",&Number);
           messages(15);scanf("%s",Name);
           messages(16);scanf("%s",College);
           messages(17);scanf("%d",&Grade);
           messages(18);scanf("%s",Speciality);
           messages(19);scanf("%d",&ClassNum);
           messages(20);scanf("%s",Birth);
           messages(21);scanf("%s",city);
           EnDate(Number,Name,College,Grade,Speciality,ClassNum,Birth,city);
           Save(DATEBASE);
           messages(26);Sleep(1000);
           return 0;
       case 3:
            messages(3);TraverseDate(Mshow);
            messages(50);scanf("%d",&next);
            return next;
       case 4:
            messages(5);
            scanf("%d",&next);
            return next;
       case 5:
            messages(6);
            Sort();
            messages(25);
            Save(DATEBASE);
            return 0;
       case 6:
            messages(7);
            scanf("%d",&next);
            return next;
       case 7:
       case 15:
       case 17:
           messages(51);
           scanf("%d",&Number);
           p=Locate(p,IntToString(Number),"Number");
           if(p!=NULL)
           {
               messages(28);
               scanf("%d",&sure);
               if(sure)
               {
                   Delete(p);
                    Save(DATEBASE);
                    messages(27);
               }
               else messages(30);
           }
           else messages(29);
           getchar();getchar();
           return 0;
       case 8:
       case 16:
       case 18:
           messages(52);
           scanf("%d",&Number);
           p=Locate(p,IntToString(Number),"Number");
           if(p!=NULL)
                Modify(p);
            Save(DATEBASE);
           return 0;
       case 9:
           messages(8);scanf("%d",&Number);head();SearchNumber(Number);
           messages(50);scanf("%d",&next);
           return next;
       case 10:
           messages(9);scanf("%s",Name);head();SearchName(Name);
           messages(50);scanf("%d",&next);
           return next;
       case 11:
           messages(10);
           messages(17);scanf("%d",&Grade);
           messages(18);scanf("%s",Speciality);
           messages(19);scanf("%d",&ClassNum);
           head();SearchClassroom(Grade,ClassNum,Speciality);
           messages(50);scanf("%d",&next);
           return next;
       case 12:
            messages(11);
            messages(17);scanf("%d",&Grade);
            messages(18);scanf("%s",Speciality);
            messages(19);scanf("%d",&ClassNum);
            messages(23);printf("%d\n",StatisticOfClass(Grade,Speciality,ClassNum));
            messages(24);getchar();getchar();
            return 0;
       case 13:
            messages(12);scanf("%d",&Grade);
            messages(23);printf("%d\n",StatisticOfGrade(Grade));
            messages(24);getchar();getchar();
            return 0;
       case 14:
            messages(13);scanf("%s",College);
            messages(23);printf("%d\n",StatisticOfCollege(College));
            messages(24);getchar();getchar();
            return 0;
       case 19:
           messages(51);
           scanf("%d",&Number);
           p=Locate(p,IntToString(Number),"Number");
           if(p!=NULL)
                Delete(p);
            Save(DATEBASE);
           return 0;
       case 20:
           messages(52);
           scanf("%d",&Number);
           p=Locate(p,IntToString(Number),"Number");
           if(p!=NULL)
                Modify(p);
            Save(DATEBASE);
           return 0;
       default:messages(22);return ERROR;
   }
   return ERROR;
}

//提示函数
void messages(int a)
{
    switch (a)
    {
        case 1:
        {
            system("cls");
        printf("\n\n                **********欢迎进入学生信息管理系统**********\n\n\n");
        printf("                     1.新添信息\n");
        printf("                     2.显示全部信息\n");
        printf("                     3.查找信息\n");
        printf("                     4.按学号重排信息\n");
        printf("                     5.统计信息\n");
        printf("                     请选择：");
        printf("\n\n                ********************************************\n\n\n");break;
        }
        case 2:
        {
         system("cls");
        printf("\n\n\n\n\n");
        printf("\t                 亲，欢迎进入新添信息界面！                    \n");
        printf("\t***************************************************************\n");
        printf("\t                        1.新添信息                            \n");
        printf("\t                        2.返回上级                            \n");
        printf("\t***************************************************************\n");
        printf("\n\t请按下相应数字选择对应功能：");break;
        }
        case 3:
        {
            system("cls");
            head();break;
        }
        case 4:
        {
            system("cls");
            printf("\n\n\n\n\n");
            printf("\t                 亲，欢迎进入编辑信息界面！                    \n");
            printf("\t***************************************************************\n");
            printf("\t                        1.编辑信息                            \n");
            printf("\t                        2.返回上级                            \n");
            printf("\t***************************************************************\n");
            printf("\n\t请按下相应数字选择对应功能：");break;
        }
        case 5:
        {
            system("cls");
            printf("\n\n\n\n\n");
            printf("\t                 亲，欢迎进入查找学生信息界面！                \n");
            printf("\t***************************************************************\n");
            printf("\t                         1.按学号查询                          \n");
            printf("\t                                                               \n");
            printf("\t                         2.按姓名查询                          \n");
            printf("\t                                                               \n");
            printf("\t                         3.按专业班级查询                      \n");
            printf("\t                                                               \n");
            printf("\t                         0.返回                                \n");
            printf("\t                                                               \n");
            printf("\t***************************************************************\n");
            printf("\n\t请按下相应数字选择对应功能：");break;
        }
        case 6:
        {
            system("cls");
            printf("\n\n\n\n\n");
            printf("\t                 亲，欢迎进入排序信息界面！                    \n");
            printf("\t***************************************************************\n");
            printf("\t                        1.排序信息                            \n");
            printf("\t                        2.返回                            \n");
            printf("\t***************************************************************\n");
            printf("\n\t请按下相应数字选择对应功能：");
            break;
        }
        case 7:
        {
            system("cls");
            printf("\n\n\n\n\n");
            printf("\t                 亲，欢迎进入统计学生信息界面！                    \n");
            printf("\t***************************************************************\n");
            printf("\t                         1.统计班别人数                              \n");
            printf("\t                                                               \n");
            printf("\t                         2.统计年级人数                              \n");
            printf("\t                                                               \n");
            printf("\t                         3.统计学院人数                           \n");
            printf("\t                                                               \n");
            printf("\t                         0.返回                           \n");
            printf("\t                                                               \n");
            printf("\t***************************************************************\n");
            printf("\n\t请按下相应数字选择对应功能：");break;
        }
        case 8:
        {
            system("cls");
            printf("\n\n\n\n\n");
            printf("\t                 亲，欢迎进入按学号查找信息界面！                    \n");
            printf("\t***************************************************************\n");
            printf("\n\t请输入要查找的学号：");break;
        }
        case 9:
        {
            system("cls");
            printf("\n\n\n\n\n");
            printf("\t                 亲，欢迎进入按姓名查找信息界面！                    \n");
            printf("\t***************************************************************\n");
            printf("\n\t请输入要查找的姓名：");break;
        }
        case 10:
        {
            system("cls");
            printf("\n\n\n\n\n");
            printf("\t                 亲，欢迎进入按专业班级查找信息界面！                    \n");
            printf("\t***************************************************************\n");
            printf("\n\t请按以下要求分别输入年级、专业和班级：\n");break;
        }
        case 11:
        {
            system("cls");
            printf("\n\n\n\n\n");
            printf("\t***************************************************************\n");
            printf("\t                 亲，欢迎进入统计班别人数界面！                    \n");
            printf("\t***************************************************************\n");
            printf("\n\t请按以下要求分别输入年级、专业和班级：\n");break;
        }
        case 12:
        {
            system("cls");
            printf("\n\n\n\n\n");
            printf("\t***************************************************************\n");
            printf("\t                 亲，欢迎进入统计年级人数界面！                    \n");
            printf("\t***************************************************************\n");
            printf("\n\t请输入要统计的年级：");break;
        }
        case 13:
        {
            system("cls");
            printf("\n\n\n\n\n");
            printf("\t***************************************************************\n");
            printf("\t                 亲，欢迎进入统计学院人数界面！                    \n");
            printf("\t***************************************************************\n");
            printf("\n\t请输入要统计的学院：");break;
        }
        case 14:
        {
            printf("\t请输入学号:");break;
        }
        case 15:
        {
            printf("\t请输入姓名:");break;
        }
        case 16:
        {
            printf("\t请输入学院:");break;
        }
        case 17:
        {
            printf("\t请输入年级:");break;
        }
        case 18:
        {
            printf("\t请输入专业:");break;
        }
        case 19:
        {
            printf("\t请输入班级编号:");break;
        }
        case 20:
        {
            printf("\t请输入生日:");break;
        }
        case 21:
        {
            printf("\t请输入城市:");break;
        }
        case 22:
        {
             printf("程序跳转错误，错误号为0x235\n");break;
        }
        case 23:
        {
            printf("\t统计结果为：");break;
        }
        case 24:
        {
            printf("\t***************************************************************\n");
            printf("\t                统计完成，请按任意键返回。                   \n");
            break;
        }
        case 25:
        {
            printf("\t***************************************************************\n");
            printf("\t             排序完成并存盘，请按任意键返回。                   \n");
            break;
        }
        case 26:
        {
            printf("\t***************************************************************\n");
            printf("\t                   新添信息完成并存盘。                        \n");
            break;
        }
        case 27:
        {
            printf("\t***************************************************************\n");
            printf("\t           删除信息完成并存盘，请按任意键返回。                \n");
            break;
        }
        case 28:
        {
            printf("\n\n\n\n\n");
            printf("\t         已经找到匹配的信息，请问是否真要删除这个信息？         \n");
            printf("\t***************************************************************\n");
            printf("\t                         0.否                             \n");
            printf("\t                                                               \n");
            printf("\t                         1.是                              \n");
            printf("\t***************************************************************\n");
            printf("\n\t请输入：");break;
        }
        case 29:
        {
            printf("\t***************************************************************\n");
            printf("\t             找不到匹配的信息，请按任意键返回。                \n");
        }
        case 30:
        {
            printf("\t***************************************************************\n");
            printf("\t           感谢您的深思熟虑，请按任意键返回菜单。              \n");
        }
        case 50:
        {
            printf("\n\n\n\n\n");
            printf("\t                 亲，请选择下一步操作！                    \n");
            printf("\t***************************************************************\n");
            printf("\t                         1.删除                             \n");
            printf("\t                                                               \n");
            printf("\t                         2.修改                              \n");
            printf("\t                                                               \n");
            printf("\t                         0.返回                           \n");
            printf("\t***************************************************************\n");
            printf("\n\t请输入下一步操作：");break;
        }
        case 51:
        {
            printf("\t请输入您要删除的学生相应的学号:");break;

        }
        case 52:
        {
            printf("\t请输入您要修改的学生相应的学号:");break;

        }
    }

}

void head()
{
    printf("***学号\t姓名\t学院\t年级\t专业\t班级编号\t生日\t居住地***\n");
}

status Mshow(ElemType e)
{
    printf("%u\t%s\t%s\t%d\t%s\t%d\t%s\t%s\n",e.Number,e.Name,e.College,e.Grade,e.Speciality,e.ClassNum,e.Birth,e.city);
    return OK;
}


void SearchNumber(int Number)
{
    LNode *p;
    p=DATEBASE;
    while(p!=NULL)
    {
        p=Locate(p,IntToString(Number),"Number");
        if(p!=NULL)
        {
             Mshow(p->date);
        }
    }

}

void SearchName(char *Name)
{
    LNode *p;
    p=DATEBASE;
    while(p!=NULL)
    {
        p=Locate(p,Name,"Name");
        if(p!=NULL)
        {
             Mshow(p->date);
        }
       }

}

void SearchClassroom(int Grade,int ClassNum,char *Speciality)
{
    LNode *p;
    p=DATEBASE;
    while(p!=NULL)
    {
        p=Locate(p,Speciality,"Speciality");
        if(p!=NULL)
        {
             if(p->date.Grade==Grade&&p->date.ClassNum==ClassNum)Mshow(p->date);
        }
    }
}

int StatisticOfClass(int Grade,char* Speciality,int ClassNum)
{
    LNode *p;
    int i=0;
    p=DATEBASE;
    while(p!=NULL)
    {
        p=Locate(p,Speciality,"Speciality");
        if(p!=NULL)
        {
             if(p->date.Grade==Grade&&p->date.ClassNum==ClassNum)i++;
        }
    }
    return i;
}

int StatisticOfGrade(int Grade)
{
    int i=0;
    LNode *p;
    p=DATEBASE;
    while(p!=NULL)
    {
        p=Locate(p,IntToString(Grade),"Grade");
        if(p!=NULL)
        {
            i++;
        }
       }
    return i;
}

int StatisticOfCollege(char College[])
{
    int i=0;
    LNode *p;
    p=DATEBASE;
    while(p!=NULL)
    {
        p=Locate(p,College,"College");
        if(p!=NULL)
        {
            i++;
        }
    }
    return i;
}



