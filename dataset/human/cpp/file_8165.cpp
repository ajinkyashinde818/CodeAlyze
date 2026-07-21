#include <vector>
#include <iostream> 
#include <limits>

using namespace std;

int main(int argc, char *argv[]) {
	int N;
	long long A = 0, B = 0;

	cin >> N;

	vector<int> a(N);
	for (int i = 0; i < N; i++) {
		cin >> a[i];
		B += a[i];
	}

	long long ans = numeric_limits<long long>::max();
	for (int i = 0; i < N - 1; i++) {
		A += a[i];
		B -= a[i];
		ans = min(ans, abs(B - A));
	}

	cout << ans << endl;

	return 0;
}
