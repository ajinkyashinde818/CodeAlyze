#include<stdio.h>

int main(){
	int cnt;
	int i;
	int x[10000];
	while(1){
		scanf("%d",&x[cnt]);
		if(x[cnt]==0)break;
		cnt++;
	}
	
	for(i=0;i<cnt;i++){
		printf("Case %d: %d\n",i+1,x[i]);
	}
	return 0;
}
