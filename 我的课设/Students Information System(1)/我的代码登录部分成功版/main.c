#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<conio.h>
#define N 50


int RENSHU;

struct manager
{
	char name[20];
	char mima[20];

}mag[N];


void all();    // ���ȫ��ѧ����Ϣ
void xiugai();  // �޸�ѧ����Ϣ
void zengjia();  //  ����ѧ����Ϣ
void shanchu();  //  ɾ��ѧ����Ϣ
void chaxun();  //  ��Ҫ���ѯѧ����Ϣ
void pailie();  //   ��Ҫ������ѧ����Ϣ
void tongji();  //   ��Ҫ��ͳ��ѧ��
void tuichu();  //    �˳�

void  denglu();  //  ��¼
void  menu();   //   ���˵�
void guanli();  //   ����
void zhuce();  //   ע��
void change();  //  �޸�����

    int main()
{ denglu();
  return 0;
}


/**********************************��¼����**************************************/
    void denglu()
{
    printf("\n\n                **********��ӭ����ѧ����Ϣ����ϵͳ**********\n\n\n");
    printf("                     1.����Ա��¼\n");
    printf("                     2.�û�ע��\n");
    printf("                     3.�޸�����\n");
    printf("                    ��ѡ��");
    	while(1)                                                                          //����ѡ���ܵĺ������Ӷ�������һ������
	{
		int choose;
 	    scanf("%d",&choose);
        switch(choose)
		{
		case  1:guanli();break;                                                   //ѡ���Թ���Ա��ݽ���ϵͳ
		case  2:zhuce();break;
         case 3: change();break;                                               //ѡ���޸ĵ���ݽ���ϵͳ
		default:printf("\n\t �����������������룺");break;while(1);	                     //�����������֣�����б���ͬʱwhile�����в���ѭ��
		}
	}

}

/**********************************����Ա��¼����**************************************/
void guanli()
{ system("cls");
    FILE *x;
    int i;
	char yh[20];
    char m[20];
	printf("\n\n\n\n\n");
	printf("\t***************************************************************\n");
	printf("			      ��ӭ��������Ա��½����   \n");
	printf("\t***************************************************************\n");
	printf("			       ���������û���������\n");
    printf("\t�û�����");
    scanf("%s",yh);
    printf("\t���룺");
    scanf("%s",m);
	x=fopen("manager.txt","rb");
	for(i=0;i<50;i++)
	{
	    fread(&mag[i],sizeof(struct manager),1,x);
        if((strcmp(yh,mag[i].name)==0) && (strcmp(m,mag[i].mima)==0))
        {
            printf("\n			     ��¼�ɹ���\n");
            printf("			  2S���Զ����������桭����\n");
            fclose(x);
            Sleep(2000);
            system("cls");                                                                        //��ͣ2S
            menu();                                                                             //�������˵�����
        }
        else                                                                                  //�������Ҫ�����������ѡ��
        {
            printf("\t\t\t�˻����������,������;\n");
            printf("\t\t\t��1����������\n");
             system("cls");
        }
	}
}


/**********************************����Աע�����**************************************/

void zhuce()                                                                           //ע����溯��
{
    system("cls");                                                                     //����
    FILE*x;
    FILE*y;
    int i;
    char choose1[20];
    char choose2[20];
    y=fopen("number.txt","r");
    fscanf(y,"%d",&RENSHU);
    fclose(y);
	printf("\n\n\n\n\n");
	printf("\t***************************************************************\n");
	printf("\t              ��ӭ��������Ա��ע��ҳ��\n");
	printf("\t***************************************************************\n");
	printf("\t���������½������û���:");
   x=fopen("manager.txt","rb");
    for(i=0;i<RENSHU;i++)
    {fread(&mag[i],sizeof(struct manager),1,x);
    }
    fclose(x);
    int flag=1;
    while (flag)                                                                  //��־λ�������ж�������û����Ƿ��Ѿ���ע���
	{
	    scanf("%s",choose1);




      for(i=0;i<RENSHU;i++)
			 {

			    if(strcmp(mag[i].name,choose1)==0)                                  //ɸѡ�Ƿ���ڴ��˺ţ��Ƚ������ַ���
			{
				printf("\n\n\n\n\n");
				printf("\t***************************************************************\n");
				printf("		                    ע��ҳ�� \n");
				printf("\t***************************************************************\n");
				printf("			   ���û����Ѵ���,���������룡\n");
				Sleep(300);                                                            //��ʱ300mS
				printf("���������µ��û���:");
				flag=1;                                        //�û�������ʱ��Ҫ���������������û���


			}
			else flag=0;


			 }
     }






	strcpy(mag[RENSHU].name,choose1);                                                //��¼�û�������choose1���Ƶ�name��	                                                                                   //�����¼���飬���ֻ��6λ����
	printf("\t����(�������Ϊ10λ):");
	scanf("%s",choose2);
	strcpy(mag[RENSHU].mima,choose2);
    x=fopen("manager.txt","ab");
    fwrite(&mag[RENSHU],sizeof(struct manager),1,x);
	fclose(x);
	RENSHU++;
	y=fopen("number.txt","wb");
	fprintf(y,"%d",RENSHU);
	fclose(y);
	printf("\n			      ���ע��ɹ���\n");
	printf("			  2S���Զ����е�¼���桭����\n");

	Sleep(2000);
	 system("cls");                                                                         //��ͣ2S
	denglu();                                                                          //�����½����
}

/**********************************���˵�����**************************************/
menu()
{
    printf("\n\n                **********��ӭ����ѧ����Ϣ����ϵͳ**********\n\n\n");
    printf("                     1.�鿴����ѧ����Ϣ\n");
    printf("                     2.����ѧ����Ϣ\n");
    printf("                     3.ɾ��ѧ����Ϣ\n");
    printf("                     4.��Ҫ���ѯѧ����Ϣ\n");
    printf("                     5.��Ҫ������ѧ����Ϣ\n");
    printf("                     6.��Ҫ��ͳ��ѧ����Ϣ\n");
    printf("                     7.�˳�\n");
    printf("                    ��ѡ��");
    while(1)                                                                           //����ѡ���ܵĺ���
			{
				int choose;
				scanf("%d",&choose);
				switch(choose)
				{
		          case 1: all();break;                                                    //�鿴����
		          case 2: zengjia();break;
		          case 3: paixu();break;
		          case 4: chaxun(); break;
		          case 5: paixu();break;
		          case 6: tongji();break;
		          case 7: tuichu();break;                                                 //���ص�¼��ҳ
		          default:printf("\t �����������������룺");break;	                    //�����������֣�����б���ͬʱwhile�����в���ѭ��
				}
			}
}

/**********************************�޸��������**************************************/
change()
{
     system("cls");                                                                     //����
     FILE*x;
     FILE*y;
     int i;
     y=fopen("number.txt","r");
    fscanf(y,"%d",&RENSHU);
    fclose(y);
	printf("\n\n\n\n\n");
	printf("\t***************************************************************\n");
	printf("\t              ��ӭ�����޸�����ҳ��\n");
	printf("\t***************************************************************\n");
	printf("\t���������޸ĵ��û���:");
   char choose1[20];
   char choose2[20];
   fflush(stdin);                                                                //��־λ�������ж�������û����Ƿ��Ѿ���ע���
	scanf("%s",choose1);
	printf("\t����������û���ԭʼ����:");
	fflush(stdin);
    scanf("%s",choose2);
    fflush(stdin);
    x=fopen("manager.txt","rb");
		   for(i=0;i<RENSHU;i++)
       {
           fread(&mag[i],sizeof(struct manager),1,x);
       }
       int flag=1;
       while(flag)
       {
           for(i=0;i<RENSHU;i++)
           {
               if((strcmp(choose1,mag[i].name)==0) && (strcmp(choose2,mag[i].mima)==0))                               //ɸѡ�Ƿ���ڴ��˺ţ��Ƚ������ַ���
			    {
			    printf("\t����������û���������:");
                char choose3[10];
                scanf("%s",choose3);
                 strcpy(mag[i].mima,choose3);
                 fclose(x);
                x=fopen("manager.txt","wb");
                for(i=0;i<RENSHU;i++)
               {
                   fwrite(&mag[i],sizeof(struct manager),1,x);
               }
               fclose(x);
                printf("\n			      �����޸ĳɹ���\n");
	            printf("			  2S���Զ����й�����桭����\n");
	            Sleep(2000);
	            flag=0;                                                                       //��ͣ2S
	            guanli();
                }

            }
                if(flag){
                system("cls");
				printf("\n\n\n\n\n");
				printf("\t***************************************************************\n");
				printf("\t***************************************************************\n");
				printf("			   ���û������������,���������룡\n");
				Sleep(300);
				printf("\t���������޸ĵ��û���:");
				scanf("%s",choose1);
				printf("\t����������û���ԭʼ����:");
				scanf("%s",choose2);


				}
       }








	printf("\n			      �����޸ĳɹ���\n");
	printf("			  2S���Զ����й�����桭����\n");
	Sleep(2000);                                                                       //��ͣ2S
	guanli();

}

void all()
{

}

void paixu()
{

}
void chaxun()
{

}

void zengjia()
{

}

void tuichu()
{

}

void tongji()
{

}
