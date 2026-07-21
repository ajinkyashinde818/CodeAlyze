#include<stdio.h>
int main(void)
{
	int n,m,x;
	scanf("%d %d",&n,&m);
	if(n==0){
		if(m>=1868&&m<=1911) printf("M%d\n",44-(1911-m));
		if(m>=1912&&m<=1925) printf("T%d\n",14-(1925-m));
		if(m>=1926&&m<=1988) printf("S%d\n",63-(1988-m));
		if(m>=1989&&m<=2016) printf("H%d\n",28-(2016-m));
	}
	if(n==1) printf("%d\n",1911-(44-m));
	if(n==2) printf("%d\n",1925-(14-m));
	if(n==3) printf("%d\n",1988-(63-m));
	if(n==4) printf("%d\n",2016-(28-m));
	return 0;
}
