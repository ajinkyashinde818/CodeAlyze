#include<stdio.h>
#include<stdlib.h>

int main(){
	int x[10000];
	int i=0;
	int num=0;
	x[0]=1;
	
	while(1){
		scanf("%d",&x[i]);
		if(x[i]==0){
			break;
		}
		i++;
	}
	
	for(num=0;num<i;num++){
		printf("Case %d: %d\n",num + 1,x[num]);
	}
	return 0;
}
