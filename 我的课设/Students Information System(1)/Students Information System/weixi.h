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

void  denglu();  //  µÇÂ¼
int guanli();  //   ¹ÜÀí
void zhuce();  //   ×¢²á
void change();  //  ĞŞ¸ÄÃÜÂë

#endif // WEIXI_H_INCLUDED
