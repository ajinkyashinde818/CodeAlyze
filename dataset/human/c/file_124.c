#include<stdio.h>
int main(void){
	int R,G,B,N;
	int r,g,b;
	int i,j,k;
	int Ans =0;
	scanf("%d %d %d %d",&R,&G,&B,&N);
	
	for(i=0;i<=3000;i++){
		for(j=0;j<=3000;j++){
			if(N>=R*i+G*j && (N-R*i-G*j)%B==0){
				Ans++;
			}
		}
	}
	printf("%d",Ans);
    return 0;
}
