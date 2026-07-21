#include<stdio.h>

int main(){
	int N,M,i;
	scanf("%d%d",&N,&M);
	char A[N][N+1];
	char B[M][M+1];
	for(i=0;i<N;i++)scanf("%s",A[i]);
	for(i=0;i<M;i++)scanf("%s",B[i]);
	
	for(i=0;i<=N-M;i++){
		for(int j=0;j<=N-M;j++){
			int flag=1;
			for(int k=0;k<M;k++){
				for(int l=0;l<M;l++){
					if(A[k+i][l+j]!=B[k][l])flag=0;
				}
			}
			if(flag==1){
				printf("Yes\n");
				return 0;
			}
		}
	}
	printf("No\n");
	return 0;
}
