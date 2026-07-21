#include<stdio.h>

int main(){

	int N;  /* 人数 */
	int K;  /* 身長制限 */
	int ans=0;
	scanf("%d", &N);
	scanf("%d", &K);

	int h[N];  /* 身長配列 */
	for( int i=0; i<N; i++ ){
		scanf("%d", &h[i]);
	}

	for( int j=0; j<N; j++ ){
		if( h[j]>=K ){
			ans++;
		}
	}

	printf("%d\n", ans);

	return 0;
}
