#include<stdio.h>
int main(void){
	int tate[2],yoko[2],menseki[2],i,dai;
	scanf("%d %d %d %d",&tate[0],&yoko[0],&tate[1],&yoko[1]);
	
	for(i=0;i<2;i++){
		menseki[i]=tate[i]*yoko[i];
	}
	dai=menseki[0];
	if(menseki[1]>dai){
		dai=menseki[1];
	}
	printf("%d\n",dai);
	
	return 0;
}
