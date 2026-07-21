#include <stdio.h>

int main(void)
{
	int N, A[20], B[20], C[20];
	int i;
	int s=0, b=-1;	// 満足度の合計、現在の料理Aの値
	
	// 入力
	scanf("%d", &N);
	for(i=0; i<N; i++)	scanf("%d", &A[i]);
	for(i=0; i<N; i++)	scanf("%d", &B[i]);
	for(i=0; i<N-1; i++)scanf("%d", &C[i]);
	
	for(i=0; i<N; i++){
		//printf("%d %d %d\n", A[i], B[A[i]-1], b);
		s += B[A[i]-1];	// 満足度Bを追加
		if(i>0 && b==A[i]-1)	s += C[b-1];	// 順番通りなら満足度Cを追加
		b = A[i];	// 現在の料理Aの値を格納
		//printf("%d\n", s);
	}
	
	printf("%d\n", s);
	
	return 0;
}
