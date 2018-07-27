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

//��ʾ����
void messages(int a)
{
    switch (a)
    {
        case 1:
        {
            system("cls");
        printf("\n\n                **********��ӭ����ѧ����Ϣ����ϵͳ**********\n\n\n");
        printf("                     1.������Ϣ\n");
        printf("                     2.��ʾȫ����Ϣ\n");
        printf("                     3.������Ϣ\n");
        printf("                     4.��ѧ��������Ϣ\n");
        printf("                     5.ͳ����Ϣ\n");
        printf("                     ��ѡ��");
        printf("\n\n                ********************************************\n\n\n");break;
        }
        case 2:
        {
         system("cls");
        printf("\n\n\n\n\n");
        printf("\t                 �ף���ӭ����������Ϣ���棡                    \n");
        printf("\t***************************************************************\n");
        printf("\t                        1.������Ϣ                            \n");
        printf("\t                        2.�����ϼ�                            \n");
        printf("\t***************************************************************\n");
        printf("\n\t�밴����Ӧ����ѡ���Ӧ���ܣ�");break;
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
            printf("\t                 �ף���ӭ����༭��Ϣ���棡                    \n");
            printf("\t***************************************************************\n");
            printf("\t                        1.�༭��Ϣ                            \n");
            printf("\t                        2.�����ϼ�                            \n");
            printf("\t***************************************************************\n");
            printf("\n\t�밴����Ӧ����ѡ���Ӧ���ܣ�");break;
        }
        case 5:
        {
            system("cls");
            printf("\n\n\n\n\n");
            printf("\t                 �ף���ӭ�������ѧ����Ϣ���棡                \n");
            printf("\t***************************************************************\n");
            printf("\t                         1.��ѧ�Ų�ѯ                          \n");
            printf("\t                                                               \n");
            printf("\t                         2.��������ѯ                          \n");
            printf("\t                                                               \n");
            printf("\t                         3.��רҵ�༶��ѯ                      \n");
            printf("\t                                                               \n");
            printf("\t                         0.����                                \n");
            printf("\t                                                               \n");
            printf("\t***************************************************************\n");
            printf("\n\t�밴����Ӧ����ѡ���Ӧ���ܣ�");break;
        }
        case 6:
        {
            system("cls");
            printf("\n\n\n\n\n");
            printf("\t                 �ף���ӭ����������Ϣ���棡                    \n");
            printf("\t***************************************************************\n");
            printf("\t                        1.������Ϣ                            \n");
            printf("\t                        2.����                            \n");
            printf("\t***************************************************************\n");
            printf("\n\t�밴����Ӧ����ѡ���Ӧ���ܣ�");
            break;
        }
        case 7:
        {
            system("cls");
            printf("\n\n\n\n\n");
            printf("\t                 �ף���ӭ����ͳ��ѧ����Ϣ���棡                    \n");
            printf("\t***************************************************************\n");
            printf("\t                         1.ͳ�ư������                              \n");
            printf("\t                                                               \n");
            printf("\t                         2.ͳ���꼶����                              \n");
            printf("\t                                                               \n");
            printf("\t                         3.ͳ��ѧԺ����                           \n");
            printf("\t                                                               \n");
            printf("\t                         0.����                           \n");
            printf("\t                                                               \n");
            printf("\t***************************************************************\n");
            printf("\n\t�밴����Ӧ����ѡ���Ӧ���ܣ�");break;
        }
        case 8:
        {
            system("cls");
            printf("\n\n\n\n\n");
            printf("\t                 �ף���ӭ���밴ѧ�Ų�����Ϣ���棡                    \n");
            printf("\t***************************************************************\n");
            printf("\n\t������Ҫ���ҵ�ѧ�ţ�");break;
        }
        case 9:
        {
            system("cls");
            printf("\n\n\n\n\n");
            printf("\t                 �ף���ӭ���밴����������Ϣ���棡                    \n");
            printf("\t***************************************************************\n");
            printf("\n\t������Ҫ���ҵ�������");break;
        }
        case 10:
        {
            system("cls");
            printf("\n\n\n\n\n");
            printf("\t                 �ף���ӭ���밴רҵ�༶������Ϣ���棡                    \n");
            printf("\t***************************************************************\n");
            printf("\n\t�밴����Ҫ��ֱ������꼶��רҵ�Ͱ༶��\n");break;
        }
        case 11:
        {
            system("cls");
            printf("\n\n\n\n\n");
            printf("\t***************************************************************\n");
            printf("\t                 �ף���ӭ����ͳ�ư���������棡                    \n");
            printf("\t***************************************************************\n");
            printf("\n\t�밴����Ҫ��ֱ������꼶��רҵ�Ͱ༶��\n");break;
        }
        case 12:
        {
            system("cls");
            printf("\n\n\n\n\n");
            printf("\t***************************************************************\n");
            printf("\t                 �ף���ӭ����ͳ���꼶�������棡                    \n");
            printf("\t***************************************************************\n");
            printf("\n\t������Ҫͳ�Ƶ��꼶��");break;
        }
        case 13:
        {
            system("cls");
            printf("\n\n\n\n\n");
            printf("\t***************************************************************\n");
            printf("\t                 �ף���ӭ����ͳ��ѧԺ�������棡                    \n");
            printf("\t***************************************************************\n");
            printf("\n\t������Ҫͳ�Ƶ�ѧԺ��");break;
        }
        case 14:
        {
            printf("\t������ѧ��:");break;
        }
        case 15:
        {
            printf("\t����������:");break;
        }
        case 16:
        {
            printf("\t������ѧԺ:");break;
        }
        case 17:
        {
            printf("\t�������꼶:");break;
        }
        case 18:
        {
            printf("\t������רҵ:");break;
        }
        case 19:
        {
            printf("\t������༶���:");break;
        }
        case 20:
        {
            printf("\t����������:");break;
        }
        case 21:
        {
            printf("\t���������:");break;
        }
        case 22:
        {
             printf("������ת���󣬴����Ϊ0x235\n");break;
        }
        case 23:
        {
            printf("\tͳ�ƽ��Ϊ��");break;
        }
        case 24:
        {
            printf("\t***************************************************************\n");
            printf("\t                ͳ����ɣ��밴��������ء�                   \n");
            break;
        }
        case 25:
        {
            printf("\t***************************************************************\n");
            printf("\t             ������ɲ����̣��밴��������ء�                   \n");
            break;
        }
        case 26:
        {
            printf("\t***************************************************************\n");
            printf("\t                   ������Ϣ��ɲ����̡�                        \n");
            break;
        }
        case 27:
        {
            printf("\t***************************************************************\n");
            printf("\t           ɾ����Ϣ��ɲ����̣��밴��������ء�                \n");
            break;
        }
        case 28:
        {
            printf("\n\n\n\n\n");
            printf("\t         �Ѿ��ҵ�ƥ�����Ϣ�������Ƿ���Ҫɾ�������Ϣ��         \n");
            printf("\t***************************************************************\n");
            printf("\t                         0.��                             \n");
            printf("\t                                                               \n");
            printf("\t                         1.��                              \n");
            printf("\t***************************************************************\n");
            printf("\n\t�����룺");break;
        }
        case 29:
        {
            printf("\t***************************************************************\n");
            printf("\t             �Ҳ���ƥ�����Ϣ���밴��������ء�                \n");
        }
        case 30:
        {
            printf("\t***************************************************************\n");
            printf("\t           ��л������˼���ǣ��밴��������ز˵���              \n");
        }
        case 50:
        {
            printf("\n\n\n\n\n");
            printf("\t                 �ף���ѡ����һ��������                    \n");
            printf("\t***************************************************************\n");
            printf("\t                         1.ɾ��                             \n");
            printf("\t                                                               \n");
            printf("\t                         2.�޸�                              \n");
            printf("\t                                                               \n");
            printf("\t                         0.����                           \n");
            printf("\t***************************************************************\n");
            printf("\n\t��������һ��������");break;
        }
        case 51:
        {
            printf("\t��������Ҫɾ����ѧ����Ӧ��ѧ��:");break;

        }
        case 52:
        {
            printf("\t��������Ҫ�޸ĵ�ѧ����Ӧ��ѧ��:");break;

        }
    }

}

void head()
{
    printf("***ѧ��\t����\tѧԺ\t�꼶\tרҵ\t�༶���\t����\t��ס��***\n");
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



