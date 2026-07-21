#include<stdio.h>
int main(void){
	int x[10000],a,i;
	i=1;
	while(1)
		{
		scanf("%d",&x[i]);
		if(x[i]==0){
			break;
		}
		a=i;
		i++;
	}
	i=0;
	i=1;
	while(i<=a){
	printf("Case %d: %d\n",i,x[i]);
	i++;
	}
	return 0;
}
