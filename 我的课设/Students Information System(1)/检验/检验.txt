#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<conio.h>
#define N 50

struct match
{
	char name[20];
	char miyao[20];

}mat[N];


int main()
{   char yh[20];
    char pw[20];
    int i;
    printf("			   现在进行身份验证工作\n");
   printf("			       请您输入教师姓名\n");
    scanf("%s",yh);
    printf("			       请您输入您的密钥，\n");
    scanf("%s",pw);
    FILE*z;
    z=fopen("match.txt","rb");
    for(i=0;i<50;i++)
       {
          fread(&mat[i],sizeof(struct match),1,z) ;


       }
       fclose(z);
       int flag=1;
        while(flag)
       {
           for(i=0;i<50;i++)
           {if((strcmp(yh,mat[i].name)==0) && (strcmp(pw,mat[i].miyao)==0))
           {
               printf("			   身份验证成功了，亲\n");
               flag=0;
           }
           }

           if(flag)
           {
               system("cls");
				printf("\n\n\n\n\n");
				printf("\t***************************************************************\n");
				printf("\t***************************************************************\n");
				printf("			   教师姓名或密钥错误,请重新输入！\n");
				Sleep(300);
				printf("			       请您输入教师姓名\n");
                scanf("%s",yh);
                printf("			       请您输入您的密钥，\n");
                scanf("%s",pw);
           }



        }
        return 0;
}
