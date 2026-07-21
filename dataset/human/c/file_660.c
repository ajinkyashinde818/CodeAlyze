#include <stdio.h>

int main(void){
	int N,M;
	scanf("%d %d",&N,&M);

	int f;

	char A[N][N+1];
	char B[M][M+1];
	for(int i=0; i<N; i++){
		scanf("%s",A[i]);
	}
	for(int i=0; i<M; i++){
		scanf("%s",B[i]);
	}


	for(int i=0; i<=N-M; i++){
		for(int l=0; l<=N-M; l++){
			f=0;
			for(int j=0; j<M; j++){
				for(int k=0; k<M; k++){
					if(A[j+i][k+l]!=B[j][k]){ f=1; break; }
				}
			}
			if(f==0){ printf("Yes\n");return 0; }
		}
	}
	
	printf("No\n");
	return 0;
}
