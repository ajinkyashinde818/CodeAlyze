#include<stdio.h>
int a[100001],b[100001];
int main(void)
{
	int i,n,m;
	scanf("%d",&n);
	for(i=1;i<=n;i++) b[i]=0;
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	i=1;
	m=0;
	b[i]=1;
	while(1){
		if(i==2){
			printf("%d\n",m);
			break;
		}
		if(m==n){
			printf("-1\n");
			break;
		}
		if(b[i]==1){
			b[i]=0;
			b[a[i]]=1;
			i=a[i];
		}
		m++;
	}
	return 0;
}
