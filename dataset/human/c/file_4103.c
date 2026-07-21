#include<stdio.h>
int main()
{
	int a,b,k;
	int i,x[100]={0},y=0,c=0;
	scanf("%d %d %d",&a,&b,&k);
	if(a>b) y=a;
	else y=b;
	for(i=1;i<=y;i++){
		if(a%i==0&&b%i==0){
			x[c]=i;
			c++;
		}
	}
	printf("%d\n",x[c-k]);
	return 0;
}
