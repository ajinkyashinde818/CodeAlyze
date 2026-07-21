#include <stdio.h>

int main(void)
{
	int a,b,c,d[110],i,j,x=0;
	scanf("%d %d %d",&a,&b,&c);
	for(i=0;i<a;i++){
		scanf("%d",&d[i]);
	}
	for(i=0;i<a;i++){
		for(j=0;j<b;j=j){
			x++;
			j=j+d[i];
		}
	}
	printf("%d",x+c);
}
