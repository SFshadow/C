#include "caowei.h"
#include "string.h"
#include <stdio.h>
/*
���ڶ�λ�����з���Ҫ��Ľڵ㣬������ָ��ýڵ��ָ��
zeng��Ҫ���ҵ����ݣ���chaowei�еı�ǽ��в���,�������õ�strcmp�����Ƚ��ַ����Ĵ�С������������str1==str2���򷵻���;
��str1>str2���򷵻�����;
��str1<str2���򷵻ظ�����
*/
LNode* Locate(LNode *list,char zeng[],char chaowei[])
{
     LNode *p;
    if(strcmp(chaowei,"Number")==0) /*��ѧ�Ų�ѯ*/
    {
        p=list->next;/*��p�ӵ�����ͷ����һ���ڵ㣬׼����ʼ��ѯ*/
        while(p)
        {
            if(xiaojianren(IntToString(p->date.Number),zeng)==0) /*���ҵ�*/
                return p;
            p=p->next;/*һֱ������*/
        }
    }
    else if(strcmp(chaowei,"Name")==0)  /*��������ѯ*/
    {
        p=list->next;
        while(p)
        {
            if(paidaxing(p->date.Name,zeng)==0)    /*���ҵ�*/
                return p;
            p=p->next;
        }
    }
     else if(strcmp(chaowei,"Speciality")==0)/*��רҵ��ѯ*/
   {
      p=list->next;
     while(p)
       { if(xiaojianren(p->date.Speciality,zeng)==0)
           return p;
          p=p->next;
        }
    }
     else if(strcmp(chaowei,"Grade")==0)/*���꼶��ѯ*/
   {
      p=list->next;
     while(p)
       { if(xiaojianren(IntToString(p->date.Grade),zeng)==0)
           return p;
          p=p->next;
        }
    }
    else if(strcmp(chaowei,"ClassNum")==0)/*���༶��ѯ*/
   {
      p=list->next;
     while(p)
       { if(xiaojianren(IntToString(p->date.ClassNum),zeng)==0)
           return p;
          p=p->next;
        }
    }
    else if(strcmp(chaowei,"College")==0)/*��ѧԺ��ѯ*/
   {
      p=list->next;
     while(p)
       { if(paidaxing(p->date.College,zeng)==0)
           return p;
          p=p->next;
        }
    }
    return NULL; /*��δ�ҵ�������һ����ָ��*/
}

/*�������������е�������бȽϣ�����ѧ�ţ�������רҵ�༶��Ӧ��Ϊ�ַ����������ʽ,
����ѧ�ź�רҵ�༶ʹ��ȱʡ��ѯ��Ϊxiaojianren����*/
int xiaojianren(char baba[],char xiaokeai[14])
{
    int i=0,j=0;
	while(i<strlen(baba)&&j<strlen(xiaokeai))
	{
		if(baba[i]==xiaokeai[j])/*ֻҪ��ͷ��ͬ�ͷ���һ��0��ȥ�����Ǳ߽�������*/
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

int paidaxing(char yeye[],char moren[14])/*����ģ����ѯ*/
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
        printf(msg);     /*��ʾ��ʾ��Ϣ*/
        scanf("%s",str);  /*�����ַ���*/
        if(strlen(str)>lens)
            printf("\n input error! \n"); /*���г���У�飬����lensֵ��������*/
    }while(strlen(str)>lens);
    strcpy(t,str); /*��������ַ����������ַ���t��*/
}

/*�޸�ѧ����¼���Ȱ������ѧ�Ų�ѯ���ü�¼��Ȼ����ʾ�û��޸�ѧ��֮���ֵ��ѧ�Ų����޸�*/
void Modify(LNode *p)
{
    int grade,class;
        printf("ѧ��:%u,\n",p->date.Number);
        printf("ԭ����:%s,",p->date.Name);
       StringInput(p->date.Name,20,"�������µ�����:\n");
        printf("ԭѧԺ:%s,",p->date.College);
        StringInput(p->date.College,20,"�������µ�ѧԺ:\n");
        printf("ԭ�꼶:%d,",p->date.Grade);
        printf("�������µ��꼶����Χ��14-17:\n");
        scanf("%d",&grade);
        p->date.Grade=grade;
        printf("ԭרҵ:%s,",p->date.Speciality);
        StringInput(p->date.Speciality,20,"�������µ�רҵ:\n");
        printf("ԭ���:%d,",p->date.ClassNum);;
        printf("�������µİ�𣬷�Χ��1-10:\n");
        scanf("%d",&class);
        p->date.ClassNum=class;
        printf("ԭ��������:%s,",p->date.Birth);
         StringInput(p->date.Birth,20,"�������µĳ�������:\n");
        printf("ԭ��ס����:%s,",p->date.city);
         StringInput(p->date.city,20,"�������µľ�ס��ַ:\n");
        printf("\n=====>�޸ĳɹ�!\n");
}

status Delete(LNode *p)/*ɾ��ѧ����¼�����ҵ������ѧ����¼�Ľڵ㣬Ȼ��ɾ���ڵ�*/
{
    LNode *r;
    r=DATEBASE;
    if(p==NULL)
    {
        return ERROR;
    }
    while(r->next!=p)
        r=r->next;
    r->next=p->next;/*��p��ָ�Ľڵ�������г�ȥ*/
    free(p);/*�ͷ��ڴ�ռ�*/
    printf("\n   == == =>ɾ���ɹ���\n");
    return OK;
}
