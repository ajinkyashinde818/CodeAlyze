// AtCoder ABC140: B - 
// 2019.9.7 bal4u

#include <stdio.h>

int N;
int A[25], B[25], C[25];

int main()
{
	int i, ans;
	
	scanf("%d", &N);
	for (i = 1; i <= N; i++) scanf("%d", A+i);
	for (i = 1; i <= N; i++) scanf("%d", B+i);
	for (i = 1; i < N; i++) scanf("%d", C+i);
	ans = 0; for (i = 1; i <= N; i++) {
		ans += B[A[i]];
		if (i < N && A[i]+1 == A[i+1]) ans += C[A[i]];
	}
	printf("%d\n", ans);
	return 0;
}
