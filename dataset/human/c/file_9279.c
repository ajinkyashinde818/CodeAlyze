#include<stdio.h>
int main(){
	int cnt=0,i,N,K,h[100000]={};
	scanf("%d%d",&N,&K);
	for(i=0;i<N;++i){
		scanf("%d",&h[i]);
		if(h[i]>=K){
			++cnt;
		}
	}
	printf("%d\n",cnt);
}
//???
