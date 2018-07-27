#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<conio.h>
#include "weixi.h"



/**********************************登录界面**************************************/
    void denglu()
{
    int temp=1;
    while(temp)                                                                          //进入选择功能的函数，从而进行下一个界面
	{
	    system("cls");
        printf("\n\n                **********欢迎进入学生信息管理系统**********\n\n\n");
        printf("                     1.管理员登录\n");
        printf("                     2.用户注册\n");
        printf("                     3.修改密码\n");
        printf("                    请选择：");
		int choose;
 	    scanf("%d",&choose);
        switch(choose)
		{
		case  1:temp=guanli();break;                                                   //选择以管理员身份进入系统
		case  2:zhuce();break;
         case 3:change();break;                                               //选择修改的身份进入系统
		default:printf("\n\t 输入有误，请重新输入：");break;	                     //输入其他数字，则进行报错，同时while函数中不断循环
		}
	}
}

/**********************************管理员登录界面**************************************/
int guanli()
{ system("cls");
    FILE *x;
    int i,flag;
	char yh[20];
    char m[20];
	printf("\n\n\n\n\n");
	printf("\t***************************************************************\n");
	printf("			      欢迎来到管理员登陆界面   \n");
	printf("\t***************************************************************\n");
	printf("			       请您输入用户名和密码\n");
    printf("\t用户名：");
    scanf("%s",yh);
    printf("\t密码：");
    scanf("%s",m);
	x=fopen("manager.txt","rb");
	for(i=0;i<50;i++)
    {fread(&mag[i],sizeof(struct manager),1,x);
    }
    fclose(x);
    flag=1;
	while(1)
    {
        for(i=0;i<50;i++)
        {
            if((strcmp(yh,mag[i].name)==0) && (strcmp(m,mag[i].mima)==0))
            {
                printf("\n			     登录成功！\n");
                flag=0;
                Sleep(1000);
                system("cls");
                return 0;
            }
        }
        if(flag)
        {printf("\t\t\t账户或密码错误;\n"); //输入错误，要求重新输入或选择
        printf("\t\t请重新输入：\n");
        printf("\t\t用户名：");
       scanf("%s",yh);
       printf("\t密码：");
        scanf("%s",m);
        }
    }
	return 1;
}


/**********************************管理员注册界面**************************************/

void zhuce()                                                                           //注册界面函数
{
    system("cls");                                                                     //清屏
    FILE*x;
    FILE*y;
    int i;
    char choose1[20];
    char choose2[20];
    y=fopen("number.txt","r");
    fscanf(y,"%d",&RENSHU);
    fclose(y);
    char wh[20];
    char pw[20];
    printf("\n\n\n\n\n");
    printf("			   现在进行身份验证工作\n");
    printf("			   请您输入教师姓名\n");
    scanf("%s",wh);
    printf("			   请您输入您的密钥，\n");
    scanf("%s",pw);
    FILE*z;
    z=fopen("match.txt","rb");
    for(i=0;i<N;i++)
       {
          fread(&mat[i],sizeof(struct match),1,z) ;
       }
       fclose(z);
    int flag1=1;
    while(flag1)
       {
           for(i=0;i<50;i++)
           {if((strcmp(wh,mat[i].name)==0) && (strcmp(pw,mat[i].miyao)==0))
           {
               printf("			   身份验证成功了，亲\n");
               flag1=0;
           }
           }

           if(flag1)
           {
               system("cls");
				printf("\n\n\n\n\n");
				printf("\t***************************************************************\n");
				printf("\t***************************************************************\n");
				printf("			   教师姓名或密钥错误,请重新输入！\n");
				Sleep(300);
				printf("			       请您输入教师姓名\n");
                scanf("%s",wh);
                printf("			       请您输入您的密钥，\n");
                scanf("%s",pw);
           }



        }

    system("cls");
	printf("\n\n\n\n\n");
	printf("\t***************************************************************\n");
	printf("\t              欢迎来到管理员的注册页面\n");
	printf("\t***************************************************************\n");
	printf("\t请您输入新建立的用户名:");
   x=fopen("manager.txt","rb");
    for(i=0;i<RENSHU;i++)
    {fread(&mag[i],sizeof(struct manager),1,x);
    }
    fclose(x);
    int flag=1;
    while (flag)                                                                  //标志位，用于判断输入的用户名是否已经被注册过
	{
	    scanf("%s",choose1);


      for(i=0;i<RENSHU;i++)
			 {

			    if(strcmp(mag[i].name,choose1)==0)                                  //筛选是否存在此账号，比较两个字符串
			{
				printf("\n\n\n\n\n");
				printf("\t***************************************************************\n");
				printf("		                    注册页面 \n");
				printf("\t***************************************************************\n");
				printf("			   该用户名已存在,请重新输入！\n");
				Sleep(300);                                                            //延时300mS
				printf("请您输入新的用户名:");
				flag=1;                                        //用户名存在时，要求重新输入输入用户名


			}
			else flag=0;
			 }
     }






	strcpy(mag[RENSHU].name,choose1);                                                //记录用户名，把choose1复制到name中	                                                                                   //密码记录数组，最多只能6位密码
	printf("\t密码(长度最多为10位):");
	scanf("%s",choose2);
	strcpy(mag[RENSHU].mima,choose2);
    x=fopen("manager.txt","ab");
    fwrite(&mag[RENSHU],sizeof(struct manager),1,x);
	fclose(x);
	RENSHU++;
	y=fopen("number.txt","wb");
	fprintf(y,"%d",RENSHU);
	fclose(y);
	printf("\n			      身份注册成功！\n");
	printf("			  2S后自动进行登录界面………\n");

	Sleep(2000);
	 system("cls");                                                                         //暂停2S
}


/**********************************修改密码界面**************************************/
void change()
{
     system("cls");                                                                     //清屏
     FILE*x;
     FILE*y;
     int i;
     y=fopen("number.txt","r");
    fscanf(y,"%d",&RENSHU);
    fclose(y);
	printf("\n\n\n\n\n");
	printf("\t***************************************************************\n");
	printf("\t              欢迎来到修改密码页面\n");
	printf("\t***************************************************************\n");
	printf("\t请您输入修改的用户名:");
   char choose1[20];
   char choose2[20];
   fflush(stdin);                                                                //标志位，用于判断输入的用户名是否已经被注册过
	scanf("%s",choose1);
	printf("\t请您输入该用户的原始密码:");
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
               if((strcmp(choose1,mag[i].name)==0) && (strcmp(choose2,mag[i].mima)==0))                               //筛选是否存在此账号，比较两个字符串
			    {
			    printf("\t请您输入该用户的新密码:");
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
                printf("\n			      密码修改成功！\n");
	            printf("			  2S后自动进行管理界面………\n");
	            Sleep(2000);
	            flag=0;
	            return;                                                                    //暂停2S
	            //denglu();
                }

            }
                if(flag){
                system("cls");
				printf("\n\n\n\n\n");
				printf("\t***************************************************************\n");
				printf("\t***************************************************************\n");
				printf("			   该用户名或密码错误,请重新输入！\n");
				Sleep(300);
				printf("\t请您输入修改的用户名:");
				scanf("%s",choose1);
				printf("\t请您输入该用户的原始密码:");
				scanf("%s",choose2);
				}
       }
}



