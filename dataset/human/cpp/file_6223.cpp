#include<cstdio>
#include<algorithm>
using namespace std;
int n;
long long A[101000], AA[101000], B[101000], BB[101000], L, X[101000], w[101000], M, MM, res;
int main() {
	int i;
	scanf("%d%lld", &n, &L);
	for (i = 1; i <= n; i++) {
		scanf("%lld%lld", &X[i],&w[i]);
		A[i] = A[i - 1] - (X[i] - X[i - 1]) + w[i];
		AA[i] = AA[i - 1] - (X[i] - X[i - 1]) * 2 + w[i];
	}
	X[n + 1] = L;
	for (i = n; i >= 1; i--) {
		B[i] = B[i + 1] - (X[i + 1] - X[i]) + w[i];
		BB[i] = BB[i + 1] - (X[i + 1] - X[i])*2 + w[i];
	}
	for (i = n; i >= 0; i--) {
		res = max(res, M + AA[i]);
		res = max(res, MM + A[i]);
		if (!i)break;
		M = max(M, B[i]);
		MM = max(MM, BB[i]);
	}
	printf("%lld\n", res);
}
