#include <iostream>
#include <string>

using namespace std;

int main() {
	int N;
	cin >> N;
	long long A[100000];
	long long cnt = 0;
	long long ans = 0;
	long long tmp;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		if (i == 0) tmp = abs(A[0]);
		else if (abs(A[i]) < tmp) tmp = abs(A[i]);
		if (A[i] < 0) cnt++;
		ans += abs(A[i]);
	}
	if (cnt % 2 == 1) ans = ans - 2 * tmp;
	cout << ans << endl;
	return 0;
}
