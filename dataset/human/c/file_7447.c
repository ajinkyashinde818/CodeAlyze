#include<stdio.h>
int main(void){
	int i;
	int Case[ 10000 ];
	for(i=0;i<10000;i++){
		scanf("%d",&Case[i]);
		if(Case[i]==0){
			break;
		}
	}
	for(i=0;i<10000;i++){
		if(Case[i]==0){
			break;
		}
		printf("Case %d: %d\n",i+1,Case[i]);
	}
	return 0;
}
