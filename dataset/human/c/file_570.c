#include <stdio.h>
int M, N;	char A[51][51], B[51][51];	bool same_flag;
 
int main(void){
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; ++i) { 
      scanf("%s", &A[i]);
    }
	for (int i = 0; i < M; ++i) { 
      scanf("%s", &B[i]);
    }
 
	for (int i = 0; i <= (N - M); ++i){
		for (int j = 0; j <= (N - M); ++j){
			same_flag = true;
			for (int x = 0; x < M; ++x){
				for (int y = 0; y < M; ++y){
					if (A[i + x][j + y] != B[x][y]){
						same_flag = false;	break;
					}
				}
				if (same_flag == false){
					break;
				}
			}
			if (same_flag == true){
				printf("Yes\n");	return 0;
			}
		}
	}
	printf("No\n");
}
