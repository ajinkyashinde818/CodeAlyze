#include<stdio.h>
int main(void){
	int N,M,ze[100],i,j,x;
	scanf("%d %d",&N,&M);
	for(i=0;i<N;i++){
		scanf("%d",&ze[i]);
	}
	for(j=1;j<=M;j++){
		for(i=0;i<N-1;i++){
			if(ze[i]%j>ze[i+1]%j){
				x=ze[i];
				ze[i]=ze[i+1];
				ze[i+1]=x;
			}
		}
	}
	for(i=0;i<N;i++){
		printf("%d\n",ze[i]);
	}
	return 0;
}
