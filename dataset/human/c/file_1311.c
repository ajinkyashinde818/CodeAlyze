#include<stdio.h>

int n,m,a[200001],b[200001],ta,tb;

int main(void){
	register int i;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++)
		scanf("%d%d",&ta,&tb),
		a[tb]|=(ta==1),
		b[ta]|=(tb==n);
	for(i=1;i<n;i++)
		if(a[i]&&b[i])
			return puts("POSSIBLE"),0;
	puts("IMPOSSIBLE");
	return 0;
}
