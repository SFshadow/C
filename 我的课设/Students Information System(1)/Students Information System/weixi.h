#ifndef WEIXI_H_INCLUDED
#define WEIXI_H_INCLUDED
#define N 50

int RENSHU;

struct manager
{
	char name[20];
	char mima[20];
}mag[N];

struct match
{
	char name[20];
	char miyao[20];

}mat[N];

void  denglu();  //  ��¼
int guanli();  //   ����
void zhuce();  //   ע��
void change();  //  �޸�����

#endif // WEIXI_H_INCLUDED
