#include <stdio.h>
#include <string.h>
 
int main(int argc, char *argv[])
{
	int i, j, k, M, N;
	char mm[64][64], nn[64][64];
	scanf("%d %d\n", &N, &M);
	for ( i = 0; i < N; i++ ){
		fgets(nn[i], 64, stdin);
	}
	for ( i = 0; i < M; i++ ){
		fgets(mm[i], 64, stdin);
	}
						 
	for ( i = 0; i + M <= N; i++ ){
		for ( j = 0; j + M <= N; j++ ){
			for ( k = 0; k < M; k++ ){
				if ( memcmp(nn[k+i]+j, mm[k], M) != 0 ){
					break;
				}
			}
			if ( k == M ){
				printf("Yes\n");
				return 0;
			}
		}
	}
	printf("No\n");
	return 0;
}
