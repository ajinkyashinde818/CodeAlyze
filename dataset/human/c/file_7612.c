#include<stdio.h>
int main(void){
	int x[10000];
	int t,m=0;
	for(t=0;t<10000;t++){
		scanf("%d",&x[t]);
		if(x[t]==0){
			break;
		}
		m++;
	}
	for(t=0;t<m;t++){
		printf("Case %d: %d\n",t+1,x[t]);
	}
	return 0;
}
