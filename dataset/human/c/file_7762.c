#include<stdio.h>
int main(){
	int Nx,K[1000]={0},P[1000]={0},i,j;
	scanf("%d",&Nx);
	for(i=0;i<Nx;i++){
		scanf("%d %d",&K[i],&P[i]);
	}
	for(j=0;j<Nx;j++){
		if(K[j]%P[j]!=0){
			printf("%d\n",K[j]%P[j]);
		}else{
			printf("%d\n",P[j]);
		}
	}
	return 0;
}
