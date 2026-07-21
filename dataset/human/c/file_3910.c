#include<stdio.h>
int main(void)
{
	int a,b,k,y,cnt=0,i,x[100],p;
	scanf("%d %d %d",&a,&b,&k);
	p=0;
	for(i=100;i>=1;i--){
		if(a%i==0&&b%i==0){
			x[p]=i;
			p++;
		}
	}
	k=k-1;
	printf("%d\n",x[k]);
	return 0;
}
