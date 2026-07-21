#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	long long Ans = 0, MIN = 1000000001;
	int Minus = 0;
	for (int i = 0; i < N; i++) {
		long long A;
		cin >> A;
		Minus += (A < 0);
		long long Abs = A > 0 ? A : -A;
		Ans += Abs;
		MIN = min(MIN, Abs);
	}
	if (Minus % 2 == 0) cout << Ans << endl;
	else cout << Ans - 2 * MIN << endl;
}
