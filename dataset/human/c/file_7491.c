#include<stdio.h>

int main(void){
	int i;
	int x[10000]={1};
	int y=0;

	for(i=0;i<10001;i++){
		
			scanf("%d",&x[i]);
		if(x[i]==0){
		i=10001;
		}
		y++;
		
		
}
	for(i=0;i<(y-1);i++){
		printf("Case %d: %d\n",(i+1),x[i]);
	}
	
return 0;
}
