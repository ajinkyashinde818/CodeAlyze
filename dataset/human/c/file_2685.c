#include<stdio.h>
int main(void)
{
	int k,s,x,y,z,a;
	
	scanf("%d",&k);
	scanf("%d",&s);
	a=0;
	for(x=0;x<=k;++x) {
		for(y=0;y<=k;++y) {
			z=s-x-y;
			if(0<=z&&z<=k) {
				a=a+1;
			}
		}
	}
	printf("%d\n",a);
	
	return 0;
}
