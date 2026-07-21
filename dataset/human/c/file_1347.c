#include <stdio.h>

int main(int argc, char *argv[])
{
	int i, N, M, a, b;
	static int s1[200000], sn[200000];
	scanf("%d %d", &N, &M);

	for ( i = 0; i < M; i++ ){
		scanf("%d %d", &a, &b);
		if ( a == 1 ){
			s1[b-1] = 1;
		} else if ( b == 1 ){
			s1[a-1] = 1;
		} else if ( a == N ){
			sn[b-1] = 1;
		} else if ( b == N ){
			sn[a-1] = 1;
		}
	}

	for ( i = 0; i < N; i++ ){
		if ( s1[i] == 1 && sn[i] == 1 ){
			printf("POSSIBLE\n");
			return 0;
		}
	}
	printf("IMPOSSIBLE\n");
	return 0;
}
