#include<stdio.h>

int main(){
	int N, M;
	int i, j, k, l, sc;
	_Bool t = 0;
	sc = scanf("%d %d", &N, &M);
	
	char A[N][N + 1], B[M][M + 1];
	
	for(i = 0; i < N; i ++){
		sc = scanf("%s", &A[i][0]);
	}
	for(i = 0; i < M; i ++){
		sc = scanf("%s", &B[i][0]);
	}
	
	for(k = 0; k < N - M + 1; k ++){
		for(l = 0; l < N - M + 1; l ++){
			t = 0;
			for(i = 0; i < M; i ++){
				for(j = 0; j < M; j ++){
					if(B[i][j] != A[k + i][l + j]){
						t = 1;
						break;
					}
				}
				if(t == 1) break;
			}
			if(i == M && j == M){
				printf("Yes\n");
				return 0;
			}
		}
	}
	printf("No\n");	
	return 0;
}
