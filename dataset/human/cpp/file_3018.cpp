#include <iostream>
using namespace std;

int A[100001];

int main(void) {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	long long Bm = -A[1], Bp = A[1];

	for (int i = 2; i < N; i++) {
		long long TmpBm = Bm, TmpBp = Bp;
		// 反転する
		Bm = max(TmpBm+A[i], TmpBp-A[i]);
		// 反転しない
		Bp = max(TmpBm-A[i], TmpBp+A[i]);
	}
	// 最後のAnを足す
	Bm += -A[N];
	Bp += +A[N];
	cout << max(Bm, Bp) << endl;
	return 0;
}
