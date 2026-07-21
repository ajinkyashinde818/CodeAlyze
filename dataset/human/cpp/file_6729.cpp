#include<cstdio>
#include<functional>
#include<algorithm>
#include<cstring>
using namespace std;
int main(void)
{
	char buf[10];
	int sei,bunbo,zyun,i,j,flg,len,x,y,yaku,ama,zbo;
	scanf("%s",buf);
	len=strlen(buf);
	flg=0;
	sei=0;
	bunbo=1;
	zyun=0;
	zbo=0;
	for(i=0;i<len;i++)	{
		if(flg==0)	{
			if(buf[i]!='.')	{
				sei=sei*10;
				sei+=buf[i]-'0';
			}
			else {
				flg=1;
			}
		}
		else if(flg==1)	{
			if(buf[i]!='(')	{
				sei=sei*10;
				sei+=buf[i]-'0';
				bunbo=bunbo*10;
			}
			else {
				flg=2;
				zyun=sei;
			}
		}
		else {
			if(buf[i]!=')')	{
				sei=sei*10;
				sei+=buf[i]-'0';
				zbo=zbo*10;
				zbo+=9;
			}
			else {
				sei=sei-zyun;
				bunbo=bunbo*zbo;
			}
		}
	}
	x=sei;	y=bunbo;
	if(x<y)	swap(x,y);
	while(1)	{
		ama=x%y;
		if(ama==0)	{
			yaku=y;
			break;
		}
		else {
			x=y;
			y=ama;
		}
	}
	sei=sei/yaku;	bunbo=bunbo/yaku;
	printf("%d/%d\n",sei,bunbo);
	return 0;
}
