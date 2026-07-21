/*隣接しているところに絶対行く。
間の距離を計算。
*/

#include<stdio.h>

int main(){
	int K, N, i, dist;
	scanf("%d %d", &K, &N);
	int A[N], d[N];
	for(i = 0; i < N; i++){
		scanf("%d", &(A[i]));
	};
	for(i = 0; i < N - 1; i++){
		d[i] = A[i+1] - A[i];
	}
	d[N-1] = (K - A[N-1]) + A[0];
	/*d[i] は i と i+1の間の距離*/
	dist = K;
	for(i = 0; i < N; i++){
		if(K - d[i] < dist){
			dist = K - d[i];
		}
	}
	printf("%d\n", dist);
	/*printf("%d %d\n", K, N);
	for(i = 0; i < N; i++){	
		printf("%d ", A[i]);
	}*/
	return 0;
}
