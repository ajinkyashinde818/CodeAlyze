#include<stdio.h>

int main (){
	int N,K,i,j,can;
	scanf("%d %d",&N,&K);
	int height[N];
	can = 0;
	for (i=0;i<N;i++){
		scanf("%d",&height[i]);
	}
	for (j=0;j<N;j++){
		if (height[j]>=K){
			can++;
		}
	}
	printf("%d\n",can);
	return 0;	
}
