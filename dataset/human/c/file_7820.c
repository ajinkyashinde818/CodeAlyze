#include<stdio.h>
int main(){
int a,b,i,N,K[100],P[100];
	scanf("%d",&N);
	
	for(i=0;i<N;i++){
		scanf("%d %d",&K[i],&P[i]);
	}
	
	for(a=0;a<N;a++){
		b=K[a]%P[a];
		if(b==0){
			b=P[a];
		}
		printf("%d\n",b);
	}
	
return 0;
}
