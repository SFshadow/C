#include "caowei.h"
#include "string.h"
#include <stdio.h>
/*
用于定位链表中符合要求的节点，并返回指向该节点的指针
zeng是要查找的内容，按chaowei中的标记进行查找,其中运用到strcmp函数比较字符串的大小，条件如下若str1==str2，则返回零;
若str1>str2，则返回正数;
若str1<str2，则返回负数。
*/
LNode* Locate(LNode *list,char zeng[],char chaowei[])
{
     LNode *p;
    if(strcmp(chaowei,"Number")==0) /*按学号查询*/
    {
        p=list->next;/*把p接到链表开头的下一个节点，准备开始查询*/
        while(p)
        {
            if(xiaojianren(IntToString(p->date.Number),zeng)==0) /*若找到*/
                return p;
            p=p->next;/*一直往下找*/
        }
    }
    else if(strcmp(chaowei,"Name")==0)  /*按姓名查询*/
    {
        p=list->next;
        while(p)
        {
            if(paidaxing(p->date.Name,zeng)==0)    /*若找到*/
                return p;
            p=p->next;
        }
    }
     else if(strcmp(chaowei,"Speciality")==0)/*按专业查询*/
   {
      p=list->next;
     while(p)
       { if(xiaojianren(p->date.Speciality,zeng)==0)
           return p;
          p=p->next;
        }
    }
     else if(strcmp(chaowei,"Grade")==0)/*按年级查询*/
   {
      p=list->next;
     while(p)
       { if(xiaojianren(IntToString(p->date.Grade),zeng)==0)
           return p;
          p=p->next;
        }
    }
    else if(strcmp(chaowei,"ClassNum")==0)/*按班级查询*/
   {
      p=list->next;
     while(p)
       { if(xiaojianren(IntToString(p->date.ClassNum),zeng)==0)
           return p;
          p=p->next;
        }
    }
    else if(strcmp(chaowei,"College")==0)/*按学院查询*/
   {
      p=list->next;
     while(p)
       { if(paidaxing(p->date.College,zeng)==0)
           return p;
          p=p->next;
        }
    }
    return NULL; /*若未找到，返回一个空指针*/
}

/*想利用数据域中的数组进行比较，所以学号，姓名，专业班级都应该为字符串数组的形式,
其中学号和专业班级使用缺省查询，为xiaojianren函数*/
int xiaojianren(char baba[],char xiaokeai[14])
{
    int i=0,j=0;
	while(i<strlen(baba)&&j<strlen(xiaokeai))
	{
		if(baba[i]==xiaokeai[j])/*只要开头相同就返回一个0回去，在那边进行运算*/
		{
			i++;
			j++;
		}
		else
            return -1;
	}
    if(j>=strlen(xiaokeai))
        return 0;
    else
        return -1;
}

int paidaxing(char yeye[],char moren[14])/*设置模糊查询*/
{
    int i=0,j=0;
	while(i<strlen(yeye)&&j<strlen(moren))
	{
		if(yeye[i]==moren[j])
		{
			i++;
			j++;
		}
		else
		{
			i++;
		}
	}

	if(j>=strlen(moren))
		return 0;
    else
        return -1;
}

void StringInput(char *t,int lens,char *msg)
{
    char str[16];
    do
    {
        printf(msg);     /*显示提示信息*/
        scanf("%s",str);  /*输入字符串*/
        if(strlen(str)>lens)
            printf("\n input error! \n"); /*进行长度校验，超过lens值重新输入*/
    }while(strlen(str)>lens);
    strcpy(t,str); /*将输入的字符串拷贝到字符串t中*/
}

/*修改学生记录。先按输入的学号查询到该记录，然后提示用户修改学号之外的值，学号不能修改*/
void Modify(LNode *p)
{
    int grade,class;
        printf("学号:%u,\n",p->date.Number);
        printf("原姓名:%s,",p->date.Name);
       StringInput(p->date.Name,20,"请输入新的姓名:\n");
        printf("原学院:%s,",p->date.College);
        StringInput(p->date.College,20,"请输入新的学院:\n");
        printf("原年级:%d,",p->date.Grade);
        printf("请输入新的年级，范围在14-17:\n");
        scanf("%d",&grade);
        p->date.Grade=grade;
        printf("原专业:%s,",p->date.Speciality);
        StringInput(p->date.Speciality,20,"请输入新的专业:\n");
        printf("原班别:%d,",p->date.ClassNum);;
        printf("请输入新的班别，范围在1-10:\n");
        scanf("%d",&class);
        p->date.ClassNum=class;
        printf("原出生年月:%s,",p->date.Birth);
         StringInput(p->date.Birth,20,"请输入新的出生年月:\n");
        printf("原居住城市:%s,",p->date.city);
         StringInput(p->date.city,20,"请输入新的居住地址:\n");
        printf("\n=====>修改成功!\n");
}

status Delete(LNode *p)/*删除学生记录：先找到保存该学生记录的节点，然后删除节点*/
{
    LNode *r;
    r=DATEBASE;
    if(p==NULL)
    {
        return ERROR;
    }
    while(r->next!=p)
        r=r->next;
    r->next=p->next;/*将p所指的节点从链表中除去*/
    free(p);/*释放内存空间*/
    printf("\n   == == =>删除成功！\n");
    return OK;
}
